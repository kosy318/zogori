#include <stdio.h>

typedef struct DATA
{
	int a, b;
} Gas;

Gas d[25];
int n, G, M, T;


int LCM()
{
	int i, j;
	bool check;
	for(i=1;i<=2520;i++)
	{
		check = true;
		for(j=0;j<n;j++)
		{
			if( i % d[j].a != 0 )
			{
				check = false;
				break;
			}
		}
		if( check )
		{
			return i;
		}
	}
}

int Process()
{
	int i, j, lcm, sum;
	bool check;
	lcm = LCM();
	G = -1;
	for(i=0;i<lcm;i++)
	{
		check = true;
		for(j=0;j<n;j++)
		{
			if( i % d[j].a != d[j].b % d[j].a )
			{
				check = false;
				break;
			}
		}
		if( check )
		{
			G = i;
			break;
		}
	}
	if( G == -1 )
	{
		return 0;
	}
	else
	{
		while( true )
		{
			sum = 0;
			for(i=0;i<n;i++)
			{
				sum += ( G - d[i].b ) / d[i].a ;
			}
			if( sum > M )
			{
				return 0;
			}
			if( sum == M )
			{
				return G;
			}
			else
			{
				G += lcm;
			}
		}
	}
	return 0;
}

int main()
{
	int k, i;
	scanf("%d",&T);
	for(k=0;k<T;k++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&d[i].a,&d[i].b);
		}
		scanf("%d",&M);
		printf("%d\n",Process());
	}
	return 1;
}