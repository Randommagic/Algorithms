#include <string>
#include <vector>

using namespace std;

int n,m;
int discountRates[4] = {10,20,30,40};
int maxSubCnt = 0, maxSale = 0;

vector<vector<int>> users;
vector<int> emoticonPrice, emoticonDiscountRates;


void check(){
   
    int tempSubCnt = 0;
    int tempSale = 0;
    
    // 각 사용자마다 비율 기준에 따라서 이모티콘 구매 가격 계산.
    for(auto user : users){
        int userRate = user[0];
        int userMaxPrice = user[1];
        int userTempPrice = 0;
        
        for(int i = 0 ; i < m ; i++){
            // 자신 할인 기준보다 더 할인하면 구매.
            if(userRate <= emoticonDiscountRates[i])
                userTempPrice += emoticonPrice[i] * (100 - emoticonDiscountRates[i]) / 100;
        } 
        
        // 자신 기준 가격 합보다 높으면, 구매 대신 서비스 가입.
        if(userMaxPrice > userTempPrice) tempSale += userTempPrice;
        else tempSubCnt++;        
    }
    
    // 이모티콘 플러스 서비스 가입자가 최대다 -> 가입자, 판매액 갱신
    if(maxSubCnt < tempSubCnt){
        maxSubCnt = tempSubCnt;
        maxSale = tempSale;
    }
    // 이모티콘 플러스 서비스 가입자는 동률 -> 판매액 갱신.
    else if(maxSubCnt == tempSubCnt) {
        maxSale = std::max(maxSale, tempSale);
    }
    // 플러스 가입자가 더 낮다면 확인할 필요 없음.
    return;
}



// 7개의 이모티콘당, 각 4개씩 할인율 책정 가능
// 4의 7승의 경우의 수 = 16384회
void DFS(int idx){
    // m개의 이모티콘에 대해 할인율 설정을 마치면, 가격 체크
    if(idx == m){
        check();
        return;
    }
    
    // 각 이모티콘마다 4가지 할인율 적용 가능. 
    for(int i = 0 ; i < 4 ; i++){
        emoticonDiscountRates[idx] = discountRates[i];
        DFS(idx+1);
    }
    return;
}


vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    n = _users.size();
    m = _emoticons.size();
    
    // call by ref로 넘기거나, 전역으로 따로 복사해서 다른 함수에서도 사용, 이번에는 후자
    users = _users;
    emoticonPrice = _emoticons;
    emoticonDiscountRates.resize(m);
    
    // 할인율 책정을 위해 dfs
    DFS(0);
    
    return {maxSubCnt, maxSale};
}