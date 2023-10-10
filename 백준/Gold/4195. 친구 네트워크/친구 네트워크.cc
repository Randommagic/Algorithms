#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> network;
vector<int> networkCnt;

int getNetwork(int n) {
    if (network[n] == n)
        return n;
    network[n] = getNetwork(network[n]);
    return network[n];
}

void joinNetwork(int a, int b) {
    if (getNetwork(a) == getNetwork(b))
        return;

    if (a > b)
        swap(a, b);

    // b의 부모를 a의 부모 밑에 붙임
    networkCnt[getNetwork(a)] += networkCnt[getNetwork(b)];
    network[getNetwork(b)] = getNetwork(a);
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T-- > 0) {
        int F, idx = 0;
        unordered_map<string, int> um;
        network.clear();
        networkCnt.clear();

        cin >> F;
        while (F-- > 0) {
            string a, b;
            cin >> a >> b;
            if (um.find(a) == um.end()) {
                um.insert({a, idx});
                // network[0] = 0, network[1] = 1 ....
                network.push_back(idx);
                networkCnt.push_back(1);
                idx++;
            }

            if (um.find(b) == um.end()) {
                um.insert({b, idx});
                network.push_back(idx);
                networkCnt.push_back(1);

                idx++;
            }
            joinNetwork(um[a], um[b]);
            cout << networkCnt[getNetwork(um[a])] << "\n";
        }
    }
}
