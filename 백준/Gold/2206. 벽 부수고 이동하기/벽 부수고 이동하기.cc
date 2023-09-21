#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord{
    int x,y,blocked;
    coord(int x, int y, bool blocked) {
		this->x = x;
		this->y = y;
        this->blocked = blocked;
	}
};

class BFS{
private:
    vector<vector<int>> map;
    vector<vector<vector<int>>> dist;
    int xlen,ylen;
    int xdir[4] = {1,0,-1,0};
    int ydir[4] = {0,1,0,-1};
    int qx , qy , nextx, nexty;
    bool wallCrossed;

public:
    BFS(int x, int y, vector<vector<int>> map){
        this->map = map;
        this->xlen = x;
        this->ylen = y;
        dist.resize(ylen,vector<vector<int>>(xlen,vector<int>(2,0)));
        dist[0][0][0] = 1;
        dist[0][0][1] = 1;
    }

    //dist [y][x][벽을 안뚫었으면 0, 뚫었으면 1]

    int solve(){ 
        queue<coord> q;
        q.push(coord(0,0,false));

        while(!q.empty()){
            qx = q.front().x;
            qy = q.front().y;
            wallCrossed = q.front().blocked;

            if(qx == xlen-1 && qy == ylen-1) return dist[qy][qx][wallCrossed];

            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                nextx = qx + xdir[i];
                nexty = qy + ydir[i];
                if(nextx < 0 || nextx >= xlen || nexty < 0 || nexty >= ylen ) continue;
                if(map[nexty][nextx] == 1 && !wallCrossed){ // 다음 칸이 처음 뚫는 벽일때
                    q.push(coord(nextx,nexty,true));
                    dist[nexty][nextx][true] = dist[qy][qx][wallCrossed] + 1;
                }
                else if (map[nexty][nextx] == 0 && !dist[nexty][nextx][wallCrossed] ) { // 다음 칸이 빈 칸이고, 방문 안했을때
				    q.push(coord(nextx,nexty,wallCrossed));
                    dist[nexty][nextx][wallCrossed] = dist[qy][qx][wallCrossed] + 1;
			    }
            }
        }
        return -1;
    }

};


int main(){

    int xloc, yloc;
	cin >> yloc >> xloc;
    vector<vector<int>> temp(yloc,vector<int>(xloc,0));
    
	for (int y = 0; y < yloc; y++)
		for (int x = 0; x < xloc; x++)
			scanf("%1d",&temp[y][x]);

    BFS bfs(xloc,yloc,temp);
    cout << bfs.solve();
}
