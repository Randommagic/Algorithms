//https://www.acmicpc.net/source/46442121
// https://www.acmicpc.net/problem/9202
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

class Trie {
	Trie[] t;
	boolean endpoint;

	public Trie() {
		t = new Trie[26];
		endpoint = false;
	}

}

public class Main {

	static int N, T;
	static char[][] map;
	static boolean[][] visited;
	static int[] dx = { 1, 1, 0, -1, -1, -1, 0, 1 };
	static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static int[] score = { 0, 0, 1, 1, 2, 3, 5, 11 };
	static StringBuilder word;
	static Set<String> s;
	static Trie root;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		root = new Trie();

		for (int i = 0; i < N; i++) {
			insert(br.readLine());
		}

		br.readLine();
		T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			map = new char[4][];
			visited = new boolean[4][4];
			word = new StringBuilder();
			s = new TreeSet<>();

			for (int i = 0; i < 4; i++)
				map[i] = br.readLine().toCharArray();

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++) {
					visited[i][j] = true;
					DFS(j, i, 0, root);
					visited[i][j] = false;
				}
					

			if (t < T - 1)
				br.readLine();

			int size = s.size();
			String longest = "";
			int sum = 0;

			Iterator<String> iter = s.iterator();
			while (iter.hasNext()) {
				String str = iter.next();
				if (str.length() > longest.length())
					longest = str;
				sum += score[str.length() - 1];
			}
			sb.append(sum).append(" ").append(longest).append(" ").append(size).append("\n");
		}
		System.out.println(sb.toString());
	}

	static void DFS(int x, int y, int idx, Trie trie) {
		if (idx == 8) {
			return;
		}
		
		int c = map[y][x] - 'A';

		if (trie.t[c] == null)
			return;
		
		word.append(map[y][x]);
		check(word.toString(), 0, root);

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;
			if (visited[ny][nx])
				continue;
			visited[y][x] = true;
			DFS(nx, ny, idx + 1, trie.t[c]);
			visited[y][x] = false;
		}
		word.deleteCharAt(word.length() - 1);
		
	}

	public static void insert(String input) {
		Trie current = root;
		for (int i = 0; i < input.length(); i++) {
			int c = input.charAt(i) - 'A';
			if (current.t[c] == null)
				current.t[c] = new Trie();
			current = current.t[c];
		}
		current.endpoint = true;
	}

	public static void check(String input, int idx, Trie trie) {
		if (input.length() == idx) {
			if (trie.endpoint == true)
				s.add(input);
			return;
		}

		int c = input.charAt(idx) - 'A';
		if (trie.t[c] == null)
			return;

		check(input, idx + 1, trie.t[c]);
	}

}
