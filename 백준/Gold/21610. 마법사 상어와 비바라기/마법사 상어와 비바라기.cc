#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N;
vector<vector<int>> water;
vector<vector<bool>> cloud;

void moveCloud(int dir, int s) {
    vector<vector<bool>> newCloud(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!cloud[i][j])
                continue;
            int nx = (j + dx[dir] * s) % N;
            if (nx < 0)
                nx += N;
            int ny = (i + dy[dir] * s) % N;
            if (ny < 0)
                ny += N;
            newCloud[ny][nx] = true;
        }
    }
    cloud = newCloud;
}

void addRain() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cloud[i][j])
                water[i][j]++;
}

void copyWater() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 2에서 물이 증가한 칸(구름이 있었던 칸) 이 아닐 경우 pass
            if (cloud[i][j] == 0)
                continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k * 2 + 1];
                int ny = i + dy[k * 2 + 1];
                //  "이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다."
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                // 물이 있는 바구니만 check
                if (water[ny][nx] == 0)
                    continue;
                cnt++;
            }
            water[i][j] += cnt;
        }
    }
}

void createCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // "구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다."
            // 3단계도 같이 처리
            if (cloud[i][j]) {
                cloud[i][j] = false;
                continue;
            }

            if (water[i][j] >= 2) {
                cloud[i][j] = true;
                water[i][j] -= 2;
            }
        }
    }
}

int main() {
    int M;
    cin >> N >> M;
    water.resize(N, vector<int>(N));
    cloud.resize(N, vector<bool>(N));

    // 맨 처음 바구니 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> water[i][j];

    // 맨 처음 구름 설정
    cloud[N - 1][0] = true;
    cloud[N - 1][1] = true;
    cloud[N - 2][0] = true;
    cloud[N - 2][1] = true;

    // 이동 시작
    while (M-- > 0) {
        int dir, s;
        cin >> dir >> s;
        // 1단계
        moveCloud(dir - 1, s);

        // 2단계
        addRain();

        // 3단계는 5단계를 위해서 아직 처리하지 않음
        // 4단계
        copyWater();

        // 5단계
        createCloud();
    }

    // 다 끝나고 전체 바구니 물의 양
    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            answer += water[i][j];
    cout << answer;
}