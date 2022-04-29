#include <iostream>

using namespace std; 

int main(void){

	int T;
	int height, width;
	int n, x, y, x1, x2, y1, y2;
	int xt, yt, end;
	int sum1, sum2;

	cin >> T;

	while( T-- ) {
		xt = yt = 0;
		sum1 = sum2 = 0;

		cin >> width >> height;

		int** M = new int*[height];
		int** M2 = new int*[height];

		for( int i = 0; i < height; i++ ) {
			M[i] = new int[width];
			M2[i] = new int[width];

			for( int k = 0; k < width; k++ ) M[i][k] = M2[i][k] = 0;
		}

		cin >> n;

		for( int i = 0; i < n; i++ ) {
			x1 = y1 = 1;
			x2 = y2 = 0;
			cin >> x >> y;

			if( x == 0 ) x1 = 0;
			if( y == 0 ) y1 = 0;
			if( x == width ) x2 = 1;
			if( y == height ) y2 = 1;

			M[y-y1][x-x2] = M[y-y2][x-x2] = M[y-y1][x-x1] = M[y-y2][x-x1] = 1;
			M2[y-y1][x-x2] = M2[y-y2][x-x2] = M2[y-y1][x-x1] = M2[y-y2][x-x1] = 1;

			xt += x, yt+=y;
		}

		xt = (int)((float)xt/(float)n + .5f) - 1, yt = (int)((float)yt/(float)n + .5f) - 1;

		for( int i = 0; i < width; i++ ) M[xt][i] = 1;
		for( int i = 0; i < height; i++ ) M2[i][yt] = 1;
		
		for( int i = 0 ; i < height; i++ ) {
			end = 0;
			for( int k = width-1; k >= 0; k-- )
				if( M[i][k] == 1 ) end = k, k = -1;
			for( int j = 0; j < end; j++ )
				if( M[i][j] == 1 ) M[i][j+1] = 1;
			end = 0;
			for( int k = width-1; k >= 0; k-- )
				if( M2[i][k] == 1 ) end = k, k = -1;
			for( int j = 0; j < end; j++ )
				if( M2[i][j] == 1 ) M2[i][j+1] = 1;

		}

		for( int i = 0; i < width; i++ ) {
			end = 0;
			for( int k = height-1; k >= 0; k-- )
				if( M[k][i] == 1 ) end = k, k = -1;
			for( int j = 0; j < end; j++ )
				if( M[j][i] == 1 ) M[j+1][i] = 1;	
			end = 0;
			for( int k = height-1; k >= 0; k-- )
				if( M2[k][i] == 1 ) end = k, k = -1;
			for( int j = 0; j < end; j++ )
				if( M2[j][i] == 1 ) M2[j+1][i] = 1;
		}

		for( int i = 0 ; i < width; i++ )
			for( int k = 0 ; k < height; k++ ) {
				if( M[k][i] == 1 ) sum1++;
				if( M2[k][i] == 1 ) sum2++;
			}

		if( sum2 < sum1 ) sum1 = sum2;

		cout << sum1 << endl;
	}

	return 0 ;

}