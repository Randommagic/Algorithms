#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100000001


class dijkstra {
private:
	vector<vector<pair<int,int>>> edge;
	int nodenum;
	int startNode, destNode;
	vector<int> parent;
public:
	dijkstra(int node, int edge) {
		nodenum = node;
		startNode = 1;
		destNode = nodenum;
		this->edge.resize(node + 1);
		parent.resize(nodenum + 1);
		for(int i = 1; i <= nodenum; i++)
			parent[i] = i;
		parent[1] = 0;
	}
	void inputedge(int start, int end, int cost) {
		edge[start].push_back(make_pair(end, cost));
		edge[end].push_back(make_pair(start, cost));
	}

	int getNonBlockedTime(){
		vector<int>dist(nodenum + 1, MAX);
		dist[startNode] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // cost, dest
		pq.push(make_pair(dist[startNode], startNode));

		while (!pq.empty()) {
			int qnode = pq.top().second;
			int qdist = pq.top().first;
			pq.pop();

			for (int i = 0;i<edge[qnode].size();i++) {
				int nextNode = edge[qnode][i].first;
				int nextCost = edge[qnode][i].second;
				if (dist[nextNode] > dist[qnode] + nextCost) {
					dist[nextNode] = dist[qnode] + nextCost;
					pq.push(make_pair(dist[nextNode], nextNode));
					parent[nextNode] = qnode;
				}
			}
		}
		return dist[destNode];
	}

	int getBlockedTime(int blockNode1, int blockNode2){
		vector<int>dist(nodenum + 1, MAX);
		dist[startNode] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // cost, dest
		pq.push(make_pair(dist[startNode], startNode));

		while (!pq.empty()) {
			int qnode = pq.top().second;
			int qdist = pq.top().first;
			pq.pop();

			for (int i = 0;i<edge[qnode].size();i++) {
				int nextNode = edge[qnode][i].first;
				int nextCost = edge[qnode][i].second;

				if((blockNode1==qnode && blockNode2==nextNode)||(blockNode2==qnode && blockNode1==nextNode))
					continue;
				if (dist[nextNode] > dist[qnode] + nextCost) {
					dist[nextNode] = dist[qnode] + nextCost;
					pq.push(make_pair(dist[nextNode], nextNode));
				}
			}
		}
		return dist[destNode];
	}

	int solve(){
		int minTime = getNonBlockedTime(), maxTime = 0; 
		int stNode = destNode;
		while(parent[stNode]){
			//cout << stNode << " " << parent[stNode] << endl;
			int blockedTime = getBlockedTime(stNode, parent[stNode]);
			maxTime = max(maxTime,blockedTime);
			stNode =  parent[stNode];
		}
		if(maxTime == MAX) return -1;
		else return maxTime - minTime;
	}
};

int main() {
	int numOfNode, numOfEdge;
	int st, dst, c;
	cin >> numOfNode >> numOfEdge;
	dijkstra di(numOfNode, numOfEdge);	

	while(numOfEdge--){
		cin >> st >> dst >> c;
		di.inputedge(st,dst,c);
	}
	cout << di.solve();
}
