#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char inp[1024][51];
int c[1024][4];
int d[1024][4];
int p[1024][4];
int n, m;

int main(){
	int tn;
	int i, j, k;
	stack< int > st;
	scanf("%d", &tn);
	while(tn--){
		memset( c, 0, sizeof(c) );
		memset( d, 0, sizeof(d) );
		memset( p, 0, sizeof(p) );
		scanf("%d%d", &m, &n);
		for( i = 0 ; i < m ; i++ )
			scanf("%s", inp[i]);

		for( i = 0 ; i < n ; i++ ){
			for( j = 0 ; j < m ; j++ ){
				switch( inp[j][i] ){
					case 'A':
						inp[j][i] = 0;
						break;
					case 'G':
						inp[j][i] = 1;
						break;
					case 'C':
						inp[j][i] = 2;
						break;
					case 'T':
						inp[j][i] = 3;
						break;

				}
			}
		}
		for( i = 0 ; i < n ; i++ ){
			for( k = 0 ; k < 4 ; k++ ){
				c[i][k] = 0;
				for( j  = 0 ; j < m ; j++ ){
					if( inp[j][i] != k ){
						c[i][k]++;
					}
				}
			}
		}
		memset( d, 0, sizeof(d) );

		for( i = 1 ; i < n ; i++ )
			for( j  = 0 ; j < m ; j++ )
				d[i][j] = 999999999;


		p[0][0] = 0;
		p[0][1] = 1;
		p[0][2] = 2;
		p[0][3] = 3;

		d[0][0] = c[0][0];
		d[0][1] = c[0][1];
		d[0][2] = c[0][2];
		d[0][3] = c[0][3];



		for( i = 1 ; i < n ; i++ ){
			for( j  = 0 ; j < 4 ; j++ ){
				for( k = 0 ; k < 4 ; k++ ){
					if( d[i][j] > d[i-1][k] + c[i][j] ){
						d[i][j] = d[i-1][k] + c[i][j];
						p[i][j] = k;
					}
				}
			}
		}

		while( !st.empty() ) st.pop();

		k = 999999999;
        for( i = 0 ; i < 4 ; i++ ){
			if( d[n-1][i] < k ){
				k = d[n-1][i];
				j = i;
			}
		}

		
		i = n-1;
		st.push( j );
		while( i != 0 ){
			j = p[i][j];
			i--;
			st.push( j );
		}
		

		j = k;

		while( !st.empty() ){
			k = st.top();
			st.pop();
			if( k == 0 )
				printf("A");
			if( k == 1 )
				printf("G");
			if( k == 2 )
				printf("C");
			if( k == 3 )
				printf("T");
		}
		printf("\n%d\n", j);

		
		

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