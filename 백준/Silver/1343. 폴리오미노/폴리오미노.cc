#include <iostream>
#include <string>
#include <vector>

using namespace std;

void change(string &ans, int &xCnt) {
    while (xCnt >= 4) {
        xCnt -= 4;
        ans += "AAAA";
    }
    if (xCnt == 2)
        ans += "BB";
    xCnt = 0;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, ans;
    cin >> str;

    int xCnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'X') {
            xCnt++;
        } else {
            if (xCnt % 2 == 1) {
                cout << -1;
                return 0;
            }
            change(ans, xCnt);
            ans += ".";
        }
    }
    if (xCnt % 2 == 1) {
        cout << -1;
        return 0;
    }
    change(ans, xCnt);
    cout << ans;
}