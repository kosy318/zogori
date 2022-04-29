import java.util.*;
import java.io.*;
public class Main2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(bf.readLine());
		int arr[]=new int[n];
		String s; StringTokenizer st;
		ArrayList<Input> list=new ArrayList<Input>();
		for(int i=0;i<n;i++) {
			s=bf.readLine();
			st=new StringTokenizer(s);
			list.add(new Input(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
		}
		Collections.sort(list);

		arr[0]=list.get(0).left;
		arr[n-1]=list.get(n-1).right;
		int ans=(int)Math.ceil((arr[n-1]-arr[0])/(double)(n-1));
		int max=ans;
		int max2=ans;
		for(int i=1;i<n-1;i++) {
			if(list.get(i).left>=arr[i-1]+ans) {
				arr[i]=list.get(i).left;
				ans=(int)Math.ceil((arr[n-1]-arr[i])/(double)(n-i-1));
			}
			else if(arr[i-1]+ans>=list.get(i).right) {
				arr[i]=list.get(i).right;
				ans=(int)Math.ceil((arr[n-1]-arr[i])/(double)(n-i-1));
			}
			else
				arr[i]=arr[i-1]+ans;

			max=Math.min(max, arr[i]-arr[i-1]);
		}
		ans=max+1;
		int ansans=max;
		while(true) {
			max2=Integer.MAX_VALUE;
			for(int i=1;i<n-1;i++) {
				if(list.get(i).left>=arr[i-1]+ans) {
					arr[i]=list.get(i).left;
				}
				else if(arr[i-1]+ans>=list.get(i).right) {
					arr[i]=list.get(i).right;
				}
				else
					arr[i]=arr[i-1]+ans;

				max2=Math.min(max, arr[i]-arr[i-1]);
			}
			ansans=Math.max(max2, ansans);
			if(max2<=max) break;
			ans++;
		}
		System.out.println(ansans);
	}
}
class Input implements Comparable<Input>{
	int left,right;
	public Input(int left, int right) {
		this.left=left;
		this.right=right+left;
	}
	@Override
	public int compareTo(Input o) {
		if(this.left>o.left)
			return 1;
		else return -1;
	}
}