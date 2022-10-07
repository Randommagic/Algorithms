import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int N, M, ans = 0;
	static final int INF = 9999;
	static int[][] map;
	static int[][] dist;
	static int numOfIsland;

	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int[] root;

	private static class Edge implements Comparable<Edge> {

		int srt, dst, d;

		public Edge(int srt, int dst, int d) {
			super();
			this.srt = srt;
			this.dst = dst;
			this.d = d;
		}

		@Override
		public int compareTo(Edge o) {
			return d - o.d;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}

		countIslands();
		// init dist
		dist = new int[numOfIsland + 1][numOfIsland + 1];
		for (int i = 1; i <= numOfIsland; i++)
			for (int j = 1; j <= numOfIsland; j++)
				dist[i][j] = INF;

		getAllDists();

		// debug();
		getMST();
		System.out.println(ans >= INF ? "-1" : ans);
	}

	private static void debug() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				System.out.print(map[i][j] + " ");
			System.out.println();
		}

		for (int i = 1; i <= numOfIsland; i++) {
			System.out.print(i + "-> ");
			for (int j = 1; j <= numOfIsland; j++) {
				System.out.print(dist[i][j] + " ");
			}

			System.out.println();
		}
	}

	private static void countIslands() {
		// 섬의 개수를 세고, 지도에서 각 섬마다 1 대신 섬의 번호를 붙여 준다.

		int num = 1;
		boolean[][] visited = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (map[i][j] != 0 && !visited[i][j]) {
					countIslandsBFS(j, i, num++, visited);
				}
		}
		numOfIsland = num - 1;
	}

	private static void countIslandsBFS(int x, int y, int n, boolean[][] visited) {
		Deque<int[]> q = new ArrayDeque<>();
		q.add(new int[] { x, y });
		map[y][x] = n;
		visited[y][x] = true;

		while (!q.isEmpty()) {
			int[] P = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = P[0] + dx[i];
				int ny = P[1] + dy[i];
				if (nx < 0 || ny < 0 || nx >= M || ny >= N)
					continue;
				if (visited[ny][nx] || map[ny][nx] == 0)
					continue;

				map[ny][nx] = n;
				visited[ny][nx] = true;
				q.add(new int[] { nx, ny });
			}
		}
	}

	private static void getAllDists() {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					getDist(j, i);
				}
			}
		}
	}

	private static void getDist(int x, int y) {
		// 섬의 각 포인트에서 상하좌우로 다른 섬 포인트를 만날때까지
		int currentIslandNo = map[y][x];

		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			int d = 0;
			while (true) {
				nx += dx[i];
				ny += dy[i];
				d++;

				if (nx < 0 || ny < 0 || nx >= M || ny >= N) // 맵밖으로 나갈경우
					break;
				if (map[ny][nx] == currentIslandNo) // 같은 섬을 만난경우
					break;
				if (map[ny][nx] == 0) // 바다이면 그냥 한칸 더 전진
					continue;
				if (d <= 2) // 다른 섬을 만나긴 했는데, 다리 길이가 1 이하일경우
					break;
				int newfoundIslandNo = map[ny][nx];

//				System.out.println(currentIslandNo +" 번 섬 (" + x + " " + y + ") 과  " + newfoundIslandNo + " 번 섬 (" + nx + " " + ny + ") 를 연결하는 거리: "+ (d-1));
				dist[currentIslandNo][newfoundIslandNo] = Math.min(dist[currentIslandNo][newfoundIslandNo], d - 1);
				break;
			}
		}
	}

	private static void getMST() {

		root = new int[numOfIsland + 1];
		for (int i = 1; i <= numOfIsland; i++)
			root[i] = i;

		PriorityQueue<Edge> pq = new PriorityQueue<>();

		for (int i = 1; i <= numOfIsland; i++)
			for (int j = 1; j <= numOfIsland; j++)
				pq.add(new Edge(i, j, dist[i][j]));

		int n = 0;
		while (n != numOfIsland - 1) {
			Edge E = pq.poll();
			if (checkRoot(E.srt) == checkRoot(E.dst))
				continue;
			union(E.srt, E.dst);
			ans += E.d;
			n++;
		}

	}

	private static int checkRoot(int n) {
		if (root[n] == n)
			return n;
		return root[n] = checkRoot(root[n]);
	}

	private static void union(int a, int b) {
		a = checkRoot(a);
		b = checkRoot(b);
		root[b] = a;
	}

}
