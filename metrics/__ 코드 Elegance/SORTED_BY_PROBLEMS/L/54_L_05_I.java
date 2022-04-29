import java.util.*;
public class Main {
	static int n,m;
	static int mine[][];
	static int type[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		m =in.nextInt();
		n= in.nextInt();
		type = new int[m];
		for(int i=0;i<m;i++) type[i] = in.nextInt();
		
		mine= new int[n][3];
		for(int i=0; i<n;i++) {
			mine[i][0] = in.nextInt();
			mine[i][1] = in.nextInt();
			mine[i][2] = in.nextInt();
		}
		System.out.println(recursive(0, 0, mine[0][1]));
	}
	
	static public int recursive(int idx, int start_after, int end) {
		if(idx==n) return 0;
		if(idx+1 == n) return mine[idx][1]-mine[idx][0]*type[mine[idx][2]-1];
		int max = 0;
		
		for(int i=idx;i<n&&mine[i][0]<end;i++) {
			if(mine[i][0]<start_after) continue;
			if(i+1== n) max =Math.max(max, mine[i][1]-mine[i][0]*type[mine[i][2]-1]);
			else max=Math.max(max, recursive(i+1, mine[i][1], mine[i+1][1]) + (mine[i][1]-mine[i][0])*type[mine[i][2]-1]);
		}
		return max;
	}
}
