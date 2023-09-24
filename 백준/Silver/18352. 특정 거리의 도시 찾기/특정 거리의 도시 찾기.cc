#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
4 5 3 1
1 2
1 3
2 3
2 4
4 1
1->2->4->1 로 해서 3이 나오지만, 이미 1에서 1은 0이기 떄문에
정답은 -1이 나와야함.
*/
int main() {
	int numnode, numline, targetdist, startnode;
	cin >> numnode >> numline >> targetdist >> startnode;

	vector<vector<int>>line(numnode + 1);
	vector<int> dist(numnode + 1);
	vector<int>::iterator iter;
	queue<int> q;

	for (int i = 0; i < numline; i++) {
		int start, dst;
		cin >> start >> dst;
		line[start].push_back(dst);
	}

	q.push(startnode);

	while (!q.empty()) {
		int quenode = q.front();
		q.pop();
		for (iter = line[quenode].begin(); iter != line[quenode].end(); iter++) {//현재 보고잇는 노드에 인접한 노드들
			if (!dist[*iter]&&*iter!=startnode) {
				dist[*iter] = dist[quenode] + 1;
				q.push(*iter);
			}
		}
	}

	bool flag = 0;
	for (iter = dist.begin(); iter != dist.end(); iter++) {
		if (*iter == targetdist) {
			cout << iter - dist.begin() << endl;
			flag = true;
		}
	}
	if (!flag) cout << "-1";

}