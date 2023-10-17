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
    bool operator()(const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; }
};

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    // M = false , W = true
    vector<bool> gender(N + 1);
    group.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        group[i] = i;

        char c;
        cin >> c;
        if (c == 'W')
            gender[i] = true;
    }

    vector<vector<int>> edges;

    while (M-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), cmp());

    int cnt = 0, ans = 0;
    for (const auto &edge : edges) {
        if (gender[edge[0]] == gender[edge[1]])
            continue;
        if (getGroup(edge[0]) == getGroup(edge[1]))
            continue;
        joinGroup(edge[0], edge[1]);
        ans += edge[2];
        cnt++;
        if (cnt == N - 1)
            break;
    }

    cout << (cnt == N - 1 ? ans : -1);
}