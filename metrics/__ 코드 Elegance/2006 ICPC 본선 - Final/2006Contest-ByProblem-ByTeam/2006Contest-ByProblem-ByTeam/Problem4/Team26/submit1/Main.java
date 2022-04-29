// team26i
// Prob. D

import java.io.*;
import java.util.*;

public class Main {
	private int count = 0;
	private int sid;
	private int map[][];
	private int citynum;
	

	
	public Main() throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
//		BufferedReader br = new BufferedReader( new FileReader("test.txt"));
		int cas = Integer.parseInt(br.readLine());
		while (cas > 0 ){
			StringTokenizer stk = new StringTokenizer(br.readLine());
			citynum = Integer.parseInt(stk.nextToken())+1;
			int edge = Integer.parseInt(stk.nextToken());
			map = new int[citynum][citynum];
			int mustcity[] = new int[4];
			int mustcount = 0;
			count = 0;
			for(int i = 0 ; i < edge; i++){
				stk = new StringTokenizer(br.readLine());
				int ci1 = Integer.parseInt(stk.nextToken());
				int ci2 = Integer.parseInt(stk.nextToken());
				map[ci1][ci2] = 1;
				map[ci2][ci1] = 1;				
			}
			for(int i = 0 ; i < 2; i++){
				stk = new StringTokenizer(br.readLine());
				int ci1 = Integer.parseInt(stk.nextToken());
				int ci2 = Integer.parseInt(stk.nextToken());
				map[ci1][ci2] = 10;
				map[ci2][ci1] = 10;
				boolean c1al = false;
				boolean c2al = false;
				for(int j = 0 ; j < mustcount; j++){
					if(ci1 == mustcity[j]) c1al = true;
					if(ci2 == mustcity[j]) c2al = true;					
				}
				if(!c1al) mustcity[mustcount++] = ci1;
				if(!c2al) mustcity[mustcount++] = ci2;				
			}
			int tollnum = Integer.parseInt(br.readLine());
			for(int i = 0 ; i < tollnum; i++){
				stk = new StringTokenizer(br.readLine());
				int ci1 = Integer.parseInt(stk.nextToken());
				int ci2 = Integer.parseInt(stk.nextToken());				
				map[ci2][ci1] = 0;
				map[ci1][ci2] = 0;
			}
			
			boolean istrue = false;
			for(int i = 0 ; i < mustcount; i++){
				int tempmap[][] = new int[citynum][citynum];
				for(int p = 1 ; p < citynum; p++){
					for(int o = 1; o < citynum; o++){
						tempmap[p][o] = map[p][o]; 
					}
				}
				count = 0;
				sid = mustcity[i];
				if(DFS(mustcity[i]) && count == 2) {
					istrue = true;
					break;
				}
				else count = 0;
				map = tempmap;
			}
			if(istrue) System.out.println("YES");
			else System.out.println("NO");		
			
			
			cas--;
		}
	}
	private boolean DFS(int start){
		int tempmap[][] = new int[citynum][citynum];		
		for(int p = 1 ; p < citynum; p++){
			for(int o = 1; o < citynum; o++){
				tempmap[p][o] = map[p][o]; 
			}
		}
		boolean isDFS = false; 
		if(map[start][sid] == 5 && count == 1) {
			count++;
			map = tempmap;
			return true;
		}
		else if(map[start][sid] == 1 && count==2) {
			map = tempmap;
			return true;
		}
		
		
		for(int i = 1 ; i < citynum; i++){
			if(i == sid) {
				if(map[start][sid] != 0 && count == 2) return true;
			}
			else{
				if(map[start][i] == 10) {
					tempmap = new int[citynum][citynum];
					for(int p = 1 ; p < citynum; p++){
						for(int o = 1; o < citynum; o++){
							tempmap[p][o] = map[p][o]; 
						}
					}
					count++;
					for(int j = 1 ; j < citynum; j++){
						if(start != sid) map[j][start] = 0;
						
					}
					
					if(DFS(i)) isDFS = true;
					else count--;
					map = tempmap;
				}
				else if(map[start][i] == 1){
					tempmap = new int[citynum][citynum];
					for(int p = 1 ; p < citynum; p++){
						for(int o = 1; o < citynum; o++){
							tempmap[p][o] = map[p][o]; 
						}
					}
					for(int j = 1 ; j < citynum; j++){
						if(start != sid) map[j][start] = 0;
						if(start == sid &&  map[start][i] == 10) map[start][i] = 5;
						
					}
					if(DFS(i)) isDFS = true;
					map = tempmap;
				}
				
			}
			
		}		
		return isDFS;
		
				
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

}
