#include <stdio.h>

char data[50][1001];
int tn;
int n,m;
int cnt[4];
int sum;
char a[4] = {'A','C','G','T'};

int main()
{
	int i,j,maxi;
//	freopen("input.txt","r",stdin);
	scanf("%d",&tn);
	while(tn--)
	{
		scanf("%d %d",&n,&m);

		for(i = 0 ; i < n ; i++)
		{
			scanf("%s",data[i]);
		}

		sum = 0;
		for(i = 0 ; i < m ; i++)
		{
			for(j = 0 ; j < 4 ; j++)
			{
				cnt[j] = 0;
			}
			for(j = 0 ; j < n ; j++)
			{
				if(data[j][i] == 'A')
					cnt[0]++;
				else if(data[j][i] == 'C')
					cnt[1]++;
				else if(data[j][i] == 'G')
					cnt[2]++;
				else if(data[j][i] == 'T')
					cnt[3]++;
			}
			maxi = 0;
			for(j = 0 ; j < 4 ; j++)
			{
				if(cnt[maxi] < cnt[j])
					maxi = j;
			}

            sum += n-cnt[maxi];
			printf("%c",a[maxi]);
		}
		printf("\n");
		printf("%d\n",sum);
	}
	return 0;
}