#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];

    for (int i = 0; i <= N; i++)
        for (int j = 1; j <= M; j++)
            map[i][j] += map[i][j - 1];

    for (int j = 0; j <= M; j++)
        for (int i = 1; i <= N; i++)
            map[i][j] += map[i - 1][j];

    cin >> K;
    while (K-- > 0) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int sum = 0;
        sum += map[y2][x2];
        sum -= map[y2][x1 - 1];
        sum -= map[y1 - 1][x2];
        sum += map[y1 - 1][x1 - 1];
        cout << sum << "\n";
    }
}