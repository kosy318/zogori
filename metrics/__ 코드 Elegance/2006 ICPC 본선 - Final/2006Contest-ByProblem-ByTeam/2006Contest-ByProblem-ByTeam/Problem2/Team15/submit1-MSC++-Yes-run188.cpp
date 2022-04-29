#include <stdio.h>

void process();
void find_error();


int T;
int m;
int strlenth;
char str[60][1000];
char result[1000];

void main()
{
	scanf("%d", &T);

	for(int i=0; i<T; i++)
	{
		int cnt=0;
		scanf("%d%d", &m, &strlenth);
		for(int j=0; j<m; j++)
		{
			scanf("%s", &(str[j]));
		}

		process();
		for(int y=0; y<m; y++)
		{
			
			for(int z=0; z<strlenth; z++)
			{
				if(result[z] != str[y][z])	cnt++;
			}
		}
		printf("\n%d\n", cnt);
		m = 0;
		strlenth = 0;
	}
}

void process()
{
	char alpha[26];
	int max = 0;
	int idx;
	int t;

	for(int spy = 0; spy < 26; spy++)
		alpha[spy] = spy+65;
	for(int i=0; i<strlenth; i++)
	{
		int cnt[26]={0,};
		for(int j=0; j<m; j++)
		{
			t = str[j][i] - 65;
			cnt[t]++;
		}
		
		max = 0;
		for(j=0; j<26; j++)
		{
			if(cnt[j] > max)
			{
				max = cnt[j];
				idx = j;
			}
		}		
		result[i] = idx + 65;
		printf("%c", result[i]);
	}
}

void find_error()
{
}