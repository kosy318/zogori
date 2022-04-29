
import java.util.Scanner;
public class Asj {
	public static int[] A=new int[100001];
	public static boolean[] a=new boolean[1001];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		if(N==0||N==1||N==3) A[N]=1;
		if(N==2)A[N]=2;
		else {
		for(int i=4; i<=N; i++) {
			A[0]=1;A[1]=1;A[2]=2;A[3]=1;
			a=new boolean[1001];
				for(int j=1; j<=i/2; j++) {
				A[i]=2*A[i-j]-A[i-2*j];
				if(A[i]>=0) {a[A[i]]=true;}
				else {a[0]=true;}
				}
				for(int h=1; h<1001; h++) {
					if(a[h]==false) {A[i]=h;break;}
				}

		}}
		System.out.println(A[N]);
	}

}
