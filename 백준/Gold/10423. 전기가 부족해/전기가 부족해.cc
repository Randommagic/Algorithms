#include <algorithm>
#include <iostream>
#include <queue>
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

int main() {

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    group.resize(N + 1);
    for (int i = 0; i <= N; i++)
        group[i] = i;

    // 발전소 처리
    int generator, temp;
    cin >> generator;
    for (int i = 1; i < K; i++) {
        cin >> temp;
        joinGroup(generator, temp);
    }

    // 케이블 처리
    vector<vector<int>> cables;
    while (M-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        cables.push_back({c, a, b});
    }
    sort(cables.begin(), cables.end());

    // 크루스칼
    int cnt = 0, totalCost = 0;

    for (const auto &cable : cables) {
        if (getGroup(cable[1]) == getGroup(cable[2]))
            continue;
        cnt++;
        totalCost += cable[0];
        joinGroup(cable[1], cable[2]);

        if (cnt == N - K)
            break;
    }

    cout << totalCost;
}