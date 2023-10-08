#include <iostream>
#define MAX 10001
using namespace std;

int main() {
    int dp[MAX] = { 0, };
    int i, sum , temp;
    for (i = 1; i < MAX; i++) {
        sum = 0;
        temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        sum += i;
        if (sum >= MAX) continue;
        dp[sum]++;
    }

    for (i = 1; i < MAX; i++) {
        if (!dp[i]) {
            cout << i << endl;
        }
    }
}

