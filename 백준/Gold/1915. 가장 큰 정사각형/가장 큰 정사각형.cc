#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &map[i][j]);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans;
}
