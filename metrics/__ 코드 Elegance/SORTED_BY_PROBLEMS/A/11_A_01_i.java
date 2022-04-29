
import java.util.Scanner;
public class Asj {
	public static int[] A=new int[100001];
	public static boolean[] a=new boolean[1000001];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		for(int i=0; i<=N; i++) {
			a=new boolean[10000001];
			if(i==0||i==1||i==3) A[i]=1;
			else if(i==2)A[i]=2;
			else {
				for(int j=1; j<=i/2; j++) {
				A[i]=2*A[i-j]-A[i-2*j];
				if(A[i]>=0) {a[A[i]]=true;}
				else {a[0]=true;}
				}
				for(int h=1; h<10000001; h++) {
					if(a[h]==false) {A[i]=h;break;}
				}
			}
	
		}
		System.out.println(A[N]);
	}

}
