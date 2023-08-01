// https://www.acmicpc.net/problem/1167
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> P;

P DFS(int nodeNum, vector<unordered_map<int, int>> &edge,
      vector<bool> &visited) {
    int lengthFromLeaf = 0;
    int maximumWidthSoFar = 0;
    vector<int> lengthFromLeaves;

    for (auto a : edge[nodeNum]) {
        if (visited[a.first])
            continue;
        visited[a.first] = true;
        P tempP = DFS(a.first, edge, visited);
        lengthFromLeaves.push_back(tempP.first + a.second);
        maximumWidthSoFar = std::max(maximumWidthSoFar, tempP.second);
    }
    sort(lengthFromLeaves.begin(), lengthFromLeaves.end(), greater<>());
    if (!lengthFromLeaves.empty()) {
        lengthFromLeaf = std::max(lengthFromLeaf, lengthFromLeaves[0]);
        maximumWidthSoFar = std::max(maximumWidthSoFar, lengthFromLeaf);
    }
    if (lengthFromLeaves.size() >= 2) {
        maximumWidthSoFar = std::max(maximumWidthSoFar,
                                     lengthFromLeaves[0] + lengthFromLeaves[1]);
    }
    return {lengthFromLeaf, maximumWidthSoFar};
}

int main() {
    int N;
    cin >> N;
    vector<unordered_map<int, int>> edge(N + 1);
    vector<bool> visited(N + 1);

    for (int i = 1; i <= N; i++) {
        int srt, dst, cost;
        cin >> srt;
        while (true) {
            cin >> dst;
            if (dst == -1)
                break;
            cin >> cost;
            if (edge[srt].find(dst) == edge[srt].end())
                edge[srt][dst] = 99999;
            edge[srt][dst] = std::min(edge[srt][dst], cost);
            if (edge[dst].find(srt) == edge[dst].end())
                edge[dst][srt] = 99999;
            edge[dst][srt] = std::min(edge[dst][srt], cost);
        }
    }
    visited[1] = true;
    P p = DFS(1, edge, visited);
    cout << p.second;
}
