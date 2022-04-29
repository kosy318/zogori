#include <iostream>
#include <string>
#include <math.h>

using namespace std ;

int main(void){

	int f ;
	char num[9] , num1[9] ;
	int h1, m1, s1, h2, m2, s2, n1 , n2 ;
	int temp, final, sum, loop;

	cin >> f ;

	while(f--){
		
		loop = 1;
		sum=0 ;

		cin >> num >> num1;

		h1 = (num[0]-48)*10 + (num[1]-48);
		m1 = (num[3]-48)*10 + (num[4]-48);
		s1 = (num[6]-48)*10 + (num[7]-48);
		final = (num1[0]-48)*100000 + (num1[1]-48)*10000 + (num1[3]-48)*1000
			+ (num1[4]-48)*100 + (num1[6]-48)*10 + (num1[7]-48);

		temp = h1*10000 + m1*100 + s1;

		while( temp != final ) {
			if( temp%3 == 0 ) sum++;

			s1++;
			if( s1 == 60 ) s1 = 0, m1++;
			if( m1 == 60 ) m1 = 0, h1++;
			if( h1 == 24 ) h1 = 0;

			temp = h1*10000 + m1*100 + s1;
		}


		cout << sum << endl;
	
	}

	return 0;
}