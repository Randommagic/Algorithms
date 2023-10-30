#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define MAX 9999999
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, start;
    cin >> V >> E >> start;

    vector<map<int, int>> edge(V + 1);
    vector<int> dist(V + 1, MAX);
    while (E-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        if (edge[a].find(b) == edge[a].end())
            edge[a][b] = MAX;
        edge[a][b] = std::min(c, edge[a][b]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int qn = pq.top().second;
        pq.pop();

        for (const auto &nextNode : edge[qn]) {
            int nextn = nextNode.first;
            int nextd = nextNode.second;

            if (dist[nextn] > dist[qn] + nextd) {
                dist[nextn] = dist[qn] + nextd;
                pq.push({dist[nextn], nextn});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}