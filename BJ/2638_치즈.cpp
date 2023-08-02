#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    pair<int, int> startpoint[4] = {{0, 0}, {0, N - 1}, {M - 1, 0}, {M - 1, N - 1}};

    int cheeseLeft = 0;
    int daysPassed = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                cheeseLeft++;
        }
    }

    // visited배열 - 방문한 외부 공간은 -1로, 한번 방문한 치즈는 1, 두번  방문한 치즈는 2
    // 2가 된 치즈는 visited를 -1로 바꾸고 map에서도 0으로 바꾼다.
    while (cheeseLeft) {
        daysPassed++;
        vector<vector<int>> visited(N, vector<int>(M));
        queue<pair<int, int>> q;
        // 각 모서리 부분은 언제나 비어있으니, 스타팅 포인트로 설정
        for (int i = 0; i < 4; i++) {
            int startX = startpoint[i].first;
            int startY = startpoint[i].second;
            visited[startY][startX] = -1;
            q.push({startX, startY});
        }
        while (!q.empty()) {
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                    continue;
                if (visited[ny][nx] == -1)
                    continue;
                if (map[ny][nx] == 1) { // 치즈를 방문
                    visited[ny][nx]++;
                    if (visited[ny][nx] == 2) { // 두 면  이상 변한 치즈
                        cheeseLeft--;
                        map[ny][nx] = 0;
                        visited[ny][nx] = -1;
                    }
                } else if (map[ny][nx] == 0) { // 빈 공간 방문
                    visited[ny][nx] = -1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << daysPassed;
}
