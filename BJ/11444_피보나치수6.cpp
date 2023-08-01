#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define MOD 1000000007

long long fib(long long n, unordered_map<long long, long long> &um) {
    if (um.find(n) != um.end())
        return um[n] % MOD;

    if (n % 2 == 0)
        um[n] = fib(n / 2, um) * (fib(n / 2 + 1, um) + fib(n / 2 - 1, um));
    else
        um[n] = fib((n + 1) / 2, um) * fib((n + 1) / 2, um) +
                fib((n - 1) / 2, um) * fib((n - 1) / 2, um);

    return um[n] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    unordered_map<long long, long long> um;
    um.insert({0, 0});
    um.insert({1, 1});
    um.insert({2, 1});

    cout << fib(n, um);
}
