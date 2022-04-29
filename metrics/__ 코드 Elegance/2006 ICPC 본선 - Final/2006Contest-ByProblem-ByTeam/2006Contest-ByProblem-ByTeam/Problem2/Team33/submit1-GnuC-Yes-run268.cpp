#include<stdio.h>
int n,len;
char tmp[]={'A','C','G','T'};
char dna[60][1010];
char ans[1010];

void init()
{
	scanf("%d%d",&n,&len);
	for (int i=0; i<n; i++)
		scanf("%s",dna[i]);	
}

void work()
{
	int all=0;
	for (int i=0; i<len; i++)
	{
		char use;
		int min=-1;
		for (int j=0; j<4; j++)
		{
			char u=tmp[j];
			int cnt=0;
			for (int k=0; k<n; k++)
				if (dna[k][i]!=u) cnt++;
			if (cnt<min || min<0)
			{
				min=cnt;
				use=u;	
			}
		}
		ans[i]=use;
		all+=min;
	}	
	ans[len]=0;
	printf("%s\n%d\n",ans,all);
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		init();
		work();	
	}
	return 0;	
}
