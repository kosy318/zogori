#include<iostream>
#include<fstream>
#include<string>

long long a[ 30 ], b[ 30 ];
long long M;
int n;

using namespace std;

void solve()
{
	long long A = 0;
	long long B = 0;
	long long C = 0;
	long long D = 1;

	for( int i = 0; i < n; i++ )
		M *= a[ i ];

	for( int  i = 0; i < n; i++ )
	{
		C = 1;
		for( int j = 0; j < n; j++ )
		{
			if ( i != j )
			{
				C *= a[ j ];
			} 
		}
		A += C;
		
		B += C * b[ i ];
	}

	if ( ( M + B ) % A == 0 ) 
		cout << ( M + B ) / A << endl;
	else
		cout << "0\n";
}

int main()
{
	int nT;

	//ifstream fin("input.txt");

	cin >> nT;

	while( nT-- )
	{
		cin >> n;
		for( int i = 0; i < n; i++ )
			cin >> a[ i ] >> b[ i ];

		cin >> M;

		solve();
	}
}