import java.util.Scanner;
public class J {
	public static int[] poly=new int[1000001];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		
		poly[3]=0; poly[4]=1;
		if(N==3) {System.out.println(poly[3]);}
		else if(N==4) {System.out.println(poly[4]);}
		else {
		for(int i=5; i<=N; i++) {
			if(i%2!=0) {poly[i]=poly[i-1]+1;}
			else {poly[i]=poly[i-1];}
			}
		System.out.println(poly[N]);
		}
	}
}
