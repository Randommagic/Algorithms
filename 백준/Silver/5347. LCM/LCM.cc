#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long GCB(long long a, long long b) {
    long long gcb = a * b;

    long long mod = a % b;
    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    gcb /= b;
    return gcb;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        long long a, b;
        cin >> a >> b;
        cout << GCB(a, b) << endl;
    }
}