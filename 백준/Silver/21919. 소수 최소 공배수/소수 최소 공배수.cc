#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    int maxElement = *max_element(v.begin(), v.end());
    vector<bool> sosu(maxElement + 1, true);
    sosu[0] = false;
    sosu[1] = false;

    for (int i = 2; i <= maxElement; i++) {
        if (!sosu[i])
            continue;
        int k = 2;
        while (k * i <= maxElement)
            sosu[k++ * i] = false;
    }

    long long answer = 1;
    for (auto a : v) {
        // a 중복 체크
        if (sosu[a] && answer % a != 0)
            answer *= a;
    }

    cout << (answer == 1 ? -1 : answer);
}