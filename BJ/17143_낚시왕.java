

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Shark implements Comparable<Shark> {
	int x, y, spd, dir, size;

	public Shark(int x, int y, int spd, int dir, int size) {
		super();
		this.x = x;
		this.y = y;
		this.spd = spd;
		this.dir = dir;
		this.size = size;
	}

	@Override
	public int compareTo(Shark o) {
		if (x == o.x && y == o.y)
			return size - o.size;
		if (x == o.x)
			return y - o.y;
		else
			return x - o.x;
	}
}

public class Main {

	static int R, C, M;
	static int ans, king_x;
	static List<Shark> list;
	static int[] dx = { 0, 0, 1, -1 }; // 위,아래,오,왼
	static int[] dy = { -1, 1, 0, 0 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		ans = 0;
		king_x = -1;

		list = new ArrayList<Shark>();

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken()) - 1;
			int x = Integer.parseInt(st.nextToken()) - 1;
			list.add(new Shark(x, y, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) - 1,
					Integer.parseInt(st.nextToken())));
		}
		Collections.sort(list);

		while (king_x != C) {
			kingMoveAndCatch();
			sharkMove();
			sharkEat();
		}

		System.out.println(ans);
	}

	private static void sharkEat() {
		Collections.sort(list);
		for (int i = 0; i < list.size() - 1; i++) {
			if (list.get(i).x == list.get(i + 1).x && list.get(i).y == list.get(i + 1).y) {
				list.remove(i);
				i--;
			}
		}
	}

	private static void sharkMove() {
		for (int i = 0; i < list.size(); i++) {
			int x = list.get(i).x;
			int y = list.get(i).y;
			int dist = list.get(i).spd;
			int dir = list.get(i).dir;
			int wOrh = dir <= 1 ? R : C;
			dist %= (wOrh - 1) * 2;

			while (dist-- > 0) {
				if (dir > 1 && (x + dx[dir] < 0 || x + dx[dir] >= wOrh))
					dir ^= 1; // 0 <-> 1  , 2 <-> 3

				if (dir <= 1 && (y + dy[dir] < 0 || y + dy[dir] >= wOrh))
					dir ^= 1;

				x += dx[dir];
				y += dy[dir];
			}
			list.get(i).x = x;
			list.get(i).y = y;
			list.get(i).dir = dir;
		}
	}

	private static void kingMoveAndCatch() {
		king_x++;

		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).x != king_x)
				continue;
			ans += list.get(i).size;
			list.remove(i);
			break;
		}

	}

}
