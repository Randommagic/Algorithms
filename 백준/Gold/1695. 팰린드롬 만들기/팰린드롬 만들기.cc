#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<vector<int>> dp;

int solve(int left, int right) {
    if (left >= right)
        return 0;

    int &sdp = dp[left][right];
    // 이미 계산되어 있으면 묻지도 따지지도 않고 리턴
    if (sdp != -1)
        return sdp;

    // 맨 끝이 같으면 다음으로 넘어가기
    if (arr[left] == arr[right])
        return sdp = solve(left + 1, right - 1);

    return sdp = min(solve(left + 1, right), solve(left, right - 1)) + 1;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    dp.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << solve(0, N - 1);
}
