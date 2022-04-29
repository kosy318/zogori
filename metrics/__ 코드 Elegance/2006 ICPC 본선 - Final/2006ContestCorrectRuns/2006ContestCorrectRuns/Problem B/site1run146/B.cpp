#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int T, m, n, i, j, count, max, matched[256]={0,};
	char Str[50][1001]={0,}, temp[1001]={0,};

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++)
			scanf("%s", Str[i]);

		count = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<256; j++)
				matched[j] = 0;

			for(j=0; j<m; j++)
				matched[Str[j][i]]++;
			
			max = 0;
			for(j=0; j<256; j++)
			{
				if(max < matched[j])
				{
					max = matched[j];
					temp[i] = j;
				}
			}
			count +=  m - max;
		}

		temp[n]='\0';
		printf("%s\n", temp);
		printf("%d\n", count);
	}	
	return 0;
}