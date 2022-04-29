#include <iostream>
//#include <cstdio>

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


		cnt = 0 ;

		while( 1 )
		{
			
			if ( h2==h1 && m2 == m1 && s2 == s1 )
			{
				sum = ( h1/10 + h1 % 10 + m1 / 10 + m1 % 10 + s1 /10 + s1 % 10) ;
				
				if(  (sum % 3 == 0) )
				{
					cnt++ ;
				}
				cout << cnt << endl ;
				break ;
			}

			sum = ( h1/10 + h1 % 10 + m1 / 10 + m1 % 10 + s1 /10 + s1 % 10) ;
			
			if (  sum % 3 == 0 )
			{
				//printf("%02d:%02d:%02d - %d\n", h1, m1, s1, cnt+1);
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
			if (h1 ==24)
			{
				h1 = 0;
			}
			

		}

		
	}
	return 0 ;
}