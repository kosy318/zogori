import java.util.*;
public class Main {
	public static int A[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		A=new int[1001];
		A[0]=1; A[1]=1; A[2]=2; A[3]=1; A[4]=1;
		A[5]=2; A[6]=2; A[7]=4; A[8]=4;
		for(int i=9;i<=n;i++) {
			A[i]=func(i);
		}
		System.out.println(A[n]);
	}
	public static int func(int n) {
		int ans[]=new int[1001];
		for(int i=1;n-2*i>=0;i++) {
			if(2*A[n-i]-A[n-2*i]>=0)
				ans[2*A[n-i]-A[n-2*i]]=1;
		}
		for(int i=1;i<=1000;i++) {
			if(ans[i]==0) return i;
		}
		return -1;
	}
}
