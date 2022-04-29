#include<stdio.h>
#include<string.h>
char a[1001][1001];
int cnt[1001][4];
char ans[1001];
void main()
{
	int t,n,m,i,j,k,s;
	scanf("%d",&t);

	for(t;t>=1;t--)
	{
		scanf("%d %d",&n,&m);
		for(j=0;j<100;j++)
		{
			cnt[j][0]=0;
			cnt[j][1]=0;
			cnt[j][2]=0;
			cnt[j][3]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s",a[i]);
			for(j=0;j<strlen(a[i]);j++)
			{
				if(a[i][j]=='A') cnt[j][0]++;
				if(a[i][j]=='C') cnt[j][1]++;
				if(a[i][j]=='G') cnt[j][2]++;
				if(a[i][j]=='T') cnt[j][3]++;
			}
		}
		for(j=0;j<m;j++)
		{
			if(cnt[j][0] >= cnt[j][1] && cnt[j][0] >= cnt[j][2]  && cnt[j][0] >= cnt[j][3]) ans[j]='A';
			else if(cnt[j][1] >= cnt[j][0] && cnt[j][1] >= cnt[j][2]  && cnt[j][1] >= cnt[j][3]) ans[j]='C';
			else if(cnt[j][2] >= cnt[j][0] && cnt[j][2] >= cnt[j][1]  && cnt[j][2] >= cnt[j][3]) ans[j]='G';
			else if(cnt[j][3] >= cnt[j][0] && cnt[j][3] >= cnt[j][1]  && cnt[j][3] >= cnt[j][2]) ans[j]='T';
		}
		s=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ans[j] != a[i][j]) s++;
			}
		}
		for(j=0;j<m;j++) printf("%c",ans[j]);
		printf("\n");
		printf("%d\n",s);
	}
}