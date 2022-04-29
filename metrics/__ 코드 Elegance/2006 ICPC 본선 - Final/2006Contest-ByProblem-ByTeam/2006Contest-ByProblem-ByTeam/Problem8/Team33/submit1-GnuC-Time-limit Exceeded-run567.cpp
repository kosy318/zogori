#include<stdio.h>
#include<string.h>
int an,bn;
int ans[5010];
int f[60][5010];
char a[60],b[5010];

void dp(int first)
{
	memset(f,0xff,sizeof(f));
	f[0][0]=0;
	for (int i=0; i<=an; i++)
	{
		for (int j=first; j<=bn; j++)
		{
			if (i==0 && j==first) continue;
			if (i && j!=first) f[i][j-first]=f[i-1][j-first-1]+1;
			if (i && j!=first && a[i-1]==b[j-1] && f[i-1][j-first-1]<f[i][j-first]) f[i][j-first]=f[i-1][j-first-1];
			if (i && (f[i-1][j-first]+1<f[i][j-first] || f[i][j-first]<0)) f[i][j-first]=f[i-1][j-first]+1;
			if (j!=first && (f[i][j-first-1]+1<f[i][j-first] || f[i][j-first]<0)) f[i][j-first]=f[i][j-first-1]+1;
		}
	}
}

void work()
{
	an=strlen(a);
	bn=strlen(b);
	memset(ans,0xff,sizeof(ans));
	for (int i=0; i<bn; i++)
	{
		dp(i);
		for (int j=i; j<bn; j++)
		{
			int tmp=f[an][j-i+1];
			if (i && ans[i-1]>tmp) tmp=ans[i-1];
			if (tmp<ans[j] || ans[j]<0) ans[j]=tmp;
		}
	}	
	printf("%d\n",ans[bn-1]);
}

int main()
{
	int t;
	//freopen("h.in","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s%s",a,b);
		work();
	}
	return 0;	
}
