/*
https://www.acmicpc.net/problem/20057
마법사 상어와 토네이도
*/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N, x,y, dir;
	static int combolimit, combo, combocombo;
	static int[][] map,temp;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	
	static int[][][] tornado ={
		{
			{0,0,2,0,0},{0,10,7,1,0},{5,0,0,0,0},{0,10,7,1,0},{0,0,2,0,0}
		},
		{
			{0,0,0,0,0},{0,1,0,1,0},{2,7,0,7,2},{0,10,0,10,0},{0,0,5,0,0}
		},
		{
			{0,0,2,0,0},{0,1,7,10,0},{0,0,0,0,5},{0,1,7,10,0},{0,0,2,0,0}
		},
		{
			{0,0,5,0,0},{0,10,0,10,0},{2,7,0,7,2},{0,1,0,1,0},{0,0,0,0,0}
		},	
	};
	
	
	// 1,1,2,2,3,3,4,4...... 칸 씩 방향 바꾸면서 이동.
	static void tornadoMove() {	
		x += dx[dir];
		y += dy[dir];
		combo++;
	}
	
	static void tornadoSweep() {
		int tornadoCenter = map[y][x];
		for(int i = 0 ; i < 5; i++) {
			for(int j = 0 ; j < 5; j++) {
				int tx = x - 2 + j;
				int ty = y - 2 + i;
				
				int blown = tornadoCenter * tornado[dir][i][j] / 100;
				map[y][x] -= blown;

				if(tx < 0 || ty < 0 || tx >= N || ty >= N ) continue;
				map[ty][tx] += blown;
			}
		}
		if(y+dy[dir] >= 0 && y+dy[dir] < N && x+dx[dir] >=0 && x+dx[dir] < N)
			map[y+dy[dir]][x+dx[dir]] += map[y][x];
		map[y][x] = 0;		
	}
	
	static void dirCheck() {
		if(combo == combolimit) {
			dir = (dir+1)%4;
			combo = 0;
			combocombo++;
			if(combocombo ==2) {
				combocombo = 0;
				combolimit++;
			}			
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		temp = new int[N][N];
		int originalTotal = 0;
		for(int i = 0 ; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				originalTotal += map[i][j];
			}	
		}
		
		x = N/2;
		y = N/2;
		dir = 0;
		combo = 0;
		combolimit = 1;
		combocombo = 0;
		
		while(true) {
			tornadoMove();
			tornadoSweep();
			dirCheck();
			if((x == 0 && y == 0)) break;
		}
		
		int leftOver = 0;
		for(int i = 0 ; i < N; i++) {
			for(int j = 0 ; j < N; j++) {
				leftOver += map[i][j];
			}
		}
		
		System.out.println(originalTotal - leftOver);
	}
}
