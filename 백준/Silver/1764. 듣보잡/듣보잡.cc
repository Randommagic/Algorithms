#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	string temp;
	cin >> n >> m;
	vector<string> nh, nhs;
	vector<string>::iterator iter;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (n--) {
		cin >> temp;
		nh.push_back(temp);
	}
	sort(nh.begin(), nh.end());

	while (m--) {
		cin >> temp;
		if (binary_search(nh.begin(), nh.end(),temp)) { // find함수는 시간 초과
			nhs.push_back(temp);
		}
	}
	sort(nhs.begin(), nhs.end());
	cout << nhs.size()<<"\n";
	for (iter = nhs.begin(); iter != nhs.end(); iter++) {
		cout << *iter << "\n";
	}
}
