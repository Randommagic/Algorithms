#include <iostream>
#include <vector>
using namespace std;

class network {
private:
	vector<int>v;
	int avoidparent;
public:
	network(int n) {
		v.resize(n + 1);
		for (int i = 0; i < n + 1; i++) v[i] = i;
		avoidparent = 0;
	}

	int findparent(int a) {
		if (v[a] == a) return a;
		else {
			int temp = findparent(v[a]);
			v[a] = temp; // #########압축!!!!########
			return temp;
		}
	}
	int join(int a, int b) {
		int p_a, p_b;
		p_a = findparent(a);
		p_b = findparent(b);
		if (p_a < p_b) {
			v[p_b] = p_a;
			return p_a;
		} 	
		else if	(p_a > p_b) {
			v[p_a] = p_b; 
			return p_b;
		}
	}
	
	int joinavoid(int a) {
		int p_a = findparent(a);
		if (!avoidparent) avoidparent = p_a;
		else {
			if (avoidparent > p_a) {
				v[avoidparent] = p_a;
				avoidparent = p_a;
			}
			else v[a] = avoidparent;
		}
		return avoidparent;
	}

	int showparent(int a) {
		return findparent(a);
	}

};

int main() {
	int pplnum, partynum, avoidnum, avoidparent = 0, avoidcount =0;
	cin >> pplnum >> partynum >> avoidnum;
	
	network nt(pplnum);
	int temp, temp2;
	for (int i = 0; i < avoidnum; i++) {
		cin >> temp;
		avoidparent = nt.joinavoid(temp);
	}

	vector<int>party(partynum);
	for (int i = 0; i < partynum; i++) {
		cin >> temp;
		for (int k = 0; k < temp; k++) {
			cin >> temp2;
			if (!party[i]) party[i] = nt.findparent(temp2);
			else {
				party[i] = nt.join(party[i], temp2);
			}
		}
		avoidparent = nt.findparent(avoidparent);
	}
	for (int i = 0; i < partynum; i++) {
		party[i] = nt.findparent(party[i]);
		if (party[i] == avoidparent)avoidcount++;
	}
	cout << partynum - avoidcount;
}