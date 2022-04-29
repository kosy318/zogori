#include <iostream>

using namespace std ;

int main()
{
	int tCase ;
	int i, j ;
	char ch ;
	int h1 ,h2, m1, m2, s1, s2 ;
	int cnt ;
	int sum ;
	bool check ;
	cin >> tCase ;
	
	for ( i = 0 ; i < tCase ; i++ )
	{

		sum = 0 ;

		cin >> h1 ;
		cin >> ch ;
		cin >> m1 ;
		cin >> ch ;
		cin >> s1 ;

		cin >> h2 ;
		cin >> ch ;
		cin >> m2 ;
		cin >> ch ;
		cin >> s2 ;

		if ( h2 < h1 )
		{
			h2 += 24 ;
		}

		cnt = 0 ;

		while( 1 )
		{
			
			if ( h2==h1 && m2 == m1 && s2 == s1 )
			{
				cout << cnt << endl ;
				break ;
			}
			if ( h2 > 24 )
			{
                h2 -= 24 ;
				check = true ;
			}
			else
			{
				check = false ;
			}

			sum = ( h1/10 + h1 % 10 + m1 / 10 + m1 % 10 + s1 /10 + s1 % 10) % 3 ;
			
			if ( check )
			{
				h2 += 24 ;
			}

			if ( sum == 0)
			{
				cnt ++ ;
			}
			s1++ ;
			if ( s1 == 60 )
			{
				s1 = 0 ;
				m1++ ;
			}
			if ( m1 == 60 )
			{
				m1 = 0 ;
				h1++ ;
			}
			

		}

		
	}
	return 0 ;
}