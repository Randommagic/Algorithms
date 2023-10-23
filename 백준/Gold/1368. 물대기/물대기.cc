#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, answer = 0;
    cin >> N;
    vector<vector<int>> edge(N + 1, vector<int>(N + 1, MAX));
    vector<bool> selected(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> edge[0][i];
        edge[i][0] = edge[0][i];
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> edge[i][j];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        int qc = pq.top().first;
        int qn = pq.top().second;
        pq.pop();

        if (selected[qn])
            continue;
        selected[qn] = true;
        answer += qc;

        for (int i = 0; i <= N; i++) {
            if (selected[i])
                continue;
            pq.push({edge[qn][i], i});
        }
    }
    cout << answer;
}