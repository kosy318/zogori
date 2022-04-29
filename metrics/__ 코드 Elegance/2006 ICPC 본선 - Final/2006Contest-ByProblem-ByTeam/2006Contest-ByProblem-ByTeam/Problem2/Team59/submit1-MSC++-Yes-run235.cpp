#include<stdio.h>
#include<string.h>

int cnt[1001][4];
int max[1001];
char in[1001];
int data[51][1001];
int n,m,t;
int out[1001];


void output()
{
	int i,j,chkn;
	for(i=0; i<m; i++)
	{
		if(out[i] == 0)
			printf("A");
		if(out[i] == 1)
			printf("C");
		if(out[i] == 2)
			printf("G");
		if(out[i] == 3)
			printf("T");
	}
	printf("\n");
	chkn=0;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(data[j][i] != out[i])
			{
				chkn++;
			}
		}
	}
	printf("%d\n",chkn);
}

void pro()
{
	int i,j,k,l,max,maxn;
	scanf("%d",&t);
	for(i=1; i<=t; i++)
	{
		scanf("%d %d",&n,&m);
		for(j=0; j<m; j++)
			for(l=0; l<4; l++)
				cnt[j][l]=0;
		for(k=0; k<n; k++)
		{
			scanf("%s",in);
			for(j=0; j<m; j++)
			{
				if(in[j] == 'A')
				{
					cnt[j][0]++;
					data[k][j]=0;
				}
				if(in[j] == 'C')
				{
					cnt[j][1]++;
					data[k][j]=1;
				}
				if(in[j] == 'G')
				{
					cnt[j][2]++;
					data[k][j]=2;
				}
				if(in[j] == 'T')
				{
					cnt[j][3]++;
					data[k][j]=3;
				}
			}
		}
		for(j=0; j<m; j++)
		{
			max=cnt[j][0];
			maxn=0;
			for(k=1; k<4; k++)
			{
				if(cnt[j][k] > max)
				{
					max=cnt[j][k];
					maxn=k;
				}
			}
			out[j]=maxn;	
		}
		output();
	}
}


void main()
{
	pro();
}