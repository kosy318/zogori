
#include <stdio.h>
#define prime(nnn) (nnn+N)
#define source (2*N)
#define sink (2*N+1)
int N,F,M;
int Link[2005][2005];
int Queue[2005][2];
int Visit[2005];
int Qs,Qe;

int find_flow(int label)
{
	int q,n,bf,nq;
	Queue[0][0] = source;
	Queue[0][1] = -1;
	Visit[source]=label;
	Qs=Qe=0;
	while (Qs<=Qe)
	{
		n=Queue[Qs][0];
		if (n==sink)
		{
			nq = Qs;
			bf = Queue[Qs][1];
			while (bf!=-1)
			{
				if (bf<0 || nq<0) break;
				if (Queue[bf][0]<0 || Queue[nq][0]<0) break;
				Link[ Queue[bf][0] ][ Queue[nq][0] ]--;
				Link[ Queue[nq][0] ][ Queue[bf][0] ]++;
				nq = Queue[ nq ][1];
				bf = Queue[ bf ][1];
				if (bf<0) break;
			}
			return 1;
		}
		for (q=0;q<=sink;q++)
		{
			if (Link[n][q]>0 && Visit[q]<label)
			{
				Visit[q]=label;
				Qe++;
				Queue[Qe][0]=q;
				Queue[Qe][1]=Qs;
			}
		}
		Qs++;
	}
	return 0;
}

int maxflow()
{
	int t=0,label=1;
	while ( find_flow(label++) && t<2 ) t++;
	return t;
}

int main()
{
	int t,ccc;
	scanf("%d",&t);
	int q,w,e,a,b,c,d;
	for (ccc=0;ccc<t;ccc++)
	{
		scanf("%d %d",&N,&M);
		//initialization
		for (q=0;q<=sink;q++)
			for (w=0;w<=sink;w++)
				Link[q][w]=0;
		for (q=0;q<N;q++)
		{
			Link[ q ][ prime(q) ]++;
		}
		for (w=0;w<M;w++)
		{
			scanf("%d %d",&a,&b);
			a--;
			b--;
			Link[ prime(a) ][b]++;
			Link[ prime(b) ][a]++;
		}

		scanf("%d %d %d %d",&a,&b,&c,&d);

		a--;b--;c--;d--;

		Link[ prime(a) ][b]--;
		Link[ prime(b) ][a]--;

		Link[ prime(c) ][d]--;
		Link[ prime(d) ][c]--;

		//Source -> a,b
		Link[ source ][ a ]++;
		Link[ source ][ b ]++;
		// c,d->sink
		Link[ prime(c) ][ sink ]++;
		Link[ prime(d) ][ sink ]++;

		scanf("%d",&F);
		for (q=0;q<F;q++)
		{
			scanf("%d %d",&a,&b);
			a--;
			b--;
			Link[ prime(a) ][b]--;
			Link[ prime(b) ][a]--;
		}

		if ( maxflow() == 2 ) printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}