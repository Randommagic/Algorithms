#include <iostream>
#include <queue>
#include <vector>
#define MAX 9999999
using namespace std;

int N, X;

int getTravelTimeToX(int i, vector<vector<pair<int, int>>> &edges) {
    vector<int> dist(N + 1, MAX);
    dist[i] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[i], i});
    while (!pq.empty()) {
        int pn = pq.top().second;
        pq.pop();
        if (pn == X)
            break;
        for (const auto &edge : edges[pn]) {
            int nextN = edge.first;
            int nextD = edge.second;
            if (dist[nextN] > dist[pn] + nextD) {
                dist[nextN] = dist[pn] + nextD;
                pq.push({dist[nextN], nextN});
            }
        }
    }
    return dist[X];
}

int getTravelTimeFromX(int i, vector<vector<pair<int, int>>> &edges) {
    vector<int> dist(N + 1, MAX);
    dist[X] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[X], X});
    while (!pq.empty()) {
        int pn = pq.top().second;
        pq.pop();

        if (pn == i)
            break;
        for (const auto &edge : edges[pn]) {
            int nextN = edge.first;
            int nextD = edge.second;
            if (dist[nextN] > dist[pn] + nextD) {
                dist[nextN] = dist[pn] + nextD;
                pq.push({dist[nextN], nextN});
            }
        }
    }
    return dist[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> edges(N + 1);

    while (M-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
        answer = std::max(answer, getTravelTimeToX(i, edges) + getTravelTimeFromX(i, edges));

    cout << answer;
}