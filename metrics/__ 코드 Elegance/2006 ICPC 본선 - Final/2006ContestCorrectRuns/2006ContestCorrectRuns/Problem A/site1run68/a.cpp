#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main ( void )
{
	int n;
	int h1, m1, s1, h2, m2, s2;
	int start, end, count, plus;

	scanf("%d", &n);

	for ( int i=0; i<n; i++)
	{
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

		start = end = count = plus = 0;

		start = h1;
		start *= 100;
		start += m1;
		start *= 100;
		start += s1;

		end = h2;
		end *= 100;
		end += m2;
		end *= 100;
		end += s2;

		if ( start > end ){
			for ( int j=start; j<= 235959; j++){
				if ( (j / 1000) % 10 >= 6 ) continue;
				if ( ( j / 10 ) % 10 >= 6 ) continue;
				if ( j % 3 == 0 ) count ++;
			}
			start = 0;
		} 
			
		for ( int j=start; j<= end + plus*1000; j++){
			if ( (j / 1000) % 10 >= 6 ) continue;
			if ( ( j / 10 ) % 10 >= 6 ) continue;
			if ( j % 3 == 0 ) count ++;
		}

		printf ("%d\n", count);
		
	}

	return 0;
}