#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class q1260 {
public:
	vector <vector <int>> arr;
	vector <int> visited;
	queue <int> que;
	
	q1260(int N){
		arr.resize(1005);
		visited.resize(1005);
	}
	void newline(int a, int b) {
		arr[a].push_back(b);
		sort(arr[a].begin(), arr[a].end());
		arr[b].push_back(a);
		sort(arr[b].begin(), arr[b].end());
	}
	void DFS(int N) {
		vector<int>::iterator iter;
		visited[N] = true;
		cout << N << " ";
		for (iter = arr[N].begin(); iter != arr[N].end(); iter++) {
			if (visited[*iter] == false) DFS(*iter);
		}
	}

	void BFS(int N) {
		vector<int>::iterator iter;
		if(!que.empty()) que.pop();
		if (!visited[N]) {
			visited[N] = true;
			cout << N << " ";
			for (iter = arr[N].begin(); iter != arr[N].end(); iter++) {
				if (visited[*iter] == false) que.push(*iter);
			}
		}
		//큐에 일단 돌면서 집어 넣고 다음 큐에 있는 숫자로 BFS실행	
		if (!que.empty()) BFS(que.front());
	}
};

int main() {
	int N, M, i, node;
	int input1, input2;
	cin >> N >> M >> node;
	q1260 DFS(N);
	q1260 BFS(N);
	
	for (i = 0; i < M; i++) {
		cin >> input1 >> input2;
		BFS.newline(input1, input2);
		DFS.newline(input1, input2);
	}

	DFS.DFS(node);
	cout << endl;
	BFS.BFS(node);
}		