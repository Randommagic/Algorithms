//https://www.acmicpc.net/problem/16946
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;



int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int N,M;
    cin >> N >> M;
    vector<vector<int>> map(N,vector<int>(M));
    vector<vector<int>> answer(N,vector<int>(M));
    unordered_map<int,int> m;


    for(int i = 0 ; i < N; i++){
        string str = "";
        cin >> str;
        for(int j = 0 ; j < M ; j++)
            if(str[j] == '1') map[i][j] = -1;
    }


    // fill map with numbers
    int cnt = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] != 0) continue;
            queue<pair<int,int>> q;
            q.push({j,i});
            map[i][j] = ++cnt;
            m[cnt] = 1;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int k = 0 ; k < 4 ; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= M ||ny >=N) continue;
                    if(map[ny][nx] != 0 ) continue;
                    map[ny][nx] = cnt;
                    m[cnt]++;
                    q.push({nx,ny});
                } 
            }
        }
    }

    //check from every wall, 4 side
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] != -1){
                answer[i][j] = 0;
                continue;
            } 

            set<int> s;
            for(int k = 0 ; k < 4 ; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx < 0 || ny < 0 || nx >= M ||ny >=N) continue;
                if(map[ny][nx] == -1) continue;
                s.insert(map[ny][nx]);
            }
            
            int cnt = 0;
            for(int a : s) cnt += m[a];
            answer[i][j] = (cnt+1) % 10;
        }
    }


    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++)
            cout << answer[i][j];
        cout << endl;
    }

}
