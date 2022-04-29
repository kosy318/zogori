#include <stdio.h>

struct Point
{
	int x, y;
};

struct line
{
	double a, b;
	int c;
};

struct line abc(Point a,Point b)
{
	struct line result;
	result.a = (double) (b.y-a.y) / (b.x-a.x);
	result.b = (a.y-+result.a*a.x);
	result.c = a.y < b.y ? 0 : 1;
	return result;
}

double M(double a,double b)
{
	if ( a>b)
		return a;
	else
		return b;
}


double get(line t, Point x)
{
	return t.a * x.x + t.b;
}
Point a[100000];
line l[100000];

int main()
{
	int t, c,n,i, j;
	double answer, max;
	scanf("%d",&t);
	for ( c=0;c<t;c++)
	{
		answer =10000000000.0;

		scanf("%d",&n);
		for ( i=0;i<n;i++)
			scanf("%d %d",&a[i].x,&a[i].y);
		for (i=0;i<n-1;i++)
			l[i] = abc(a[i],a[i+1]);

		for (i=0;i<n;i++)
		{
			max = -1935824358.0;
			for (j=0;j<=i;j++)
			{
				if ( l[j].c==0 )
				{
					max = M(max,get(l[j],a[i])- a[i].y) ;
				}
			}
			for (j=i+1;j<n-1;j++)
			{
				if ( l[j].c==1 )
				{
					max = M(max,get(l[j],a[i])- a[i].y) ;
				}
			}
			if ( max < answer) answer =max;
		}
		if ( answer >=1000.0 )
			printf("IMPOSSIBLE\n");
		else
			printf("%0.1f\n",answer);
	}
	return 0;
}
