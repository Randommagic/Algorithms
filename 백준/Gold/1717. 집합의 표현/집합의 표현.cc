#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int N, M;

int getParent(int n) {
    if (parent[n] == n)
        return n;
    parent[n] = getParent(parent[n]);
    return parent[n];
}

void joinParent(int a, int b) {
    if (getParent(a) == getParent(b))
        return;

    if (a > b)
        swap(a, b);

    parent[getParent(b)] = getParent(a);
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    while (M-- > 0) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
            joinParent(a, b);
        else
            cout << (getParent(a) == getParent(b) ? "YES\n" : "NO\n");
    }
}
