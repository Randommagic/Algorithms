#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        int N, M;
        cin >> N;
        vector<int> coins(N);
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        cin >> M;

        vector<int> dp(M + 1);
        // dp[100] = 100원을 만들려 할때 가능한 조합 개수
        // dp[0] = 1. 이게 없으면 모든 dp배열이 다 0으로 초기화.
        dp[0] = 1;
        for (int i = 0; i < N; i++)
            for (int j = coins[i]; j <= M; j++)
                dp[j] += dp[j - coins[i]];
        cout << dp[M] << endl;
    }
}