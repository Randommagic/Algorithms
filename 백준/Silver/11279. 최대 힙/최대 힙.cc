#include <iostream>
#include <vector>
using namespace std;

class maxheap {
private:
	int heap[100001] = { 0, };
	int last = -1;
public:
	int pop() {
		if (last == -1) return 0;
		else if (last == 0) {
			int returnvalue = heap[last--];
			return returnvalue;
		}
		int returnvalue = heap[0];
		int poploc = 0;
		int child;
		heap[0] = heap[last];
		heap[last--] = 0;

		child = poploc * 2 + 1;
		if (heap[child] < heap[child + 1]) child++;


		//자식이 더 크면 바꿔야함, .
		while (heap[poploc] < heap[child] && child <= last ) {
			swap(heap[poploc], heap[child]);
			poploc = child;
			child = poploc * 2 + 1;
			if (child+1<=last && heap[child] < heap[child + 1]) child++;
		}
		return returnvalue;
	}
	void push(int input) {
		int parent, inputloc;

		heap[++last] = input;
		if (!last)return;
		inputloc = last;
		parent = (inputloc-1) / 2;

		while (heap[parent] < heap[inputloc]&&inputloc) { //부모가 더 작으면 바꿔야함, inputloc이 첫번쨰 원소거나 부모보다 작으면 스탑.
			swap(heap[parent], heap[inputloc]);
			inputloc = parent;
			parent = (inputloc - 1) / 2;
		}
	}
};
int main() {
	int n,temp;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	maxheap mh;
	cin >> n;
	while (n--) {
		cin >> temp;
		if (!temp) cout << mh.pop()<< "\n";
		else mh.push(temp);
	}
}
