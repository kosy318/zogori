// no1.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a,b,c;
	int d,e,f;
	int oo;
	int tt;
	int i,j=1;
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
		c = atoi(as);
		as[0] = st[3];
		as[1] = st[4];
		b = atoi(as);
		as[0] = st[0];
		as[1] = st[1];
		a = atoi(as);

		as[0] = en[6];
		as[1] = en[7];
		f = atoi(as);
		
		as[0] = en[3];
		as[1] = en[4];
		e = atoi(as);
		
		as[0] = en[0];
		as[1] = en[1];
		d = atoi(as);

		if( a > d)
			d+= 24;
		tt = 0;
//		printf("%d %d %d ---- %d %d %d\n", a,b,c,d,e,f);
		b++;
		tt = (d -a)*60;
		if( b > e) {
			e+=60;
			tt -= 60;
			tt += e-b;
		}
		else
			tt += e-b;
		/*
		while( (a!=d) || (b!=e)) {
			b++;
//			printf("%d --",b);
			if( b > 59 ) {
				b -= 60;
				a++;
			}
			tt++;
		}
		*/
		oo = tt * 20;
		tt = (61 - c)/3;
		oo += tt;
		oo += (f+2)/3;

		printf("%d\n",oo);
			

	}
}

