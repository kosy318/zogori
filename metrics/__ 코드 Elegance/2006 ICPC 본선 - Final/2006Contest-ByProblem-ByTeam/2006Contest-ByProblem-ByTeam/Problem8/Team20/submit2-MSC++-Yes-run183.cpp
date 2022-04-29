#pragma optimize("gity",on)
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

const int maxn1=5011;
const int maxn2=61;

char s1[maxn1],s2[maxn2];

int ans[maxn1];
int opt[maxn2*2][maxn2];
int i,j,m,n;

int min(int a,int b)
{
	return a<b?a:b;
}
int getans(int st,int ed)
{
	int i,j;
	opt[0][0]=0;
	for (i=st;i<=ed;i++)
	{
		opt[i-st+1][0]=i-st+1;
	}
	for (i=1;i<=m;i++)
	{
		opt[0][i]=i;
	}
	for (i=st;i<=ed;i++)
	{
		for (j=1;j<=m;j++)
			if (s1[i-1]==s2[j-1])
			{
				opt[i-st+1][j]=opt[i-st][j-1];
			}else
			{
				opt[i-st+1][j]=min(min(opt[i-st][j],opt[i-st+1][j-1])+1,opt[i-st][j-1]+1);
			}
	}
	return opt[ed-st+1][m];
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s %s",s2,s1);
		n=strlen(s1);
		m=strlen(s2);
		memset(ans,-1,sizeof(ans));
		ans[0]=0;
		//printf("%d\n",getans(1,n));
		for (i=0;i<=n;i++)
		if (ans[i]>=0)
		{
			for (j=1;j<=2*m;j++)
			{
				int tmp=getans(i+1,i+j);
				if (ans[i]>tmp) tmp=ans[i];
				if (ans[i+j]==-1)
				{
					ans[i+j]=tmp;
				}else
					if (tmp<ans[i+j])
						ans[i+j]=tmp;
			}
		}
		printf("%d\n",ans[n]);
	}
}