#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> ice;
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotateIce(int x, int y, int n) {
    if (n == 1)
        return;
    vector<vector<int>> original(n, vector<int>(n));
    vector<vector<int>> copy(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            original[i][j] = ice[i + y][j + x];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            copy[i][j] = original[n - j - 1][i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ice[y + i][x + j] = copy[i][j];
}

void sliceIce(int x, int y, int currentSize, int targetSize) {

    // 다 쪼개졌을 시 회전
    if (currentSize == targetSize) {
        rotateIce(x, y, currentSize);
        return;
    }

    // 더 쪼개야함
    currentSize /= 2;
    sliceIce(x, y, currentSize, targetSize);
    sliceIce(x + currentSize, y, currentSize, targetSize);
    sliceIce(x, y + currentSize, currentSize, targetSize);
    sliceIce(x + currentSize, y + currentSize, currentSize, targetSize);
}

void reduceIce() {
    vector<vector<bool>> reduceIceCheck(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || ice[ny][nx] == 0)
                    cnt++;
            }
            if (cnt >= 2)
                reduceIceCheck[i][j] = true;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (reduceIceCheck[i][j] && ice[i][j] > 0)
                ice[i][j]--;
}

int pow(int n) {
    if (n == 0)
        return 1;
    int pow = 2;
    while (--n > 0)
        pow *= 2;
    return pow;
}

int getLargestIce() {
    int maxCnt = 0;
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || ice[i][j] == 0)
                continue;
            int cnt = 0;
            queue<pair<int, int>> q;
            visited[i][j] = true;
            q.push({j, i});

            while (!q.empty()) {
                int qx = q.front().first;
                int qy = q.front().second;
                q.pop();
                cnt++;

                for (int k = 0; k < 4; k++) {
                    int nx = qx + dx[k];
                    int ny = qy + dy[k];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (visited[ny][nx] || ice[ny][nx] == 0)
                        continue;
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
            maxCnt = std::max(cnt, maxCnt);
        }
    }
    return maxCnt;
}

int main() {
    int temp, Q;
    cin >> temp >> Q;

    N = pow(temp);

    ice.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> ice[i][j];

    while (Q-- > 0) {
        int L;
        cin >> L;

        sliceIce(0, 0, N, pow(L));
        reduceIce();
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += ice[i][j];

    int maxCnt = getLargestIce();
    cout << sum << "\n" << maxCnt;
}