import java.util.*;
public class Main {
	static int n,m;
	static ArrayList<ArrayList> mine;
	static int type[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		m =in.nextInt();
		n= in.nextInt();
		type = new int[m];
		for(int i=0;i<m;i++) type[i] = in.nextInt();
		Comparator Mycomparator = new MyComparator();
		mine = new ArrayList<>();
		for(int i=0; i<n;i++) {
			ArrayList<Integer> a = new ArrayList<Integer>();
			a.add(in.nextInt());
			a.add(in.nextInt());
			a.add(in.nextInt());			
			mine.add(a);
		}
		mine.sort(Mycomparator);
		
		System.out.println(recursive(0, 0, (int)mine.get(0).get(1)));
	}
	
	static public int recursive(int idx, int start_after, int end) {
		if(idx==n) return 0;
		if(idx+1 == n) return ((int)mine.get(idx).get(1)-(int)mine.get(idx).get(0))*type[(int)mine.get(idx).get(2)-1];
		int max = 0;
		
		for(int i=idx;i<n&&(int)mine.get(i).get(0)<end;i++) {
			if((int)mine.get(i).get(0)<start_after) continue;
			if(i+1== n) max =Math.max(max, ((int)mine.get(i).get(1)-(int)mine.get(i).get(0))*type[(int)mine.get(i).get(2)-1]);
			else max=Math.max(max, recursive(i+1, (int)mine.get(i).get(1), (int)mine.get(i+1).get(1)) + ((int)mine.get(i).get(1)-(int)mine.get(i).get(0))*type[(int)mine.get(i).get(2)-1]);
		}
		return max;
	}
}

class MyComparator implements Comparator<ArrayList<Integer>>{
	@Override
	public int compare(ArrayList o1, ArrayList o2) {
		if((int)o1.get(0)>(int)o2.get(0))
			return 1;
		else if((int)o1.get(0)==(int)o2.get(0)){
			if((int)o1.get(1)>(int)o2.get(1))
				return 1;
			else return -1;
		}
		else return -1;
	}
	
}