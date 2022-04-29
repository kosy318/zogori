#include <stdio.h>

int start;
int end;
char buf[6][10];

int calc(int a, int b ,int c)
{
	if ( c == -1 )
		c=0;
	return a * 60 * 20 + b* 20 + c/3;
}

void init()
{
	int a[6], i;
	char c;
	scanf("%c%c:%c%c:%c%c %c%c:%c%c:%c%c",&buf[0][0],&buf[0][1],&buf[1][0],&buf[1][1],&buf[2][0],&buf[2][1],&buf[3][0],&buf[3][1],&buf[4][0],&buf[4][1],&buf[5][0],&buf[5][1]);
	scanf("%c",&c);
	for ( i = 0; i < 6; i++ )
	{
		sscanf(buf[i],"%d",&a[i]);
	}

	start = calc(a[0],a[1],a[2]-1);
	end = calc(a[3],a[4],a[5]);

	if ( end - start < 0 ) end += 24 * 60 * 20 - 1;

	printf("%d\n",end-start);

}

int main()
{
	int T;
	int i;
	char c;
	scanf("%d",&T);
	scanf("%c",&c);
	for(i=0;i<T;i++)
	{
		init();
	}
	return 0;
}