import java.util.*;
import java.io.*;
import java.math.*;

public class H_2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		Point[] strikePoints = new Point[N];
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			strikePoints[i] = new Point(x,y,1,0);
		}
		int M = Integer.parseInt(br.readLine());
		Point[] ballPoints = new Point[M];
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			ballPoints[i] = new Point(x, y, 0, 1);
		}
		
		Point[] allPoints = new Point[N + M];
		for (int i = 0; i < N; i++) {
			allPoints[i] = strikePoints[i];
		}
		for (int i = 0; i < M; i++) {
			allPoints[i + N] = ballPoints[i];
		}
		Arrays.sort(allPoints);
		
		// accumulate
		// 0:# of Strike, 1:# of Ball 
		int[][] accumulate = new int[allPoints.length][2]; 
		accumulate[0][0] = allPoints[0].strike;
		accumulate[0][1] = allPoints[1].ball;
		
		for(int i=1; i<allPoints.length; i++) {
			accumulate[i][0] = accumulate[i-1][0] + allPoints[i].strike; 
			accumulate[i][1] = accumulate[i-1][1] + allPoints[i].ball;
		}
		
		// check all
		StringTokenizer st = new StringTokenizer(br.readLine());
		long C1 = Long.parseLong(st.nextToken());
		long C2 = Long.parseLong(st.nextToken());
		
		long maxValue = Long.MIN_VALUE;
		for (int i = 0; i < allPoints.length; i++) {
			int i_Strike = 1;
			int i_Ball = 0;
			
			if(allPoints[i].strike==0) { 
				i_Strike = 0;
				i_Ball = 1;
			}
			
			for (int j = i; j < allPoints.length; j++) {
				long numOfStrike = i_Strike+accumulate[j][0]-accumulate[i][0];
				long numOfBall = i_Ball+accumulate[j][1]-accumulate[i][0];
				
				long evaluate = C1*numOfStrike - C2*numOfBall;
				maxValue = Math.max(maxValue,evaluate);
			}
		}
		System.out.print(maxValue);
		
		bw.close();
	}

	private static class Point implements Comparable<Point> {
		public int x, y, strike, ball;

		public Point(int x, int y, int strike, int ball) {
			this.x = x;
			this.y = y;
			this.strike = strike;
			this.ball = ball;
		}
		public int compareTo(Point p) {
			return p.y - this.y;
		}
	}
}
