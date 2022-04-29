#include<stdio.h>

int G[2222][2222];
int a[2222][2222];
int n, m, V, S, T;
int A, B, C, D;
int q[2222], head, tail;
int Back[2222];
int Check[2222];

int Bfs(void)
{
	int l1, l2, l3;
	for(l1=0;l1<=V;l1++)
	{
		Check[l1] = 0;
		Back[l1] = 0;
	}
		q[0] = 0;
		head = 0;
		tail = 1;
		Back[0] = -1;
		Check[0] = 1;
		while(head < tail)
		{
			l1 = q[head++];

			for(l2=0;l2<=V;l2++)
			{
				if(G[l1][l2] && Check[l2] == 0)
				{
					Back[l2] = l1;
					q[tail++] = l2;
					Check[l2] = 1;
				}
			}
		}
		if(Check[V] == 0) return 0;
		l1 = V;
		while(1)
		{
			//printf("%d-",l1);
			if(Back[l1] == -1) break;
			G[Back[l1]][l1]--;
			G[l1][Back[l1]]++;
			l1 = Back[l1];
		}
		//printf("\n");



		return 1;
}

int main(void)
{
	int T;
	int l1, l2;
	int t1, t2;

//	freopen("d.in","r",stdin);

	for(scanf("%d",&T);T>=1;T--)
	{
		scanf("%d %d",&n,&m);
		for(l1=1;l1<=n;l1++)
			for(l2=1;l2<=n;l2++)
				a[l1][l2] = 0;
		V = 1 + n + n + 1;
		for(l1=1;l1<=V;l1++)
			for(l2=1;l2<=V;l2++)
				G[l1][l2] = 0;
		for(l1=1;l1<=m;l1++)
		{
			scanf("%d %d",&t1,&t2);
			a[t1][t2] = a[t2][t1] = 1;
		}
		scanf("%d %d %d %d",&A,&B,&C,&D);
		scanf("%d",&m);
		for(l1=1;l1<=m;l1++)
		{
			scanf("%d %d",&t1,&t2);
			a[t1][t2] = a[t2][t1] = 0;
		}
		for(l1=1;l1<=n;l1++)
		{
			G[l1][n+l1] = 1;
		}
		
		for(t1=1;t1<=n;t1++)
		{
			for(t2=1;t2<=n;t2++)
			{
				if(a[t1][t2])
				{
					// t1 -> t2
					G[n+t1][t2] = 1;
				}
			}
		}
		G[0][A]++;
		G[0][B]++;
		G[n+C][V]++;
		G[n+D][V]++;
		
		//// ~_~_??
		if(Bfs() == 0)
		{
			printf("NO\n");
		}
		else
		{
			if(Bfs())
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}