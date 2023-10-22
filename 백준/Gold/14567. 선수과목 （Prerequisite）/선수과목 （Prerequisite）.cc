#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> conn(N + 1);
    vector<int> prereqCnt(N + 1);
    vector<int> answer(N + 1);
    while (M-- > 0) {
        int a, b;
        cin >> a >> b;
        prereqCnt[b]++;
        conn[a].push_back(b);
    }

    // 과목번호 , 이수 학기
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++)
        if (prereqCnt[i] == 0)
            q.push({i, 1});

    while (!q.empty()) {
        int qn = q.front().first;
        int qh = q.front().second;
        q.pop();
        answer[qn] = qh;

        for (const auto &a : conn[qn]) {
            prereqCnt[a]--;
            if (prereqCnt[a] == 0)
                q.push({a, qh + 1});
        }
    }

    for (int i = 1; i <= N; i++)
        cout << answer[i] << " ";
}