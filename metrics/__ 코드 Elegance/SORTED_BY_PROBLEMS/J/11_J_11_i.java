import java.util.*;

public class J_2 {
	static int[] DP = new int[10000001];
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		
		int tmp = 2, cnt = 1;
		for(int i=3; i<1000001; i = i+tmp) {
			for(int j=i; j<i+tmp; j++) {
				DP[j] = cnt;
			}
			cnt++;
			for(int j=i+tmp; j<i+tmp+tmp; j++) {
				DP[j] = cnt;
			}
			cnt++;
			tmp *= 2;	
		}
		DP[3] = 0;
		
		System.out.println(DP[N]);
	}
}
