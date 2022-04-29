import java.util.*;
import java.io.*;
import java.math.*;

public class Template {
	static int solve(int n) {
		if(n<2) return 1;
		int[] arr = new int[n+1];
		arr[0] = 1;
		arr[1] = 1;
		
		for(int i=2;i<=n;i++) {
			boolean[] cand = new boolean[2*i];
			//Arrays.fill(cand, true);
			//ArrayList<Integer> list = new ArrayList<Integer>()
			for(int k=1;i-2*k >= 0;k++) {
				int not = 2*arr[i-k]-arr[i-2*k];
				
				if(not<=0) continue;
				//System.out.println(" "+not);
				cand[not] = true;
			}

			//System.out.println(Arrays.toString(cand));
			for(int k=1;k<i+1;k++) 
				if(!cand[k]) {
					arr[i] = k;
					break;
				}
		}
		//System.out.println(Arrays.toString(arr));
		return arr[n];
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int ret = solve(n);
		bw.write(Integer.toString(ret));
		bw.close();
	}
}
