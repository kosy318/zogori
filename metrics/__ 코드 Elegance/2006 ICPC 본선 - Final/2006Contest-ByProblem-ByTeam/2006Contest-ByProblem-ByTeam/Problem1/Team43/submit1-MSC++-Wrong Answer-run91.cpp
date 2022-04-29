#include <stdio.h>

typedef struct TIME
{
	int h, m, s;
} Time;

Time a, b;
int tA, tB;
int T;

Time Increase(Time Q)
{
    Q.s++;
	Q.m += Q.s / 60;
	Q.s = Q.s % 60;
	Q.h += Q.m / 60;
	Q.m = Q.m % 60;
	Q.h = Q.h % 24;
	return Q;
}
int main()
{
	int k, i;
	int outcome;
	char A[100], B[100];
	scanf("%d",&T);
	for(k=0;k<T;k++)
	{
        scanf("%s %s",A,B);

		a.h = ( A[0] - '0' )  * 10 + ( A[1] - '0' ) * 1;
		a.m = ( A[3] - '0' )  * 10 + ( A[4] - '0' ) * 1;
		a.s = ( A[6] - '0' )  * 10 + ( A[7] - '0' ) * 1;
		b.h = ( B[0] - '0' )  * 10 + ( B[1] - '0' ) * 1;
		b.m = ( B[3] - '0' )  * 10 + ( B[4] - '0' ) * 1;
		b.s = ( B[6] - '0' )  * 10 + ( B[7] - '0' ) * 1;


		outcome = 0;
		while( true )
		{
			tA = a.h * 10000 + a.m * 100 + a.s;
			if( tA % 3 == 0 )
			{
				outcome++;
			}

			a = Increase(a);

			if( a.h == b.h && a.m == b.m && a.s == b.s )
			{
				break;
			}           
		}
		printf("%d\n",outcome);
	}

}