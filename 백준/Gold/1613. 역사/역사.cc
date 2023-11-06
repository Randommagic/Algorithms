#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<bool>> v(N + 1, vector<bool>(N + 1));

    while (K-- > 0) {
        int srt, dst;
        cin >> srt >> dst;
        v[srt][dst] = true;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (v[i][k] && v[k][j])
                    v[i][j] = true;
            }
        }
    }

    int S;
    cin >> S;

    while (S-- > 0) {
        int srt, dst;
        cin >> srt >> dst;
        if (v[srt][dst])
            cout << "-1\n";
        else if (v[dst][srt])
            cout << "1\n";
        else
            cout << "0\n";
    }
}