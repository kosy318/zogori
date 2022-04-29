#include <stdio.h>

int m,n;
int difer;
int val[4];
char DNA[50][1000];
char result[1000];
char D[4] = {'A','C','G','T'};

void input ( void ){

	int i;
	
	scanf("%d",&m);
	scanf("%d",&n);

	for( i = 0 ; i < m ; i++ )
		scanf("%s",&DNA[i]);
}

void init( void ){

	int i;
	for( i = 0 ; i < 4 ; i++ )
		val[i] = 0;

}

int max ( void ){

	int i;
	int cal = val[0];
	int j = 0;

	for( i = 1 ; i < 4 ; i++ )
		if( cal < val[i] ){
			cal = val[i];
			j = i;
		}
	
	for( i = 0 ; i < 4 ; i++ )
		if( i != j )
			difer += val[i];

	return j;
}

void process( void ){

	
	int i,j,k,r;
	int cnt = 0;
	char c;
	int maximum;
	
	difer = 0;
	for( i = 0 ; i < n ; i++ ){
		init();
		for( j = 0 ; j < m ; j++ ){
			c = DNA[j][i];
			
			if( c == 'A' )
				val[0]++;
			else if( c == 'C' )
				val[1]++;
			else if( c == 'G' )
				val[2]++;
			else
				val[3]++;
		}
		maximum = max();
		result[cnt++] = D[maximum];
		

	}
	printf("%s\n",result);
	printf("%d\n",difer);
}

int main ( void ){

	int T;
	
	scanf("%d",&T);	
	while( T-- ){

		input();
		process();

	}

}
