// no1.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a,b,c,d=0,e;
	int oo=0, pp=0;
	int i,j=0;
	int bat;
	char st[10], en[10], as[7]={0,}, zx[7]={0,};
	scanf("%d",&bat);
	for( i = 0 ; i < bat ; i++) {
		scanf("%s %s", st, en);
		/*
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
		*/
		as[0] = st[6];
		as[1] = st[7];
		a = atoi(as);
		oo += a;
		as[0] = st[3];
		as[1] = st[4];
		a = atoi(as);
		oo += a*60;
		as[0] = st[0];
		as[1] = st[1];
		a = atoi(as);
		oo += a*3600;

		as[0] = en[6];
		as[1] = en[7];
		a = atoi(as);
		pp += a;
		as[0] = en[3];
		as[1] = en[4];
		a = atoi(as);
		pp += a*60;
		as[0] = en[0];
		as[1] = en[1];
		a = atoi(as);
		pp += a*3600;
/*
		a = atoi(as);
		b = atoi(zx);
*/		
		//printf("%s |||| %s\n",as,zx);
		//printf("%d %d\n", a,b);
		
		if( oo > pp ) 
			pp+= 24*3600;
		/*
		oo += (a%100);
		oo += ( ( a - (a%100) )%10000)*60;
		oo += ( a - (a%10000) ) * 3600;
		pp += (a%100);
		pp += ( ( b - (b%100) )%10000)*60;
		pp += ( b - (b%10000) ) * 3600;
		*/
		//printf("%d %d\n", oo, pp);
		/*
		for( c = oo ; c <= pp ; c++) {
			j++;
			if( (j%3) == 0 ) 
				d++;
			
		}
		*/
		//printf("---%d   %d\n",pp-oo, (pp-oo)%3);
		e = pp - oo + 1;
		d = e /3;
		if( (e%3) > 1) 
			d++;
		printf("%d\n",d);
		d = 0;
		j = 0;
		/*
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
		*/
		oo = 0;
		pp = 0;
	}

	return 0;
}

