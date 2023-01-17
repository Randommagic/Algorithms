// https://www.acmicpc.net/problem/14442
/*
틀렸던 반례 :
1 1 1
0
정답 : 1
내 정답 : -1
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class node {
  public:
    int x, y, dist, cnt;
    node(int _x, int _y, int _dist, int _cnt)
        : x(_x), y(_y), dist(_dist), cnt(_cnt){};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<vector<bool>>> visited(
        N, vector<vector<bool>>(M, vector<bool>(K + 1)));

    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }
    // map init
    for (int i = 0; i < N; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < M; j++)
            if (str[j] == '1')
                map[i][j] = 1;
    }

    queue<node> q;
    visited[0][0][0] = true; // 처음 좌표는 이미 visited;
    q.push(node(0, 0, 1, 0)); // x좌표, y좌표, 현재까지 거리, 벽깬 횟수.
    // fill map with numbers
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        int cnt = q.front().cnt;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;

            if (nx == M - 1 && ny == N - 1) { // 맨 마지막에 다다렀을때.
                cout << dist + 1 << endl;
                return 0;
            }

            if (map[ny][nx] == 1) { // 다음 칸이 벽일시
                if (cnt == K) // 이미 벽깨는 횟수를 모두 소모함.
                    continue;
                if (visited[ny][nx][cnt + 1]) // 이미 벽을 깨고 간 곳일시
                    continue;
                visited[ny][nx][cnt + 1] = true;
                q.push(node(nx, ny, dist + 1, cnt + 1));
            } else {
                if (visited[ny][nx][cnt])
                    continue;
                visited[ny][nx][cnt] = true;
                q.push(node(nx, ny, dist + 1, cnt));
            }
        }
    }
    cout << -1;
}
