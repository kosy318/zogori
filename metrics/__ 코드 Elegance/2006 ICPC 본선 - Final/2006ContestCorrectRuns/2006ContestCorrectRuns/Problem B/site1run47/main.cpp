#include <stdio.h>

#define MAXLEN 10000

char *ss = "ACGT";

int GetID(char c)
{
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'G') return 2;
	if(c == 'T') return 3;
	return -1;
}
int n, len;
int count[MAXLEN+1][4];
char str[MAXLEN+1];

int main()
{
	int ca, id;
	int i, j, ans;
	scanf("%d", &ca);
	while(ca-- > 0)
	{
		scanf("%d %d", &n, &len);
		for(i=1;i<=len;i++) for(j=0;j<4;j++) count[i][j] = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%s", str);
			for(j=0;j<len;j++)
			{
				count[j+1][GetID(str[j])] ++;
			}
		}
		ans = 0;
		for(i=1;i<=len;i++)
		{
			id = -1;
			for(j=0;j<4;j++)
			{
				if(id == -1 || count[i][j] > count[i][id])
				{
					id = j;
				}
			}
			str[i-1] = ss[id];
			ans += n - count[i][id];
		}
		str[len] = 0;
		printf("%s\n%d\n", str, ans);
	}
	return 0;
}