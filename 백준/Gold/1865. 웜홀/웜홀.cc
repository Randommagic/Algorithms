#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 99000000
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<vector<int>> arr(n + 1, vector<int>(n + 1, MAX));

        for (int i = 0; i < m; i++) {
            int st, dst, c;
            cin >> st >> dst >> c;
            arr[st][dst] = std::min(arr[st][dst], c);
            // 도로는 방향이 없다를 놓쳐서 추가.
            arr[dst][st] = std::min(arr[dst][st], c);
        }

        for (int i = 0; i < w; i++) {
            int st, dst, c;
            cin >> st >> dst >> c;
            arr[st][dst] = std::min(arr[st][dst], c * -1);
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (arr[i][i] < 0) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }
}