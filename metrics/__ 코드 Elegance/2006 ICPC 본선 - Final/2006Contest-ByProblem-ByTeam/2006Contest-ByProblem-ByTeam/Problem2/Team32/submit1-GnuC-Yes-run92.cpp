#include <stdio.h>
int main()
{
	int t;
	char ans[4]={'A','C','G','T'};
	scanf("%d",&t);
	while(t>0)
	{
		int m,n;
		char map[50][1000];
		int cc[4],err=0;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			scanf("%s",map[i]);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<4;k++)
				cc[k]=0;
			int max=0,maxi=0;
			for(int i=0;i<m;i++)
			{
				switch(map[i][j])
				{
					case 'A':
						cc[0]++;
						break;
					case 'C':
						cc[1]++;
						break;
					case 'G':
						cc[2]++;
						break;
					case 'T':
						cc[3]++;
						break;
				}
			}
			for(int k=0;k<4;k++)
			{
				if(cc[k]>max)
				{
					maxi=k;
					max=cc[k];
				}		
			}
			err=err+m-max;
			printf("%c",ans[maxi]);
		}
		printf("\n%d\n",err);
		t--;
	}
	return 0;
}
