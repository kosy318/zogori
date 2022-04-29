import java.util.*;
public class Main {
	public static int A[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n = in.nextInt();
		int ans[] = new int[n+1];
		ans[3] = 0;
		if(n>=4) ans[4] = 1;
		for(int i=5;i<=n;i++) {
			int inside = (i+1)/2;
			ans[i] = ans[inside]+2;
		}
		System.out.println(ans[n]);
	}
}
