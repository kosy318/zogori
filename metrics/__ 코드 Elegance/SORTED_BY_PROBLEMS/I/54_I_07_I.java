import java.util.*;
public class Main2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int arr[]=new int[n];
		LinkedList<Input> list=new LinkedList<Input>();
		for(int i=0;i<n;i++) {
			int left=in.nextInt();
			int right=in.nextInt();
			list.add(new Input(left,left+right));
		}
		Collections.sort(list);
		arr[0]=list.get(0).left;
		arr[n-1]=list.get(n-1).right;
		int ans=(int) Math.ceil((arr[n-1]-arr[0])/(double)(n-1));
		int max=Integer.MAX_VALUE;
		for(int i=1;i<n-1;i++) {
			if(list.get(i).left>=arr[i-1]+ans) {
				arr[i]=list.get(i).left;
				ans=(int) Math.ceil((arr[n-1]-arr[i])/(double)(n-i-1));
			}
			else {
				if(list.get(i).left<=arr[i-1]+ans&&arr[i-1]+ans<=list.get(i).right) {
					arr[i]=arr[i-1]+ans;
				}
				else {
					arr[i]=list.get(i).right;
					ans=(int) Math.ceil((arr[n-1]-arr[i])/(double)(n-i-1));
				}
			}
			max=Math.min(max, arr[i]-arr[i-1]);
		}
		System.out.println(max);
	}
}
class Input implements Comparable<Input>{
	int left,right;
	public Input(int left, int right) {
		this.left=left;
		this.right=right;
	}
	@Override
	public int compareTo(Input o) {
		if(this.left>o.left)
			return 1;
		else return -1;
	}
}