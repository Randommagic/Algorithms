#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, Q, M;
    cin >> N >> K >> Q >> M;

    vector<bool> attendence(N + 3, false), sleeping(N + 3, false);
    while (K-- > 0) {
        int i;
        cin >> i;
        sleeping[i] = true;
    }

    while (Q-- > 0) {
        int i, k = 1;
        cin >> i;
        if (sleeping[i])
            continue;
        while (i * k <= N + 2) {
            if (!sleeping[i * k])
                attendence[i * k] = true;
            k++;
        }
    }

    vector<int> answer(N + 3, 0);
    for (int i = 3; i <= N + 2; i++) {
        answer[i] = answer[i - 1];
        if (!attendence[i])
            answer[i]++;
    }

    while (M-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << answer[b] - answer[a - 1] << "\n";
    }
}