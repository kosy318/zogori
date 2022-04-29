#include<stdio.h>
int p[1001][2],cnt;
int vec[10000][4];
int chk[1001],n;
double ans;
#define EPS 1e-12
void solve()
{
	int i,j;
	double s,t,d,a0,a1,b0,b1,c0,c1,d0,d1,max,xp,yp,ty;
	ans=999999.0;
	for(i=1;i<=n;i++)
	{
		max=-1e100;
		for(j=1;j<=cnt;j++)
		{
			d=(vec[j][2]-vec[j][0]);

			if(d==0) continue;

			a0=p[i][0];
			a1=p[i][1];
			b0=p[i][0];
			b1=p[i][1]+1;
			c0=vec[j][0];
			c1=vec[j][1];
			d0=vec[j][2];
			d1=vec[j][3];

			d=(a0-b0)*(d1-c1) - (a1-b1)*(d0-c0);
			s=(a0*(d1-c1) + c0*(a1-d1) + d0*(c1-a1))/d;
			//t=-(a0*(c1-b1) + b0*(a1-c1) + c0*(b1-a1))/d;

			if(a1+((b1-a1)*s) > max && (s < -EPS || EPS < s))
			{
				max=a1+((b1-a1)*s);
				chk[i]=j;
			}

			
		}
		if(max - p[i][1] < ans) ans=max - p[i][1];
	}
	for(i=2;i<=n;i++)
	{
		if(chk[i]!=chk[i-1])
		{
			a0=vec[chk[i]][0];
			a1=vec[chk[i]][1];
			b0=vec[chk[i]][2];
			b1=vec[chk[i]][3];
			
			c0=vec[chk[i-1]][0];
			c1=vec[chk[i-1]][1];
			d0=vec[chk[i-1]][2];
			d1=vec[chk[i-1]][3];

			d=(a0-b0)*(d1-c1) - (a1-b1)*(d0-c0);
			s=(a0*(d1-c1) + c0*(a1-d1) + d0*(c1-a1))/d;
			t=-(a0*(c1-b1) + b0*(a1-c1) + c0*(b1-a1));

			xp=a0 + (b0-a0) * s;
			yp = a1 + (b1-a1)*s;

			ty = p[i-1][1] + (((xp-p[i-1][0])/(p[i][0] - p[i-1][0])) * (p[i][1]-p[i-1][1]));

			if(yp - ty < ans) ans=yp - ty;
		}
	}
	if(ans>1000+EPS) printf("IMPOSSIBLE\n");
	else printf("%.1lf\n",ans);
}
void main()
{
	int t,i;
	//freopen("i.in","r",stdin);
	scanf("%d",&t);
	for(t;t>=1;t--)
	{
		scanf("%d",&n);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&p[i][0],&p[i][1]);
			if(i>=2)
			{
				vec[++cnt][0]=p[i-1][0];
				vec[cnt][1]=p[i-1][1];
				vec[cnt][2]=p[i][0];
				vec[cnt][3]=p[i][1];
			}
/*			vec[++cnt][0]=p[i][0];
			vec[cnt][1]=p[i][1];
			vec[cnt][2]=p[i][0]+1;
			vec[cnt][3]=p[i][1];*/
		}
		solve();
	}
}