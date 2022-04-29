import java.util.*;

public class J_2 {
	static int[] DP = new int[10000001];
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		
		int tmp = 0;
		int cnt = 1;
		for(int i=3; i<1000001; i = i*2) {
			tmp = i/3;
			
			for(int j=i+1; j<=i+tmp; j++) {
				DP[j] = cnt;
			}
			cnt++;
			
			for(int j=i+tmp+1; j<=i*2; j++) {
				DP[j] = cnt;
			}
			cnt++;
		}
		
		System.out.println(DP[N]);
	}
}
