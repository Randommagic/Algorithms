#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> coins(N);
    vector<int> dp(K + 1, 9999999);
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    dp[0] = 0;

    for (auto coin : coins) {
        for (int i = coin; i <= K; i++)
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
    }
    cout << (dp[K] == 9999999 ? -1 : dp[K]);
}
