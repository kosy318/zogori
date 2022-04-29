import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;
public class fuckingL {
	static int n,m;
	static ArrayList<ArrayList> mine;
	static int type[];
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		m =Integer.parseInt(st.nextToken());
		n= Integer.parseInt(st.nextToken());
		type = new int[m];
		for(int i=0;i<m;i++) {
			type[i] = Integer.parseInt(br.readLine());
		}
		Comparator Mycomparator = new MyComparator();
		mine = new ArrayList<>();
		for(int i=0; i<n;i++) {
			st = new StringTokenizer(br.readLine());
			ArrayList<Integer> a = new ArrayList<Integer>();
			a.add(Integer.parseInt(st.nextToken()));
			a.add(Integer.parseInt(st.nextToken()));
			a.add(Integer.parseInt(st.nextToken()));
			a.add((a.get(1)-a.get(0))*type[a.get(2)-1]);
			mine.add(a);
		}
		mine.sort(Mycomparator);
		
		System.out.println(recursive(0, 0));
	}
	
	static public int recursive(int idx, int start_after) {
		if(idx>=n)return 0;
		int end=Integer.MAX_VALUE;
		boolean first = true;
		int max = 0;
		
		for(int i=0; i<n && (int)mine.get(i).get(0) < end; i++) {
			if((int)mine.get(i).get(0)<start_after)continue;
			if(first) {
				end = (int)mine.get(i).get(1);
				first = false;
			}
			max=Math.max(max, (int)mine.get(i).get(3)+recursive(idx+1, (int)mine.get(i).get(1)));
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