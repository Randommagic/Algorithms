#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> edge;
vector<bool>visited;
vector<int>parent;

int main(){
    cin >> N;
    edge.resize(N+1);
    visited.resize(N+1,false);
    parent.resize(N+1);
    
    for(int i = 0 ; i < N - 1; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    queue<int>q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()){
        int n = q.front(); q.pop();
        
        for(int i = 0 ; i < edge[n].size(); i++){
            int nn = edge[n][i];
            if(!visited[nn]){
                visited[nn] = true;
                parent[nn] = n;
                q.push(nn);
            }
        }
    }
    
    for(int i = 2 ; i <= N ; i++)
        cout << parent[i] << "\n";
}