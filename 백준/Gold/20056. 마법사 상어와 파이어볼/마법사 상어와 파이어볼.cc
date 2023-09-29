/*
4 9 5
3 2 8 5 2
3 3 19 3 4
3 1 7 1 1
4 4 6 4 0
2 1 6 2 5
4 3 9 4 3
2 2 16 1 2
4 2 17 5 3
3 4 3 5 7
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

class Fireball {
  public:
    int x, y;
    int m, s, d;
    Fireball(int y = 0, int x = 0, int m = 0, int s = 0, int d = 0) : y(y), x(x), m(m), s(s), d(d){};

    // sort를 위한 operator
    bool operator<(const Fireball &a) const {
        if (this->x == a.x)
            return this->y < a.y;
        return this->x < a.x;
    }
};

int N;
vector<Fireball> fireballs;

// 현재 fireball 배열에 있는 화염구를 움직여서, 새 배열에 넣고,
// 다 끝나면 다시 fireball 배열로 복사
void moveFireball() {
    vector<Fireball> newFireballs;

    for (auto fb : fireballs) {
        int nx = fb.x + dx[fb.d] * fb.s;
        int ny = fb.y + dy[fb.d] * fb.s;
        nx = (nx % N) >= 0 ? nx % N : (nx % N) + N;
        ny = (ny % N) >= 0 ? ny % N : (ny % N) + N;
        newFireballs.push_back(Fireball(ny, nx, fb.m, fb.s, fb.d));
    }
    fireballs.clear();
    fireballs = newFireballs;
    sort(fireballs.begin(), fireballs.end());
}

// sort해서 x,y 좌표가 같은 fireball이 바로 다음으로 옴으로 인해서
// fireball 합칠수 있게
void addAndDivideFireball() {
    if (fireballs.size() == 0)
        return;

    vector<Fireball> newFireballs;
    for (int i = 0; i < fireballs.size();) {
        Fireball fb = fireballs[i];
        i++;

        bool isSameDir = true;
        int cnt = 1;

        while (i < fireballs.size()) {
            Fireball fb2 = fireballs[i];
            if (fb.x != fb2.x || fb.y != fb2.y)
                break;

            fb.m += fb2.m;
            fb.s += fb2.s;
            cnt++;
            i++;
            if (!isSameDir)
                continue;

            // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수인지 체크
            if (fb.d % 2 != fb2.d % 2)
                isSameDir = false;
        }
        // 2개 이상의 파이어볼이 합쳐진다면
        if (cnt >= 2) {
            // 질량은 (합쳐진 파이어볼 질량의 합)/5
            fb.m /= 5;
            // 질량이 0인 파이어볼은 소멸
            if (fb.m == 0)
                continue;
            // 속력은 (합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)
            fb.s /= cnt;
            // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7
            for (int k = 0; k < 4; k++) {
                newFireballs.push_back(Fireball(fb.y, fb.x, fb.m, fb.s, isSameDir ? k * 2 : k * 2 + 1));
            }
        } else
            newFireballs.push_back(fb);
    }

    fireballs.clear();
    fireballs = newFireballs;
}

int calculateFireball() {
    int total = 0;
    for (Fireball fb : fireballs)
        total += fb.m;
    return total;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    while (M-- > 0) {
        int y, x, m, s, d;
        cin >> y >> x >> m >> s >> d;
        fireballs.push_back(Fireball(y - 1, x - 1, m, s, d));
    }

    while (K-- > 0) {
        moveFireball();
        addAndDivideFireball();
    }
    cout << calculateFireball() << endl;
}
