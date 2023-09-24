#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v(5);
    for (int i = 0; i < 5; i++)
        cin >> v[i];

    string answer = "";

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 5; j++)
            if (i < v[j].size())
                answer += v[j][i];

    cout << answer;
}