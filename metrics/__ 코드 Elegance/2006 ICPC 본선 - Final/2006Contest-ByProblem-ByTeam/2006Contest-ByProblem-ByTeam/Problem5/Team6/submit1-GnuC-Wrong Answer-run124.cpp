#include <cstdio>
#include <algorithm>

using namespace std;

int time1[100],time2[100];
int order1[500],order2[500];
int dyna[500][500];
int n1,n2,n;

void calc(int a,int b)
{
	int sum,t;
	dyna[a][b]=min(dyna[a-1][b]+time1[order1[a]],dyna[a][b-1]+time2[order2[b]]);

	sum=0;t=b;
	while(order2[t] != order1[a] && t>0)
	{
		sum+=time2[order2[t]];
		dyna[a][b] =min(dyna[a][b], dyna[a-1][t-1]+max(time1[order1[a]],sum));
		t--;
	}

	sum=0;t=a;
	while(order1[t] != order2[b] && t>0)
	{
		sum+=time1[order1[t]];
		dyna[a][b] = min(dyna[a][b],dyna[t-1][b-1]+max(time2[order2[b]],sum));
		t--;
	}
}

int main(void)
{
	int T;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&time1[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&time2[i]);

		scanf("%d %d",&n1,&n2);
		for(i=1;i<=n1;i++)
		{
			scanf("%d",&order1[i]);
			dyna[i][0]=dyna[i-1][0]+time1[order1[i]];
		}
		for(i=1;i<=n2;i++)
		{
			scanf("%d",&order2[i]);
			dyna[0][i]=dyna[0][i-1]+time2[order2[i]];
		}



		dyna[0][0]=0;
		for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n2;j++)
			{
				calc(i,j);
			}
		}

		printf("%d\n",dyna[n1][n2]);
	}
}
