/*
https://www.acmicpc.net/problem/17070
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static boolean[][] map;
	static int[][][] dp;

	static boolean check_right(int x, int y) {
		if (x + 1 >= N)
			return false;
		if (map[y][x + 1])
			return false;
		return true;
	}

	static boolean check_down(int x, int y) {
		if (y + 1 >= N)
			return false;
		if (map[y + 1][x])
			return false;
		return true;
	}

	static boolean check_diag(int x, int y) {
		if (x + 1 >= N || y + 1 >= N)
			return false;
		if (map[y][x + 1] || map[y + 1][x] || map[y + 1][x + 1])
			return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		map = new boolean[N][N];
		dp = new int[N][N][3]; // 파이프 끝점의 위치 / 가로, 세로, 대각선

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++)
				if (Integer.parseInt(st.nextToken()) == 1)
					map[i][j] = true;
		}

		dp[0][1][0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				for (int dir = 0; dir < 3; dir++) {
					if (dp[i][j][dir] == 0)
						continue;
					if (dir == 0) {
						if (check_right(j, i))
							dp[i][j + 1][0] += dp[i][j][0];
						if (check_diag(j, i))
							dp[i + 1][j + 1][2] += dp[i][j][0];
					} else if (dir == 1) {
						if (check_down(j, i))
							dp[i + 1][j][1] += dp[i][j][1];
						if (check_diag(j, i))
							dp[i + 1][j + 1][2] += dp[i][j][1];
					} else {
						if (check_right(j, i))
							dp[i][j + 1][0] += dp[i][j][2];
						if (check_down(j, i))
							dp[i + 1][j][1] += dp[i][j][2];
						if (check_diag(j, i))
							dp[i + 1][j + 1][2] += dp[i][j][2];
					}
				}
			}
		}

		int answer = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
		System.out.println(answer);
	}
}
