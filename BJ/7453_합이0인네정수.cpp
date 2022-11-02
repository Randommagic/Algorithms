// 이분탐색을 하지 않고, 투포인터를 사용.

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	vector<int> a(N), b(N), c(N), d(N);
	vector<long long> temp1, temp2;

	for (int i = 0; i < N; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp1.push_back(a[i] + b[j]);
			temp2.push_back(c[i] + d[j]);
		}
	}

	sort(temp1.begin(), temp1.end()); // 오름차순
	sort(temp2.begin(), temp2.end(), greater<>()); // 내림차순

	int idx1 = 0, idx2 = 0;
	long long cnt = 0;
	while (true) {
		long long sum = temp1[idx1] + temp2[idx2];
		//cout << idx1 << ": " << temp1[idx1] << "   +   " << idx2 << ": " << temp2[idx2] << "  =  " << sum <<endl;
		if (sum == 0) {
			long long oneCnt = 0;
			long long twoCnt = 0;

			long long onetemp = temp1[idx1];
			while (idx1 < N*N) {
				if (temp1[idx1] == onetemp) oneCnt++;
				else break;
				idx1++;
			}

			long long twotemp = temp2[idx2];
			while (idx2 < N*N) {
				if (temp2[idx2] == twotemp) twoCnt++;
				else break;
				idx2++;
			}
			cnt += oneCnt * twoCnt;
		}
		else if (sum > 0) {
			idx2++;
		}
		else {
			idx1++;
		}

		if (idx1 == N * N || idx2 == N * N) break;
	}
	cout << cnt;

}
