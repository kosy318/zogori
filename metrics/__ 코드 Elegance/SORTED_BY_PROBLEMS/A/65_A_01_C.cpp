#include <cstdio>

#define MAX_N 1000

using namespace std;

int main ( void ) {
	int i = 0 ;

	int A [ MAX_N + 1 ] = { 0 } ;

	A [ 0 ] = 1 ;
	A [ 1 ] = 1 ;

	int B [ MAX_N + 1 ] [ MAX_N + 1 ] = { 0 } ;

	int n = 0 ;
	scanf ( "%d" , & n ) ;

	for ( i = 2 ; i <= n ; i ++ ) {
		int j = 0 ;

		for ( j = 1 ; ; j ++ ) {
			int i_minus_j = 0 ;
			i_minus_j = i - j ;

			int i_minus_2j = 0 ;
			i_minus_2j = i_minus_j - j ;

			if ( i_minus_2j < 0 ) {
				break ;
			}
			int prev_sum = 0 ;
			prev_sum = A [ i_minus_j ] - A [ i_minus_2j ] ;

			B [ i ] [ A [ i_minus_j ] + prev_sum ] = 1 ;
		}
		for ( j = 1 ; j <= MAX_N ; j ++ ) {
			if ( ! B [ i ] [ j ] ) {
				A [ i ] = j ;
				break ;
			}
		}
	}
	printf ( "%d" , A [ n ] ) ;

	return 0 ;
}
