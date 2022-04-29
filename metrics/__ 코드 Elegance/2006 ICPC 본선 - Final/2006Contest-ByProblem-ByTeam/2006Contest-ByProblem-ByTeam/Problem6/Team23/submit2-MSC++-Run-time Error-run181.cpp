#include <stdio.h>

int main ()
{
	int a[20], b[20];
	int m;
	int t;

	int n;
	int i,j;
	int min, max, e, k;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++) 
			scanf("%d %d", &a[i], &b[i]);

		scanf("%d", &m);

		while (m > 0) {
			min = -1; k = -1; e = -1;
			max = -1;

			for (i=0; i<n; i++) {
				if (min > b[i] || min == -1) {
					min = b[i];
					e = i;
				}
				else if (min == b[i] && a[e] < a[i])
					e = i;

				if (max < b[i]) max = b[i];
			}

			k = (max - min) / a[e];

			if (min + a[e]*k < max) k = k + 1;
			if (min == max) k = 1;

			b[e] = b[e] + a[e] * k;
			m = m - k;
		}

		k = b[0];
		for (i=1; i<n; i++)
			if (k != b[i]) k = -1;

		if (k == -1 || m != 0) printf("0\n"); else printf("%d\n", k);
	}
}

/*#include<stdio.h>

bool is_inter_inte(int a1,int b1,int a2,int b2)
{
	return !((b2-b1)%(a1-a2));
}

int inter(int a1,int b1, int a2, int b2)
{
	return (b2-b1)/(a1-a2);
}

bool is_x_inte(int a,int b,int y)
{
	return !((y-b)%a);
}

int xx(int a,int b,int y)
{
	return (y-b)/a;
}

int a,b,c,d;
int n;
int last;
int M;
bool flag;

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		if(n>1)
		{
			last=-2147483648;
			scanf("%d %d",&c, &d);
			flag = true;
			M=0;
			for(int i=0; i<n; i++)
			{
				a=c; b=d;
				scanf("%d %d",&c, &d);
				if(is_inter_inte(a,b,c,d) && flag)
				{
					if(last==-2147483648)
					{
						last=inter(a,b,c,d);
						if(is_x_inte(a,b,last)) M=xx(a,b,last);
						else
						{
							flag=false;
							continue;
						}
						if(is_x_inte(c,d,last)) M+=xx(c,d,last);
						else
						{
							flag=false;
							continue;
						}
					}
					else if(last!=inter(a,b,c,d))
					{
						flag=false;
						continue;
					}
					else
					{
						if(is_x_inte(c,d,last)) M+=xx(c,d,last);
						else
						{
							flag=false;
							continue;
						}
					}
				}
			}
			int temp;
			scanf("%d",&temp);
			if(M!=temp || flag) printf("0\n"); else printf("%d",last);
		}
		else if(n==1)
		{
			scanf("%d %d",&a,&b);
			int temp;
			scanf("%d",&temp);
			printf("%d\n",a*temp+b);
		}
		else if(n==0)
		{
			printf("0\n");
		}

	}
	return 0;
}
*/