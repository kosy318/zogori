#include <cstdio>

#define MAX_N 10000

#define NUM_COL 2
#define X 0
#define L 1

void heapsort ( long long heap [ ] [ NUM_COL ] , int n ) ;
void heapswap ( long long heap [ ] [ NUM_COL ] , int a , int b ) ; 

long long binary_search ( long long heap [ ] [ NUM_COL ] , int n , long long left , long long right ) ;

long long heap [ MAX_N + 1 ] [ NUM_COL ] = { 0 } ;

int main ( void ) {
	int n = 0 ;
	scanf ( "%d" , & n );

	for ( int i = 1 ; i <= n ; i ++ ) {
		scanf ( "%lld%lld" , heap [ i ] + X , heap [ i ] + L ) ;
	}
	heapsort ( heap , n ) ;

	long long max = 0 ;
	max = ( heap [ n ] [ X ] + heap [ n ] [ L ] - heap [ 1 ] [ X ] ) / ( n - 1 ) ;

	max = binary_search ( heap , n , 0 , max + 1 ) ;

	printf("%lld", max); 

	return 0;
}
void heapsort ( long long heap [ ] [ NUM_COL ] , int n ) {
	for ( int i = 1 ; i <= n ; i ++ ) {
		for (int j = i ; j > 1 ; j /= 2 ) {
			if ( heap [ j ] [ X ] > heap [ j / 2 ] [ X ] ) {
				heapswap ( heap , j , j / 2 ) ;
			}
		}
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		heapswap ( heap , 1 , n - i + 1 ) ;
		for ( int j = 1 ; ; ) {
			int k = j * 2 ;
			if ( k > n - i ) break ;
			if ( k + 1 <= n - i && heap [ k ] [ X ] < heap [ k + 1 ] [ X ] ) k ++ ;
			if ( heap [ j ] [ X ] < heap [ k ] [ X ] ) {
				heapswap ( heap , j , k ) ;
				j = k ;
			}
			else break ;
		}
	}
	return ;
}
void heapswap ( long long heap [ ] [ NUM_COL ] , int a , int b ) {
	for ( int i = 0 ; i < NUM_COL ; i ++ ) {
		long long temp = 0 ;
		temp = heap [ a ] [ i ] ;
		heap [ a ] [ i ] = heap [ b ] [ i ] ;
		heap [ b ] [ i ] = temp ;
	}
	return ;
}
long long binary_search ( long long heap [ ] [ NUM_COL ] , int n , long long left , long long right ) {
	while ( left < right ) {
		int i = 0 ;

		long long mid = 0 ; 
		mid = ( left + right + 1 ) / 2 ;

		long long x_prev = 0 ;
		x_prev = heap [ 1 ] [ X ] ;
		for ( i = 2 ; i <= n ; i ++ ) {
			long long x_next = 0 ;
			x_next = x_prev + mid ;

			if ( heap [ i ] [ X ] + heap [ i ] [ L ] < x_next ) {
				break ;
			} else if ( x_next < heap [ i ] [ X ] ) {
				x_next = heap [ i ] [ X ] ;
			}
			x_prev = x_next ;
		}
		if ( n < i ) {
			left = mid ;
		} else {
			right = mid - 1 ;
		}
	}
printf ( "%lld %lld\n" , left , right ) ;
	return left ;
}
