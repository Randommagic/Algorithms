#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, S, answer = 0;

void DFS(int idx, int cnt, int sum) {
    if (idx == N) {
        if (sum == S && cnt != 0)
            answer++;
        return;
    }

    DFS(idx + 1, cnt + 1, sum + v[idx]);
    DFS(idx + 1, cnt, sum);
}

int main() {
    cin >> N >> S;

    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    DFS(0, 0, 0);
    cout << answer;
}
