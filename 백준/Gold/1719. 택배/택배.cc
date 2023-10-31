#include <iostream>
#include <vector>
#define MAX 9999999
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, MAX));
    vector<vector<int>> ans(N + 1, vector<int>(N + 1));

    for (int i = 0; i <= N; i++) {
        dist[i][i] = 0;
        ans[i][i] = i;
    }

    while (M-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}