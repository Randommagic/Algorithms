#include <iostream>
#include <vector>
#define MAXDAY 14
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int money;
    vector<int> price(MAXDAY);
    cin >> money;

    for (int i = 0; i < MAXDAY; i++)
        cin >> price[i];

    // BNP
    int BNPmoney = money;
    int BNPstock = 0;

    for (int i = 0; i < MAXDAY; i++) {
        int availableStockCnt = BNPmoney / price[i];
        BNPmoney -= availableStockCnt * price[i];
        BNPstock += availableStockCnt;
    }

    BNPmoney += price[MAXDAY - 1] * BNPstock;

    // TIMING
    int TIMINGmoney = money;
    int TIMINGstock = 0;

    int combo = 0;
    for (int i = 1; i < MAXDAY; i++) {
        // 전일대비 상승
        if (price[i - 1] < price[i]) {
            if (combo < 0)
                combo = 0;
            combo++;
        } else if (price[i - 1] > price[i]) {
            if (combo > 0)
                combo = 0;
            combo--;
        } else
            combo = 0;

        if (combo == 3) { // 3일 연속 상승 -> 전량 매도
            TIMINGmoney += TIMINGstock * price[i];
            TIMINGstock = 0;
        } else if (combo == -3) {
            int availableStockCnt = TIMINGmoney / price[i];
            TIMINGmoney -= availableStockCnt * price[i];
            TIMINGstock += availableStockCnt;
        }
    }

    TIMINGmoney += price[MAXDAY - 1] * TIMINGstock;

    cout << (BNPmoney >= TIMINGmoney ? (BNPmoney == TIMINGmoney ? "SAMESAME" : "BNP") : "TIMING");
}