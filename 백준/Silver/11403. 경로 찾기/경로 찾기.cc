#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<vector<int>> network(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> network[i][j];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (network[i][k] && network[k][j])
                    network[i][j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (network[i][j] ? "1 " : "0 ");
        cout << "\n";
    }
}