#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n, len;
string data[ 100 ];

int tran( char inp )
{
	switch( inp )
	{
	case 'A' :
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	default:
		cout << "error\n";
	}
}

void solve()
{
	string ret;
	int cnt[4];
	int tr;
	int maxj;
	int i, j;
	string crt = "ACGT";
	int retn = 0;

	for( i = 0; i < len; i++ )
	{
		for( j = 0; j < 4; j++ )
			cnt[ j ] = 0;

		for( j = 0; j < n; j++ )
		{
			cnt[ tran( data[ j ][ i ] ) ]++;
		}

		maxj = 0;
		for( j = 1; j < 4; j++ )
			if (  cnt[ j ] > cnt[ maxj ] )
				maxj = j;

		for( j = 0; j < 4; j++ )
		{
			if ( maxj != j )
				retn += cnt[ j ];
		}

		ret += crt[ maxj ];
	}

	cout << ret << endl;
	cout << retn << endl;
}

int main()
{
	//ifstream fin( "input.txt" );
	int nT;

	cin >> nT;

	while( nT-- )
	{
		cin >> n >> len;
		
		for( int i = 0; i < n; i++ )
		{
			cin >> data[ i ];
		}

		solve();
	}
}