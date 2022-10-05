
/*
 deque에 push를 써서 삽질한 문제.. push말고 add를 쓰자. push는 stack으로 사용할떄처럼 맨 앞에 넣어버린다.


*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class P {
	int x, y, key, cnt;

	public P(int x, int y, int key, int cnt) {
		super();
		this.x = x;
		this.y = y;
		this.key = key;
		this.cnt = cnt;
	}
}

public class Main {

	static int N, M;
	static char[][] map;
	static boolean[][][] visited;
	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new char[N][M];
		visited = new boolean[N][M][64];

		int startx = 0, starty = 0;
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == '0') {
					map[i][j] = '.';
					startx = j;
					starty = i;
				}
			}
		}

		Deque<P> q = new ArrayDeque<P>();
		q.add(new P(startx, starty, 0, 0));

		while (!q.isEmpty()) {
			P p = q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= M || ny >= N)
					continue;

				// 이미 똑같은 열쇠보유 상황을 가지고 도착한 적이 있는가?
				if (visited[ny][nx][p.key])
					continue;

				char nc = map[ny][nx];

				if (nc == '.') {
					visited[ny][nx][p.key] = true;
					q.add(new P(nx, ny, p.key, p.cnt + 1));
					continue;
				}

				if (nc == '1') {
					System.out.println(p.cnt + 1);
					return;
				}

				if (nc >= 'a' && nc <= 'f') {
					int newKey = p.key;
					newKey |= (1 << (nc - 'a'));

					if (visited[ny][nx][newKey])
						continue;

					visited[ny][nx][newKey] = true;
					q.add(new P(nx, ny, newKey, p.cnt + 1));
				}

				if (nc >= 'A' && nc <= 'F') {
					if ((p.key & (1 << nc - 'A')) == 0)
						continue; // 다음 칸이 문이고, 그에 해당되는 열쇠가 없을 경우.

					visited[ny][nx][p.key] = true;
					q.add(new P(nx, ny, p.key, p.cnt + 1));
					continue;
				}

			}

		}
		System.out.println(-1);
	}
}
