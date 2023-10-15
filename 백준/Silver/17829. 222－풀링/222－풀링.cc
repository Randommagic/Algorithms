#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v, temp;
int N, answer = 0;

int getSecondMax(int x, int y) {
    vector<int> t;
    t.push_back(v[y][x]);
    t.push_back(v[y + 1][x]);
    t.push_back(v[y][x + 1]);
    t.push_back(v[y + 1][x + 1]);
    sort(t.begin(), t.end(), greater<>());
    return t[1];
}

void divide() {
    int tsize = temp.size();
    for (int i = 0; i < tsize; i++)
        for (int j = 0; j < tsize; j++)
            temp[i][j] = getSecondMax(j * 2, i * 2);
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    while (v.size() != 1) {
        int tsize = v.size() / 2;
        temp.clear();
        temp.resize(tsize, vector<int>(tsize));
        divide();
        v.clear();
        v = temp;
    }

    cout << v[0][0];
}
