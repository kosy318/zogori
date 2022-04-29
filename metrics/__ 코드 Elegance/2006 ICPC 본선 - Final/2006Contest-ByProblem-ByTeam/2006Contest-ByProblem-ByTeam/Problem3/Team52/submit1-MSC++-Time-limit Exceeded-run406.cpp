#include <iostream>

using namespace std;

int main()
{
	int T;
	int w,h;
	int n;
	int x, y;
	int size ;
	int sizecnt ;
	int x1, y1 ;
	
	bool** pan ;
	bool** copy ;

	int i, j, k, l;
	int min, max;
	
	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> w >> h;
		cin >> n;

		pan = new bool*[h] ;
		copy = new bool*[h] ;
		for ( x1 = 0 ; x1 < h ; x1++ )
		{
			pan[x1] = new bool[w] ;
			memset( pan[x1] , 0x00 , w ) ;
			copy[x1] = new bool[w] ;
			memset( copy[x1] , 0x00 , w ) ;
		}

		
		size = w * h ;

		for (j = 0; j < n; j++)
		{
			cin >> x >> y;
			
			for (k = x-1; k <=x; k++)
			{
				for (l=y-1; l<=y; l++)
				{
					if (k < 0 || k >= w)
						 continue;
					if (l < 0 || l >= h)
						continue;

					pan[l][k] = true;
				}
			}
		}
		
		for (j = 0; j < h; j++)
		{
			min = w;
			max = 0;
			for (k = 0; k < w; k++)
			{
				if (pan[j][k])
				{
					if (k < min)
						min = k;
					if (k > max)
						max = k;
				}
			}

			for (k = min; k < max; k++)
				pan[j][k] = true;
		}

		for (j = 0; j < w; j++)
		{
			min = w;
			max = 0;
			for (k = 0; k < h; k++)
			{
				if (pan[k][j])
				{
					if (k < min)
						min = k;
					if (k > max)
						max = k;
				}
			}

			for (k = min; k < max; k++)
				pan[k][j] = true;
		}

		
		for (j = 0; j < h; j++)
		{
			sizecnt = 0 ;
			for ( x1 = 0 ; x1 < h ; x1++ )
			{
				memcpy( copy[x1] , pan[x1] , w ) ;
			}
			
			for (k = 0; k < w ; k++)
				copy[j][k] = true;

			//check

			for (x1 = 0; x1 < h; x1++)
			{
			min = w;
			max = 0;
			for (y1 = 0; y1 < w; y1++)
			{
				if (copy[x1][y1])
				{
					if (y1 < min)
						min = y1;
					if (y1 > max)
						max = y1;
				}
			}

			for (y1 = min; y1 < max; y1++)
				copy[x1][y1] = true;
		}

		for (y1 = 0; y1 < w; y1++)
		{
			min = w;
			max = 0;
			for (x1 = 0; x1 < h; x1++)
			{
				if (copy[x1][y1])
				{
					if (x1 < min)
						min = x1;
					if (k > max)
						max = x1;
				}
			}

			for (x1 = min; x1 < max; x1++)
				copy[x1][y1] = true;
		}
		//check end

			for ( x1 = 0 ; x1 < w ; x1++ )
			{
				for ( y1 = 0 ; y1 < h ; y1++ )
					if( copy[y1][x1] == true )
						sizecnt++ ;
			}
			if ( sizecnt < size )
				size = sizecnt ;

		}		
		
		for (j = 0; j < w; j++)
		{
			sizecnt = 0 ;
			for ( x1 = 0 ; x1 < h ; x1++ )
			{
				memcpy( copy[x1] , pan[x1] , w ) ;
			}
			
			
			for (k = 0; k < h ; k++)
				copy[k][j] = true;

			//check

			for (x1 = 0; x1 < h; x1++)
			{
			min = w;
			max = 0;
			for (y1 = 0; y1 < w; y1++)
			{
				if (copy[x1][y1])
				{
					if (y1 < min)
						min = y1;
					if (y1 > max)
						max = y1;
				}
			}

			for (y1 = min; y1 < max; y1++)
				copy[x1][y1] = true;
		}

		for (y1 = 0; y1 < w; y1++)
		{
			min = w;
			max = 0;
			for (x1 = 0; x1 < h; x1++)
			{
				if (copy[x1][y1])
				{
					if (x1 < min)
						min = x1;
					if (k > max)
						max = x1;
				}
			}

			for (x1 = min; x1 < max; x1++)
				copy[x1][y1] = true;
		}
		//check end

			for ( x1 = 0 ; x1 < w ; x1++ )
			{
				for ( y1 = 0 ; y1 < h ; y1++ )
					if( copy[y1][x1] == true )
						sizecnt++ ;
			}
			if ( sizecnt < size )
				size = sizecnt ;

		}	




		for (j = 0; j < h; j++)
		{
			for (k = 0; k < w; k++)
			{
				if (pan[j][k] == true)
				{
					cout << "O";
				}
				else 
					cout << "X";
			}
			cout << endl;
		}

		for ( x1 = 0 ; x1 < h ; x1++ )
		{
			delete [] pan[x1] ;
			delete [] copy[x1] ;
		}

		delete [] pan ;
		delete [] copy ;

		cout << size  << endl;
	}

	return 0;
}

