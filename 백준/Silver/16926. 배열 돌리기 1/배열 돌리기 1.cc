#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &arr, int loop) {
    int N = arr.size();
    int M = arr[0].size();

    int line = std::min(N, M) / 2;

    for (int lp = 0; lp < loop; lp++) {
        for (int l = 0; l < line; l++) {
            int temp = arr[l][l]; // 각 라인의 첫째 값.

            // 맨 윗줄 <-방향
            for (int i = l; i < M - l - 1; i++)
                arr[l][i] = arr[l][i + 1];

            // 오른쪽줄 ^방향
            for (int i = l; i < N - l - 1; i++)
                arr[i][M - l - 1] = arr[i + 1][M - l - 1];

            // 맨 아랫줄 -> 방향
            for (int i = M - 1 - l; i > l; i--)
                arr[N - l - 1][i] = arr[N - l - 1][i - 1];

            // 왼쪽줄 v방향
            for (int i = N - 1 - l; i > l; i--)
                arr[i][l] = arr[i - 1][l];

            // 맨 마지막꺼
            arr[l + 1][l] = temp;
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    rotate(v, R);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
