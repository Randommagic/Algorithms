#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, mapSize;
    cin >> N;
    mapSize = N * 4 - 3;
    vector<vector<char>> map(mapSize, vector<char>(mapSize, ' '));

    int x, y;
    for (int i = 0; i < N; i++) {
        x = i * 2;
        y = i * 2;

        int dir = 0;
        for (int k = 0; k < 4; k++) {
            int targetCnt = (N - i - 1) * 4;
            int cnt = 0;

            while (true) {
                map[y][x] = '*';
                cnt++;
                if (cnt > targetCnt)
                    break;
                x += dx[dir];
                y += dy[dir];
            }
            dir++;
        }
    }

    // 출력
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++)
            cout << map[i][j];
        cout << "\n";
    }
}