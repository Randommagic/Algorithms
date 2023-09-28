#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W;
    cin >> H >> W;
    vector<int> map(W);
    for (int i = 0; i < W; i++)
        cin >> map[i];

    int answer = 0;

    for (int i = 0; i < W; i++) {
        int leftMax = 0, rightMax = 0;

        for (int left = i; left >= 0; left--)
            leftMax = std::max(leftMax, map[left]);

        for (int right = i; right < W; right++)
            rightMax = std::max(rightMax, map[right]);

        answer += std::min(leftMax, rightMax) - map[i];
    }
    cout << answer;
}
