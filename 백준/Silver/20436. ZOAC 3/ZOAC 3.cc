#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<char, pair<int, int>> keyboard;
unordered_set<char> leftHandKey;

void initKeyboard() {
    vector<string> keys = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    string leftHandKeys = "qwertasdfgzxcv";
    for (int i = 0; i < keys.size(); i++)
        for (int j = 0; j < keys[i].size(); j++)
            keyboard.insert({keys[i][j], {i, j}});

    for (int i = 0; i < leftHandKeys.size(); i++)
        leftHandKey.insert(leftHandKeys[i]);
}

int getKeyBoardDist(char a, char b) {
    int cp = 0;
    cp = std::abs(keyboard[a].first - keyboard[b].first) + std::abs(keyboard[a].second - keyboard[b].second);
    return cp;
}

int main() {
    initKeyboard();

    char sl, sr;
    cin >> sl >> sr;

    string input;
    cin >> input;

    int ans = 0;
    for (auto c : input) {
        // 왼손을 움직여야 하는가?
        if (leftHandKey.find(c) != leftHandKey.end()) {

            ans += getKeyBoardDist(sl, c);
            sl = c;
        } else {
            ans += getKeyBoardDist(sr, c);
            sr = c;
        }
    }
    cout << ans + input.size();
}