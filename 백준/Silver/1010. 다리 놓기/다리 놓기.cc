#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        long long answer = 1;
        
        int r = 1;
        for(int i = b ; i > b-a ; i--){
            answer *= i;
            answer /= r++;
        }
        cout << answer << "\n";
    }
}
