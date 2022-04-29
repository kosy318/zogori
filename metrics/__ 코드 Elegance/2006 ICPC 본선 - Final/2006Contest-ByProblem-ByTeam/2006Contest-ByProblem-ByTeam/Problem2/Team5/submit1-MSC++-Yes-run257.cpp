#include <iostream>
#include <string>

using namespace std ;

int main(void){

	int f ;

	cin >> f;

	while(f--){

		int row , col ;
		int sum[4] ={0,};
		int temp;
		char c;

		cin >> row >> col ;

		char *result = new char[col+1] ;

		char **ch  = new char*[row];
		
		for(int i=0 ; i<row ; i++){
			ch[i] = new char[col+1] ;
		
			cin >> ch[i];
		}
        
		for(i=0 ; i<col ; i++){
		
			sum[0] = sum[1] = sum[2] = sum[3] = 0;

			for(int j=0 ; j<row ; j++){
				
				if(ch[j][i] == 'A')
					sum[0]++ ;
				else if(ch[j][i] == 'C')
					sum[1]++ ;
				else if(ch[j][i] == 'G')
					sum[2]++ ;
				else
					sum[3]++ ;
			}
		
			c = 'A';
			temp = sum[0];
			if( sum[1] > temp ) c = 'C', temp = sum[1];
			if( sum[2] > temp ) c = 'G', temp = sum[2];
			if( sum[3] > temp ) c = 'T';
			
			result[i] = c;
		}

		result[col] = '\0' ;
		
		int count = 0 ;
		
		for(i=0 ; i<row ; i++)		
			for(int j=0 ; j<col ; j++)
				if(ch[i][j] != result[j])
					count ++ ;
				
		cout <<	result << endl ;
		cout << count << endl ;			
		

	}
	

	return 0 ;
}