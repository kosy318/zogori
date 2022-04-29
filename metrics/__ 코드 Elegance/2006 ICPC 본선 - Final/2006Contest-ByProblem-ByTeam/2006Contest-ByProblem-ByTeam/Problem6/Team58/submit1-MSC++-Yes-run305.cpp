#include <stdio.h>
#include <math.h>

int n,nn;
int a[20000];
int x;

void init()
{
	scanf("%d\n",&n);
	nn=n*2;
	for(int i=0;i<nn;i++)
		scanf("%d ",&a[i]);
	scanf("%d",&x);
}

void process()
{
	int i;
	int xx;
	int result;
	int r;

	int X;
	double b = x;
	double c;
	int d;
	c=0;
	for(i=0;i<nn;i+=2)
	{
		b+=(double)a[i+1]/a[i];
		c+=(double)1/a[i];
	}
	b/=c;

	int f;
	d=floor(b);
	result=0;
	f=1;
	for(i=0;i<nn;i+=2)
	{
		xx=d-a[i+1];
		r=xx/a[i];
		if(xx!=r*a[i])
		{
			f=0;
		}
		result+=r;
	}
	if(f&&x==result)
	{
		printf("%d\n",d);
		return;
	}
	d++;
	f=1;
	result=0;
	for(i=0;i<nn;i+=2)
	{
		xx=d-a[i+1];
		r=xx/a[i];
		if(xx!=r*a[i])
		{
			f=0;
		}
		result+=r;
	}
	if(f&&x==result)
	{
		printf("%d\n",d);
		return;
	}
	printf("0\n",0);
}

int main()
{
	int T;
	int i;
	scanf("%d\n",&T);
	for(i=0;i<T;i++)
	{
		init();
		process();
	}
	return 0;
}