#include <stdio.h>
#include <algorithm>

using namespace std;

int lg[10000];

int tn,n,k;
int st;

int main()
{
	int i,cnt,max;
//	freopen("input.txt","r",stdin);
	scanf("%d",&tn);
	while(tn--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
	
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&lg[i]);
		}

		sort(&lg[0],&lg[n]);
		st = 0;
		max = 0;
		cnt = 1;
		for(i = 1 ; i < n ; i++)
		{
			if(i-st > 2)
			{
				if((lg[i] - lg[i-2]) > k)
				{
					if((lg[i] - lg[i-1]) > k)
					{
						st = i;
						cnt--;
					}
					else
					{
						st = i-1;
						i--;
					}
					if(max < cnt)
					{
						max = cnt;
						cnt = 0;
					}
				}
			}
			else
			{
				if(lg[i] - lg[st] > k)
				{
					if((lg[i] - lg[i-1]) > k)
					{
						st = i;
						cnt--;
					}
					else
					{
						st = i-1;
						i--;
						cnt++;
					}
					if(max < cnt)
					{
						max = cnt;
						cnt = 0;
					}
				}
			}
			cnt++;
		}

		if(cnt > max)
			max = cnt;

		printf("%d\n",max);
	}
	
	return 0;
}