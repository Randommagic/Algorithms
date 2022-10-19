import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static class P {
		long x, y;

		public P(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());

		P[] points = new P[N];

		st = new StringTokenizer(br.readLine());
		points[0] = new P(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));

		// 시작점 찾기, y가 가장 작고, y가 같으면 x도 가장 작은 점.
		for (int i = 1; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			points[i] = new P(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

			if (points[0].y > points[i].y || (points[0].y == points[i].y && points[0].x > points[i].x)) {
				P temp = points[0];
				points[0] = points[i];
				points[i] = temp;
			}
		}

		Arrays.sort(points, 0, points.length, (o1, o2) -> {
			long ret = ccw(points[0], o1, o2);
			if (ret > 0)
				return -1;
			else if (ret < 0)
				return 1;
			else {
				long diff = dist(points[0], o1) - dist(points[0], o2);
				return diff > 0 ? 1 : -1;
			}
		});

		
		Stack<P> s = new Stack<>();
		s.add(points[0]);

		int len = points.length;
		for (int i = 1; i < len; i++) {
			P third = points[i];

			while (s.size() > 1) {
				P second = s.get(s.size() - 2);
				P first = s.get(s.size() - 1);
				long ret = ccw(second, first, third);
				if (ret <= 0) // 반시계가 아니면 뺴줌
					s.pop();
				else
					break;
			}
			s.add(points[i]);
		}
		System.out.println(s.size());
	}

	static long ccw(P p1, P p2, P p3) {

		long ret = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

		return ret;
//		if (ret > 0) { // 반시계 방향
//			return 1;
//		} else if (ret < 0) { // 시계 방향
//			return -1;
//		} else {
//			return 0;
//		}
	}

	static long dist(P p1, P p2) {
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}

}
