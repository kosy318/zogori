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
	static int cache[] = new int[10100];
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
		int ans = 0;
		
		for(int i=n-1;i>=0;i--) {
			int end = Integer.MAX_VALUE;
			int start_after = (int)mine.get(i).get(1);
			int max = 0;
			boolean first = true;
			for(int j=i+1; j<n && (int)mine.get(j).get(0)<end; j++) {
				if((int)mine.get(j).get(0)<start_after)continue;
				if(first) {
					first=false;
					end = (int)mine.get(j).get(1);
				}
				max = Math.max(max, cache[j]);
			}
			cache[i] = max + (int)mine.get(i).get(3);
			ans= Math.max(ans, cache[i]);
		}
		System.out.println(ans);
		
	}
	
	/*static public int recursive(int idx, int start_after) {
		if(idx>=n)return 0;
		if(cache[idx]!= 0) return cache[idx];
		int end=Integer.MAX_VALUE;
		boolean first = true;
		int max = 0;
		
		for(int i=0; i<n && (int)mine.get(i).get(0) < end; i++) {
			if((int)mine.get(i).get(0)<start_after)continue;
			if(first) {
				end = (int)mine.get(i).get(1);
				first = false;
			}
			max=Math.max(max, (int)mine.get(i).get(3) + recursive(i+1, (int)mine.get(i).get(1)));
		}
		cache[idx] = max;
		//for(int i=0;i<=n;i++) System.out.print(cache[i]+" ");
		//System.out.println();
		return max;
5 7
1
2
3
4
5
1 5 2
3 8 1
2 4 3
3 9 2
4 10 5
7 11 4
5 7 3
	}*/
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