import java.util.*;
import java.io.*;
import java.math.*;

public class J {
	static int solve(int n) {
		if(n==3) return 0;
		if(n==4) return 1;
		int[] arr = new int[n+1];
		arr[3] = 0;
		arr[4] = 1;
		int cnt = 2;
		int value = 2;
		for(int i=5;i<=n;) {
			for(int j=0;j<cnt && i<=n;j++) {
				arr[i] = value;
				i+=1;
			}	
			value += 1;
			for(int j=0;j<cnt && i<=n;j++) {
				arr[i] = value;
				i+=1;
			}
			value += 1;
			cnt *= 2;
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
