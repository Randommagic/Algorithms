#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> group;

int getGroup(int n) {
    if (group[n] == n)
        return n;
    return group[n] = getGroup(group[n]);
}

void joinGroup(int a, int b) {
    a = getGroup(a);
    b = getGroup(b);
    if (a > b)
        swap(a, b);
    group[b] = a;
}

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) { return a[2] <= b[2]; }
};

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;

    group.resize(V + 1);
    for (int i = 1; i <= V; i++)
        group[i] = i;

    vector<vector<int>> edges;

    while (E-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a, b});
    }
    sort(edges.begin(), edges.end());

    int cnt = 0, ans = 0;

    for (const auto &edge : edges) {
        if (getGroup(edge[1]) == getGroup(edge[2]))
            continue;
        joinGroup(edge[1], edge[2]);
        ans += edge[0];
        if (cnt == V - 1)
            break;
    }
    cout << ans;
}