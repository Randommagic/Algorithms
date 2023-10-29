#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> nodeCnt;

int DFS(int node, int parent) {
    int cnt = 1;

    for (auto child : edge[node]) {
        if (child == parent)
            continue;
        cnt += DFS(child, node);
    }
    return nodeCnt[node] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;
    edge.resize(N + 1);
    nodeCnt.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    DFS(R, -1);

    while (Q-- > 0) {
        int a;
        cin >> a;
        cout << nodeCnt[a] << "\n";
    }
}