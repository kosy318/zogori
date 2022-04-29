#include<stdio.h>

int a[1111][1111], n, m;
int A, B, C, D;
int G[1111][1111];
int Back[1111];
int q[1111], head, tail;

int Go(int A, int B, int C, int D)
{
	int l1, l2;

	for(l1=1;l1<=n;l1++)
	{
		for(l2=1;l2<=n;l2++)
		{
			G[l1][l2] = a[l1][l2];
		}
	}
	for(l1=1;l1<=n;l1++)
	{
		G[l1][A]=G[B][l1]=G[l1][D]=G[C][l1]=0;
	}

	if(B == C) return 0;

	// Find Path from A to C
	q[0] = A;
	head = 0;
	tail = 1;
	for(l1=1;l1<=n;l1++) Back[l1] = 0;
	Back[A] = -1;
	while(head < tail)
	{
		l1 = q[head++];
		for(l2=1;l2<=n;l2++)
		{
			if(G[l1][l2] && Back[l2] == 0)
			{
				Back[l2] = l1;
				q[tail++] = l2;
			}
		}
	}
	if(Back[C] == 0) return 0;
	l1 = C;
	while(1)
	{
		if(Back[l1] == -1) break;
		for(l2=1;l2<=n;l2++)
		{
			G[Back[l1]][l2] = 0;
		}
		G[Back[l1]][l1] = 1;
		l1 = Back[l1];
	}

	// Find Path from D to B
	q[0] = D;
	head = 0;
	tail = 1;
	for(l1=1;l1<=n;l1++) Back[l1] = 0;
	Back[D] = -1;
	while(head < tail)
	{
		l1 = q[head++];
		for(l2=1;l2<=n;l2++)
		{
			if(G[l1][l2] && Back[l2] == 0)
			{
				Back[l2] = l1;
				q[tail++] = l2;
			}
		}
	}
	if(Back[B] == 0) return 0;
	return 1;
}

int main(void)
{
	int T;
	int l1, l2, t1, t2;

	//freopen("d.in","r",stdin);

	for(scanf("%d",&T);T>=1;T--)
	{
		scanf("%d %d",&n,&m);
		for(l1=1;l1<=n;l1++)
			for(l2=1;l2<=n;l2++)
				a[l1][l2] = 0;
		for(l1=1;l1<=m;l1++)
		{
			scanf("%d %d",&t1,&t2);
			a[t1][t2] = a[t2][t1] = 1;
		}
		scanf("%d %d %d %d",&A, &B, &C, &D);
		scanf("%d",&m);
		for(l1=1;l1<=m;l1++)
		{
			scanf("%d %d",&t1,&t2);
			a[t1][t2] = a[t2][t1] = 0;
		}
		if(a[A][B] == 0 || a[C][D] == 0)
		{
			printf("NO\n");
		}
		else if(Go(A, B, C, D) || Go(A, B, D, C) || Go(B, A, C, D) || Go(B, A, D, C))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}