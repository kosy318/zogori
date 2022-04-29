#include <cstdio>
#include <algorithm>

#define MAX_N 10000
#define NUM_COL 3
#define IDX_END 1

int heap [ MAX_N ] [ NUM_COL ] = { 0 } ;
long long get_max(long long a, long long b) { return a > b ? a: b; }
void swap ( int heap [ ] [ NUM_COL ] , int a , int b ) ; 

int main ( void ) {
	int n = 0 ;
	int m = 0 ;
	int j = 0 ;
	int i = 0; 
	scanf ( "%d %d" , & m , & n );
	int type[m];

	for (i = 0; i < m; i++) scanf("%d", &type[i]);

	for ( int i = 1 ; i <= n ; i ++ ) {
		for (j = 0; j < 3; j++) scanf ( "%d" , & ( heap [ i ] [ j ] ) ) ;

		for (j = i ; j > 1 ; j /= 2 ) {
			if ( heap [ j ] [ IDX_END ] > heap [ j / 2 ] [ IDX_END ] ) {
				swap ( heap , j , j / 2 ) ;
			}
		}
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		swap ( heap , 1 , n - i + 1 ) ;
		for ( int j = 1 ; ; ) {
			int k = j * 2 ;
			if ( k > n - i ) break ;
			if ( k + 1 <= n - i && heap [ k ] [ IDX_END ] < heap [ k + 1 ] [ IDX_END ] ) k ++ ;
			if ( heap [ j ] [ IDX_END ] < heap [ k ] [ IDX_END ] ) {
				swap ( heap , j , k ) ;
				j = k ;
			}
			else break ;
		}
	}
/*	
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) { 
			printf("%d ", heap[i][j]);
		}
		printf("\n");
	}
*/
/*
	j = 1;
	int dplen = heap[n][1];
	long long dp[15001] = { 0, };
	for (i = heap[1][1]; i <= heap[n][1]; i++) {
		printf("i : %d, heap[%d][1] : %d\n", i, j, heap[j][1]);
		if (i != heap[j][1] ) { 
			dp[i] = dp[i-1];
		}
		else {
			int day = heap[j][1] - heap[j][0];
			long long price = (day*type[heap[j][2]-1]) + dp[heap[j][0]];
			printf("price : %lld\n", price);
			dp[i] = get_max(price, dp[i-1]);
			j++;
		}
	}
*/
	long long dp[15000] = { 0, };

	
	for (i = 1; i <= n; i++) {
		for (j = heap[i-1][1] + 1; j < heap[i][1]; j++) {
			dp[j] = dp[j-1];
		}
		int day = heap[i][1] - heap[i][0];
		long long price = ((long long )day * type[heap[i][2]-1]) + dp[heap[i][0]];
		dp[heap[i][1]] = get_max(dp[heap[i][1]-1], price);
	}

	//for (i = 1; i <= heap[n][1]; i++) printf("%lld ", dp[i]);
	printf("%lld\n", dp[heap[n][1]]); 
	return 0;
}
void swap ( int heap [ ] [ NUM_COL ] , int a , int b ) {
	for ( int i = 0 ; i < NUM_COL ; i ++ ) {
		int temp = 0 ;
		temp = heap [ a ] [ i ] ;
		heap [ a ] [ i ] = heap [ b ] [ i ] ;
		heap [ b ] [ i ] = temp ;
	}
	return ;
}
