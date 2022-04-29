// no1.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a,b,c,d=0;
	int i,j=1;
	int bat;
	char st[10], en[10], as[7]={0,}, zx[7]={0,};
	scanf("%d",&bat);
	for( i = 0 ; i < bat ; i++) {
		scanf("%s %s", st, en);
		as[0] = st[0];
		as[1] = st[1];
		as[2] = st[3];
		as[3] = st[4];
		as[4] = st[6];
		as[5] = st[7];
		zx[0] = en[0];
		zx[1] = en[1];
		zx[2] = en[3];
		zx[3] = en[4];
		zx[4] = en[6];
		zx[5] = en[7];
		a = atoi(as);
		b = atoi(zx);
		//printf("%s |||| %s\n",as,zx);
		//printf("%d %d\n", a,b);
		if( a > b ) 
			b+= 240000;
		for( c = a ; c <= b ; c++) {
			if( (c%100) > 59 ) {
				c = c - 60;
				c = c + 100;
			}
			if( (c%10000) > 5959 ) {
				c = c - 6000;
				c = c + 10000;
			}
			j++;
			if( (j%3) == 0 ) 
				d++;
		}
		printf("%d\n",d);
		d = 0;
		j = 1;
	}

	return 0;
}

