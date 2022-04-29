// team26
// Prob. A

import java.io.*;
import java.util.*;

public class Main {
	
	private class Clock {
		
		public int h, m, s;
		
		public Clock( String data ) {
			StringTokenizer st = new StringTokenizer( data, ":" );
			h = Integer.parseInt( st.nextToken() );
			m = Integer.parseInt( st.nextToken() );
			s = Integer.parseInt( st.nextToken() );
		}
		
		public int getNext() {
			String temp = h + "" + ( m < 10 ? "0" + m : m ) + "" + ( s < 10 ? "0" + s : s );
			s++;
			if( s == 60 ) {
				m++;
				s = 0;
			}
			if( m == 60 ) {
				h++;
				m = 0;
			}
			if( h == 24 ) {
				h = 0;
			}
			return Integer.parseInt( temp );
		}
	}
	
	public Main() throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
//		BufferedReader br = new BufferedReader( new FileReader("test.txt"));
		int cases = Integer.parseInt( br.readLine().trim() );
		while( cases > 0 ) {
			StringTokenizer st = new StringTokenizer( br.readLine());
			Clock first = new Clock( st.nextToken() );
			Clock second = new Clock( st.nextToken() );
			second.getNext();
			int start = first.getNext(), limit = second.getNext();
			int count = 0;
/*			if( start == limit ) {
				if( start % 3 == 0 ) count++;
				start = first.getNext();
			} else limit = second.getNext();
*/			while( start != limit) {
				if( start % 3 == 0 ) count++;
				start = first.getNext();
			}
/*			while( start != limit) {
//				if( start % 3 == 0 ) count++;
				count++;
				start = first.getNext();
			}*/
			System.out.println( count );
			cases--;
		}
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

}
