// 틀렸던 이유.   dist를 long long으로 하지 않고 int로 선언함.
// V가 500, E가 6000, 모든 edge가 -10000일때, 1->2로 -10000, 2->1로 -20000.... 해서 int범위를 초과할수있음.

#include <iostream>
#include <vector>
#define MAX 99999999
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int st, dst, cost;

    cin >> N >> M;

    vector<vector<int>> edges;
    while (M--) {
        cin >> st >> dst >> cost;
        edges.push_back({st, dst, cost});
    }

    vector<long long> dist(N + 1, MAX);
    dist[1] = 0;

    // N-1  + 1 번 반복하기.
    // 마지막 한번 더 체크할때  달라지는게 있다 = 음의 사이클 발견.
    for (int i = 1; i <= N; i++) {
        for (const auto &edge : edges) {
            st = edge[0];
            dst = edge[1];
            cost = edge[2];

            // 방문처리되지 않은 노드일 경우 pass.
            if (dist[st] == MAX)
                continue;
            // st -> dst 까지 거리 다시 계산.
            if (dist[dst] > dist[st] + cost) {
                if (i == N) {
                    cout << -1;
                    return 0;
                }
                dist[dst] = dist[st] + cost;
            }
        }
    }

    for (int i = 2; i <= N; i++)
        cout << (dist[i] == MAX ? -1 : dist[i]) << "\n";
}