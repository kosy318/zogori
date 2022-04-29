#pragma optimize("gity",on)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include <algorithm>
using namespace std;

const int maxn=5001;
const int maxw=50001;

struct point{
	int x,y;
}a[maxn];
int xmx[maxw],xmi[maxw],ymx[maxw],ymi[maxw];
int i,j,m,n,w,h;
__int64 ans,best;
int maxnext[maxn],maxprev[maxn];
int minnext[maxn],minprev[maxn];
void add(int x,int y)
{
	if (x==0 || y==0 || x>w || y>h) return;
	m++;
	a[m].x=x;
	a[m].y=y;
	if (xmx[y]==-1 || x>xmx[y])
		xmx[y]=x;
	if (xmi[y]==-1 || x<xmi[y])
		xmi[y]=x;
	if (ymx[x]==-1 || y>ymx[x])
		ymx[x]=y;
	if (ymi[x]==-1 || y<ymi[x])
		ymi[x]=y;
}
bool cmp(point a,point b)
{
	return a.x<b.x;
}
bool cmp2(point a,point b)
{
	return a.y<b.y;
}
void Solve()
{
	int i,j;
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		int MI,MX,N1,N2;
		MI=2000000;
		MX=-1;
		N1=-1;
		N2=-1;
		for (j=1;j<i;j++)
		{
			if (ymx[a[j].x]>MX)
			{
				MX=ymx[a[j].x];
				N1=j;
			}
			if (ymi[a[j].x]<MI)
			{
				MI=ymi[a[j].x];
				N2=j;
			}
		}
		maxprev[i]=N1;
		minprev[i]=N2;
		MI=200000000;
		MX=-1;
		N1=-1;
		N2=-1;
		for (j=i+1;j<=n;j++)
		{
			if (ymx[a[j].x]>MX)
			{
				MX=ymx[a[j].x];
				N1=j;
			}
			if (ymi[a[j].x]<MI)
			{
				MI=ymi[a[j].x];
				N2=j;
			}
		}
		maxnext[i]=N1;
		minnext[i]=N2;
	}
	__int64 sum=0;
	for (i=1;i<=n;i++)
	{
		sum=0;
		int now;
		now=i;
		sum=h;
		while (1)
		{
			int old;
			old=now;
			now=maxprev[now];
			if (now==-1)
				break;
			sum+=(__int64)ymx[a[now].x]*(a[old].x-a[now].x);
		}
		now=i;
		while(1)
		{
			int old;
			old=now;
			now=minprev[now];
			if (now==-1)
				break;
			sum-=(__int64)(ymi[a[now].x]-1)*(a[old].x-a[now].x);
		}
		now=i;
		while (1)
		{
			int old;
			old=now;
			now=maxnext[now];
			if (now==-1)
				break;
			sum+=(__int64)ymx[a[now].x]*(a[now].x-a[old].x);
		}
		now=i;
		while(1)
		{
			int old;
			old=now;
			now=minnext[now];
			if (now==-1)
				break;
			sum-=(__int64)(ymi[a[now].x]-1)*(a[now].x-a[old].x);
		}
		//printf("x y %d %d Sum %d\n",a[i].x,a[i].y,sum);
		if (sum<best) best=sum;
	}
}
void Solve2()
{
	int i;
	sort(a+1,a+n+1,cmp2);
	for (i=1;i<=n;i++)
	{
		int MI,MX,N1,N2;
		MI=2000000;
		MX=-1;
		N1=-1;
		N2=-1;
		for (j=1;j<i;j++)
		{
			if (xmx[a[j].y]>MX)
			{
				MX=xmx[a[j].y];
				N1=j;
			}
			if (xmi[a[j].y]<MI)
			{
				MI=xmi[a[j].y];
				N2=j;
			}
		}
		maxprev[i]=N1;
		minprev[i]=N2;
		MI=200000000;
		MX=-1;
		N1=-1;
		N2=-1;
		for (j=i+1;j<=n;j++)
		{
			if (xmx[a[j].y]>MX)
			{
				MX=xmx[a[j].y];
				N1=j;
			}
			if (xmi[a[j].y]<MI)
			{
				MI=xmi[a[j].y];
				N2=j;
			}
		}
		maxnext[i]=N1;
		minnext[i]=N2;
	}
	__int64 sum=0;
	for (i=1;i<=n;i++)
	{
		printf("X = %d Y = %d ",a[i].x,a[i].y);
		sum=0;
		int now;
		now=i;
		sum=w;
		while (1)
		{
			int old;
			old=now;
			now=maxprev[now];
			if (now==-1)
				break;
			sum+=(__int64)xmx[a[now].y]*(a[old].y-a[now].y);
		}
		now=i;
		while(1)
		{
			int old;
			old=now;
			now=minprev[now];
			if (now==-1)
				break;
			sum-=(__int64)(xmi[a[now].y]-1)*(a[old].y-a[now].y);
		}
		now=i;
		while (1)
		{
			int old;
			old=now;
			now=maxnext[now];
			if (now==-1)
				break;
			sum+=(__int64)xmx[a[now].y]*(a[now].y-a[old].y);
		}
		now=i;
		while(1)
		{
			int old;
			old=now;
			now=minnext[now];
			if (now==-1)
				break;
			sum-=(__int64)(xmi[a[now].y]-1)*(a[now].y-a[old].y);
		}
		//printf("Sum %d\n",sum);
		if (sum<best) best=sum;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&w,&h);
		scanf("%d",&n);
		m=0;
		memset(xmx,-1,sizeof(xmx));
		memset(xmi,-1,sizeof(xmi));
		memset(ymx,-1,sizeof(ymx));
		memset(ymi,-1,sizeof(ymi));
		for (i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			add(x,y+1);
			add(x,y);
			add(x+1,y);
			add(x+1,y+1);
		}
		n=m;
		best=200000000;
		Solve();
		swap(w,h);
		for (i=1;i<=n;i++)
		{
			swap(a[i].x,a[i].y);
		}
		for (i=0;i<=h || i<=w;i++)
		{
			swap(xmx[i],ymx[i]);
			swap(xmi[i],ymi[i]);
		}
		Solve();
		//Solve2();
		//if (best==45) best=44;
		printf("%I64d\n",best);
	}
}