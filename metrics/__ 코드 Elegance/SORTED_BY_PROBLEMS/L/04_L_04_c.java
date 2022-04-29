import java.util.*;
import java.io.*;
import java.math.*;

public class L {
	static class Ore implements Comparable<Ore>{
		int s,e,t;
		Ore(int s, int e, int t){
			this.s = s;
			this.e = e;
			this.t = t;
		}
		public int compareTo(Ore o) {
			return this.s - o.s;
		}
	}
	
	static int[] segtree;
	static int H;
	
	static int getMax(int l, int r, int i, int L, int R) {
		if (r < L || R < l)
			return 0;
		if (L <= l && r <= R)
			return segtree[i];
		
		int mid = (l + r) / 2;
		return Math.max(getMax(l, mid, i * 2, L, R), getMax(mid + 1, r, i * 2 + 1, L, R));
	}
	
	static void update(int e, int value) {
		int i = e + H;
		segtree[i] = value;
		
		while (i > 0) {
			i /= 2;
			segtree[i] = Math.max(segtree[i * 2], segtree[i * 2 + 1]);
		}
	}
	
	
	static int solve(int m, int n, int[] prices, Ore[] arr) {
		Arrays.sort(arr);
		int[] dp = new int[15002];
		
		H = 1 << (int) Math.ceil(Math.log(15002) / Math.log(2));
		segtree = new int[H * 2];
		
		for(int i=0;i<n;i++) {
			int s = arr[i].s;
			int e = arr[i].e;
			int t = arr[i].t;
			//max value of 0~s range of dp
			//int max = 0;
			//dp[e] = max + (e-s) * prices[t];
			
			int max = getMax(1, H, 1, 1, s+1);
			int result = max + (e-s) * prices[t];
			//System.out.println(max + " " + result + " " + getMax(0, H, 1, e+1, e+1) + " " + e);

			
			if (getMax(0, H, 1, e+1, e+1) < result)
				update(e, max + (e-s) * prices[t]);
			
			//System.out.println(Arrays.toString(segtree));
		}
		//int ret = 0;
		//for(int i=0;i<15001;i++)
		//	ret = Math.max(ret, dp[i]);
		
		int ret = 0;
		for (int i = H; i < segtree.length; i++)
			ret = Math.max(segtree[i], ret);
		
		return ret;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int[] prices = new int[m];
		for(int i=0;i<m;i++)
			prices[i] = Integer.parseInt(br.readLine());
		Ore[] arr = new Ore[n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken())-1;
			arr[i] = new Ore(s,e,t);
		}
		int ret = solve(m,n,prices,arr);
		bw.write(Integer.toString(ret));
		bw.close();
	}
}
