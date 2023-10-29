
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, int> dict;
    int totalCnt = 0;
    string str;

    while (getline(cin, str)) {
        if (dict.find(str) == dict.end())
            dict[str] = 0;
        dict[str]++;
        totalCnt++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto tree : dict) {
        float n = (float)tree.second / totalCnt * 100;
        cout << tree.first << " " << n << "\n";
    }
}