#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char inp[51][1024];
int c[4];
int n, m;

int main(){
	int tn, out;
	int i, j, k;
	char pr;
	
	stack< int > st;
	scanf("%d", &tn);
	while(tn--){
		scanf("%d%d", &m, &n);
		for( i = 0 ; i < m ; i++ )
			scanf("%s", inp[i]);

		out = 0;
		for( i = 0 ; i < n ; i++ ){

			c[0] = c[1] = c[2] = c[3] = 0;
			
			for( j = 0 ; j < m ; j++ ){
				if( inp[j][i] == 'A' ) c[0]++;
				if( inp[j][i] == 'G' ) c[1]++;
				if( inp[j][i] == 'T' ) c[2]++;
				if( inp[j][i] == 'C' ) c[3]++;
			}

			j = 0;
			for( k = 1 ; k < 4 ; k++ ){
				if( c[j] < c[k] ) j = k;
			}

			out += (m - c[j]);

			if( j == 0 ) pr = 'A';
			if( j == 1 ) pr = 'G';
			if( j == 2 ) pr = 'T';
			if( j == 3 ) pr = 'C';

			printf("%c", pr);

		}
		printf("\n%d\n", out);
	}
}
/*

3
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA
6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA


*/