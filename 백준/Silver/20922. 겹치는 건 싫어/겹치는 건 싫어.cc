#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> cnt(100001);
    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];

    int answer = 1;
    int left = 0;

    cnt[input[left]]++;

    for (int right = 1; right < N; right++) {
        cnt[input[right]]++;
        while (cnt[input[right]] > K) {
            cnt[input[left]]--;
            left++;
        }
        answer = max(answer, right - left + 1);
    }
    cout << answer;
}