// team26
// Prob. F

import java.io.*;
import java.util.*;

public class Main {
	
	public Main() throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
//		BufferedReader br = new BufferedReader( new FileReader("test.txt"));
		int cas = Integer.parseInt(br.readLine());
		while(cas  > 0){
			int tubenum = Integer.parseInt(br.readLine());
			int e[] = new int[tubenum];
			int c[] = new int[tubenum];
			StringTokenizer stk = new StringTokenizer(br.readLine());
			int max = 0;
			int M = Integer.parseInt(br.readLine());			
			for(int i = 0; i < tubenum; i++){
				e[i] = Integer.parseInt(stk.nextToken());
				c[i] = Integer.parseInt(stk.nextToken());
				if(max < e[i]*M + c[i]) max = e[i]*M + c[i]; 
				
			}
			
			int j;
			for(j = 1; ; j++){
				double sum = 0;
				for(int i = 0 ; i < tubenum; i++){
					if(j-c[i] < 1) continue;
					sum += (j-c[i])/(double)e[i];				
				}
				
				if(sum == M) break;
				if(j > max) {
					j = 0;
					break;
				}
			}			
			System.out.println(j);			
			
			cas--;
		}
		
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

}
