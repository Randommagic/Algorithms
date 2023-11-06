#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));
    vector<vector<bool>> selected(N, vector<bool>(N, true));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1;
                    return 0;
                }
                if (i == k || k == j)
                    continue;

                if (dist[i][j] == dist[i][k] + dist[k][j])
                    selected[i][j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (selected[i][j])
                ans += dist[i][j];
    cout << ans / 2;
}