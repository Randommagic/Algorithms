#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> pref;
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int score[5] = {0, 1, 10, 100, 1000};

void seatfind(int student) {
    int prefMaxCnt = -1, emptyMaxCnt = -1, xLoc, yLoc;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (map[i][j] != 0)
                continue;

            int prefCnt = 0, emptyCnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                // 조건2
                if (map[ny][nx] == 0)
                    emptyCnt++;
                // 조건1 체크
                else {
                    for (auto bff : pref[student]) {
                        if (bff == map[ny][nx]) {
                            prefCnt++;
                            break;
                        }
                    }
                }
            }

            // 1번 조건 체크
            if (prefCnt > prefMaxCnt) {
                xLoc = j;
                yLoc = i;
                prefMaxCnt = prefCnt;
                emptyMaxCnt = emptyCnt;
                continue;
            }

            // 2번 조건.   3번조건은 2중포문이 실행순서에 따라 이미 걸러짐.
            if (prefCnt == prefMaxCnt) {
                if (emptyMaxCnt < emptyCnt) {
                    emptyMaxCnt = emptyCnt;
                    xLoc = j;
                    yLoc = i;
                }
            }
        }
    }

    map[yLoc][xLoc] = student;
}

int calcScore() {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                for (auto bff : pref[map[i][j]]) {
                    if (bff == map[ny][nx]) {
                        cnt++;
                        break;
                    }
                }
            }
            sum += score[cnt];
        }
    }
    return sum;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    pref.resize(N * N + 1, vector<int>(4));

    for (int i = 0; i < N * N; i++) {
        int student;
        cin >> student;
        for (int j = 0; j < 4; j++)
            cin >> pref[student][j];
        seatfind(student);
    }

    cout << calcScore();
}