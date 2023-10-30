#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAX 99999999
using namespace std;

class dijkstra{
private:
    vector<map<int,int>> edges;
    vector<int> dist;
    int numOfNode, numOfEdge, startNode;
public:
    dijkstra(int numOfNode, int numOfEdge, int startNode){
        this->numOfNode = numOfNode;
        this->numOfEdge = numOfEdge;
        this->startNode = startNode;
        edges.resize(numOfNode+1);
        dist.resize(numOfNode+1,MAX);
    }
    void inputEdge(int st, int end, int dist){
        if(edges[st].find(end) != edges[st].end()){
            if(edges[st][end] > dist)
                edges[st][end] = dist;
        }
        else edges[st].insert(make_pair(end,dist));
    }
    void solve(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // dist , node
        dist[startNode] = 0;
        pq.push(make_pair(dist[startNode],startNode));

        while(!pq.empty()){
            int pqNode = pq.top().second;
            int psDist = pq.top().first;
            pq.pop();

            for(auto iter = edges[pqNode].begin(); iter != edges[pqNode].end();iter++){
                int nextNode = iter->first;
                int nextDist = iter->second;
                if(dist[nextNode] > dist[pqNode] + nextDist){
                    dist[nextNode] = dist[pqNode] + nextDist;
                    pq.push(make_pair(dist[nextNode],nextNode));
                }
            }
        }
        for(int i =1 ; i <= numOfNode; i++){
            dist[i] >=MAX? cout << "INF" : cout << dist[i];
            cout << "\n";
        }
    }
};


int main(){
    int numOfNode, numOfEdge, startNode;
    int start, end, dist;
    cin >> numOfNode >> numOfEdge >> startNode;
    dijkstra di(numOfNode,numOfEdge,startNode);
    while(numOfEdge--){
        cin >> start >> end >> dist;
        di.inputEdge(start,end,dist);
    }
    di.solve();
}