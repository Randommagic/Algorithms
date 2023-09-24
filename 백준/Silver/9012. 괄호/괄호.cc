#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main() {
	int N;
	bool flag = false;
	cin >> N;
	vector<string>input;
	vector<string>::iterator iter;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		input.push_back(temp);
		flag = false;
		stack<int>st;
		for (int k = 0; k < input[i].size() && !flag; k++) {

			if (input[i][k] == '(') {
				st.push(1);
			}
			else if (input[i][k] == ')') {
				if (st.empty()) {
					cout << "NO\n";
					flag = true;
				}
				else st.pop();
			}
		}
		if (!st.empty()) {
			cout << "NO\n"; continue;
		}
		if (!flag) cout << "YES\n";
	}
}
