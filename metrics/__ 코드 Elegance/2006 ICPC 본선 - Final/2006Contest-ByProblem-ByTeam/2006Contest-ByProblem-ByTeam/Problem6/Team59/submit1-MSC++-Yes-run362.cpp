#include <iostream>

using namespace std;

int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

int sort(int x[], int c[], int n)
{
	int i;
	int temp = x[0];

	for ( i=1; i<n; i++)
		if ( temp < x[i] ){
			temp = x[i];
			swap (&x[0], &x[i]);
			swap (&c[0], &c[i]);
		}

	temp = x[1];

	for ( i=2; i<n; i++)
		if ( temp < x[i] ) {
			temp = x[i];
			swap(&x[1], &x[i]);
			swap(&c[1], &c[i]);
		}

	return 0;
}

int gogo ( int x[], int c[], int n, int m)
{
	int i, j;
	int d, sum, target;
	int x1, x2;

	x1 = x[0];
	x2 = x[1];
	d = c[1] - c[0];

	for ( i=0; i<m/n; i++)
	{
		if ( ( x1*i - d ) % x2 == 0 ){
			sum = 0;
			target = x[0]*i + c[0];

			sum += i;

			for ( j=1; j<n; j++) {
				if ( ( target - c[j] ) % x[j] == 0 ) sum += ( target - c[j] ) / x[j];
				else break;
			}

			if ( sum > m ) return 0;
			else if ( sum == m ) return target;
		}
	}

	return 0;
}

int main ( void )
{
	int t, n, m, x[22], c[22];

	cin >> t;

	for ( int i=0; i<t; i++)
	{
		cin >> n;

		for ( int j=0; j<n; j++)
			cin >> x[j] >> c[j];

		cin >> m;

		sort(x, c, n);

		cout << gogo(x, c, n, m) << endl;
	}

	return 0;
}