#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string str;
    cin >> str;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    stack<double> st;

    for (auto c : str) {
        if (c >= 'A' && c <= 'Z') {
            st.push((double)v[c - 'A']);
            continue;
        }
        double second = st.top();
        st.pop();
        double first = st.top();
        st.pop();
        if (c == '+')
            st.push(first + second);
        else if (c == '-')
            st.push(first - second);
        else if (c == '*')
            st.push(first * second);
        else if (c == '/')
            st.push(first / second);
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
}