#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int i = 0, max = 0, sum = 0, cnt = 1;

    for (; i < X; i++)
        sum += v[i];
    max = sum;

    for (; i < N; i++) {
        sum -= v[i - X];
        sum += v[i];
        if (sum > max) {
            cnt = 1;
            max = sum;
        } else if (sum == max)
            cnt++;
    }

    if (max == 0)
        cout << "SAD";
    else
        cout << max << "\n" << cnt;
}