/*
대각선 점프를.. 예를들면 0,0 -> 1,2 -> 0,0 ..... 이렇게 visited[i][j][k++] 가 되면서 계속 쓸모없는 반복을 할텐데..
이걸 잡으면 시간을 줄일 수 있지 않을까?
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class P {
	int x, y, jump, cnt;

	public P(int x, int y, int jump, int cnt) {
		this.x = x;
		this.y = y;
		this.jump = jump;
		this.cnt = cnt;
	}
}

public class Main {

	static int[] dx = { 1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
	static int[] dy = { 0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1 };
	static int K, W, H;
	static boolean[][] map;
	static boolean[][][] visited;

	static int solve() {
		// 속도를 위해 Queue 대신 Deque 사용.
		Deque<P> dq = new ArrayDeque<P>();
		visited[0][0][0] = true;
		dq.addLast(new P(0, 0, 0, 0));

		while (!dq.isEmpty()) {
			P p = dq.pollFirst();
			// 끝에 다다른 값이 나오면 정답 리턴.
			if (p.x == W - 1 && p.y == H - 1)
				return p.cnt;

			// 상하좌우 이동
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= W || ny >= H) // 격자를 벗어날때
					continue;
				
				if (map[ny][nx]) // 이동하려는 칸에 	장애물이 있을 때
					continue;

				if (visited[nx][ny][p.jump]) // 이미 같은 점프 횟수로 도착한 적이 있는 칸일때는 굳이 다시 가볼 필요가 없다.
					continue;

				visited[ny][nx][p.jump] = true;
				dq.addLast(new P(nx, ny, p.jump, p.cnt + 1));
			}

			if (p.jump == K) // 이미 점프 기회를 다 소진해버렸으면 점프를 뛸 필요가 없음.
				continue;

			for (int i = 4; i < 12; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= W || ny >= H)
					continue;
				
				if (map[ny][nx])
					continue;
				
				if (visited[nx][ny][p.jump + 1])
					continue;

				visited[ny][nx][p.jump + 1] = true;
				dq.addLast(new P(nx, ny, p.jump + 1, p.cnt + 1));
			}

		}
		return -1; // 결국 끝에 다다르지 못하고 큐가 종료되면 -1 리턴.
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		K = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		map = new boolean[H][W];
		visited = new boolean[H][W][K + 1];

		/* visited 배열
		visited[y][x][k] = (x,y) 좌표까지 k번의 점프를 사용해서 도착한 적이 있는가? 
		*/
		
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				if (Integer.parseInt(st.nextToken()) == 1)
					map[i][j] = true;
			}
		}
		
		System.out.println(solve());
	}
}
