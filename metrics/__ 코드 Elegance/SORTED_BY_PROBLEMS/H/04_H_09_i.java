import java.util.*;
import java.io.*;
import java.math.*;

public class H_kmh {

	private static Map<Integer, Integer> yAxis, xAxis;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		List<Point> allPoints = new ArrayList<>();

		int N = Integer.parseInt(br.readLine());
		Point[] strikePoints = new Point[N];
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			strikePoints[i] = new Point(x, y, 0);

			allPoints.add(strikePoints[i]);
		}
		int M = Integer.parseInt(br.readLine());
		Point[] ballPoints = new Point[M];
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			ballPoints[i] = new Point(x, y, 1);

			allPoints.add(ballPoints[i]);
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		long C1 = Integer.parseInt(st.nextToken());
		long C2 = Integer.parseInt(st.nextToken());

		yAxis = new HashMap<>();
		xAxis = new HashMap<>();
		Collections.sort(allPoints, new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.x, o2.x);
			}
		});
		for (int i = 0; i < allPoints.size(); i++)
			xAxis.put(allPoints.get(i).x, i + 1);

		Collections.sort(allPoints, new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.y, o2.y);
			}
		});
		for (int i = 0; i < allPoints.size(); i++)
			yAxis.put(allPoints.get(i).y, i + 1);

		int[][] strikeTable = new int[allPoints.size() + 1][allPoints.size() + 1];
		int[][] ballTable = new int[allPoints.size() + 1][allPoints.size() + 1];
		for (int i = 0; i < allPoints.size(); i++) {
			Point p = allPoints.get(i);
			int yIndex = yAxis.get(p.y);
			int xIndex = xAxis.get(p.x);

			if (p.type == 0)
				strikeTable[yIndex][xIndex] = 1;
			else
				ballTable[yIndex][xIndex] = 1;
		}

		int[][] strikeDP = new int[allPoints.size() + 1][allPoints.size() + 1];
		int[][] ballDP = new int[allPoints.size() + 1][allPoints.size() + 1];
		for (int i = 1; i < strikeDP.length; i++) {
			for (int j = 1; j < strikeDP[0].length; j++) {
				strikeDP[i][j] += strikeDP[i - 1][j];
				strikeDP[i][j] += strikeDP[i][j - 1];
				strikeDP[i][j] -= strikeDP[i - 1][j - 1];
				strikeDP[i][j] += strikeTable[i][j];

				ballDP[i][j] += ballDP[i - 1][j];
				ballDP[i][j] += ballDP[i][j - 1];
				ballDP[i][j] -= ballDP[i - 1][j - 1];
				ballDP[i][j] += ballTable[i][j];
			}
		}

		long answer = 0;
		for (int i = 0; i < allPoints.size(); i++) {
			for (int j = 0; j < allPoints.size(); j++) {
				Point first = allPoints.get(i);
				Point second = allPoints.get(j);

				int sx = Math.min(first.x, second.x);
				int sy = Math.min(first.y, second.y);
				int ex = Math.max(first.x, second.x);
				int ey = Math.max(first.y, second.y);

				int sxi = xAxis.get(sx);
				int syi = yAxis.get(sy);
				int exi = xAxis.get(ex);
				int eyi = yAxis.get(ey);

				long strikeCount = strikeDP[eyi][exi] - strikeDP[syi - 1][exi] - strikeDP[eyi][sxi - 1];
				strikeCount += strikeDP[syi - 1][sxi - 1];
				long ballCount = ballDP[eyi][exi] - ballDP[syi - 1][exi] - ballDP[eyi][sxi - 1];
				ballCount += ballDP[syi - 1][sxi - 1];

				long result = C1 * strikeCount - C2 * ballCount;

				// System.out.println(strikeCount + " " + ballCount + " // " + result);

				answer = Math.max(answer, result);
			}
		}

		bw.write(String.valueOf(answer));
		bw.close();
	}

	private static class Point {
		public int x, y;
		public int type;

		public Point(int x, int y, int type) {
			this.x = x;
			this.y = y;
			this.type = type;
		}
	}
}
