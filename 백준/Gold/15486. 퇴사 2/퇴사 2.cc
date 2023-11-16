#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> daysReq(N + 2), priceRev(N + 2);
    vector<int> dp(N + 2);

    for (int i = 1; i <= N; i++)
        cin >> daysReq[i] >> priceRev[i];

    for (int i = 1; i <= N + 1; i++) {
        dp[i] = std::max(dp[i - 1], dp[i]);
        if (i + daysReq[i] <= N + 1)
            dp[i + daysReq[i]] = std::max(dp[i + daysReq[i]], priceRev[i] + dp[i]);
    }

    cout << dp[N + 1];
}
