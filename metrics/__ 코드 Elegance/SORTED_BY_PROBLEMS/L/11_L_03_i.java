import java.io.*;
import java.util.*;

class Work implements Comparable<Work>{
	int s, e, t, v;
	Work(int ss, int ee, int tt){
		s = ss; e = ee; t = tt; v = (e-s)*t;
	}
	public int compareTo(Work w) {
		return this.v - w.v;
	}
}
public class L {
	static int M, N, endTime;
	static int[] Price;
	static ArrayList<Work> work = new ArrayList<>();
	static int[][] K;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		Price = new int[M+1];
		
		for(int i=1; i<M+1; i++) {
			Price[i] = Integer.parseInt(br.readLine());
		}
		work.add(new Work(0, 0, 0));
		int s, e, t;
		for(int i=1; i<N+1; i++) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			work.add(new Work(s, e, Price[t]));
			endTime = Math.max(e, endTime);
		}
		
		
		K = new int[N+1][endTime+1];
		
		Collections.sort(work);
		Work tmp;
		
		
		
		for(int i=1; i<N+1; i++) {
			for(int j=1; j<endTime+1; j++) {
				tmp = work.get(i);
				if(tmp.e > j) K[i][j] = K[i-1][j];
				else K[i][j] = Math.max(tmp.v + K[i-1][tmp.s], K[i-1][j]);
			}
		}
		System.out.println(K[N][endTime]);

	}

}
