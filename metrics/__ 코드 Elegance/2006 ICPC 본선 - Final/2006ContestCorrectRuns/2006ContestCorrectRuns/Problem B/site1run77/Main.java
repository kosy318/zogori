// team26
// Prob. B

import java.io.*;
import java.util.*;

public class Main {
	
	public Main() throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
//		BufferedReader br = new BufferedReader( new FileReader("test.txt"));
		int cases = Integer.parseInt( br.readLine().trim() );
		while( cases > 0 ) {
			int num, len;
			StringTokenizer st = new StringTokenizer( br.readLine() );
			num = Integer.parseInt( st.nextToken() );
			len = Integer.parseInt( st.nextToken() );
			char [][] dna = new char[num][len];
			for (int i = 0; i < num; i++) {
				dna[i] = br.readLine().toCharArray();
			}
			char [] result = new char[ len ];
			for (int i = 0; i < len; i++) {
				int [] count = new int[26];
				for (int j = 0; j < num; j++) {
					count[ dna[j][i] - 'A' ]++;
				}
				int max = 0;
				for (int j = 1; j < count.length; j++) {
					if( count[max] < count[j] ) max = j;
				}
				result[i] = (char)('A' + max);
			}
			for (int i = 0; i < result.length; i++) {
				System.out.print( result[i] );
			}
			System.out.println();
			int diff = 0;
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < len; j++) {
					if( dna[i][j] != result[j] ) diff++;
				}
			}
			System.out.println( diff );
			cases--;
		}
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

}
