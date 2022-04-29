#include<stdio.h>

char string[50][1001];
char result[1000];
int agct[4];
int resultNum;
int m, n;

void input();
void getresult();

int main()
{
	int t;
	int i;

	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		resultNum = 0;
		input();
		getresult();

	}
	return 0;
}

void input()
{
	int i, j;

	scanf("%d %d", &m, &n);

	for(i=0; i<m; i++)
	{
		getchar();
		for(j=0; j<n; j++)
		{
			scanf("%c", &string[i][j]);
		}
	}
}

void getresult()
{
	int i, j;
	int max, index;

	for(i=0; i<n; i++)
	{
		agct[0] = agct[1] = agct[2] = agct[3] = 0;
		for(j=0; j<m; j++)
		{
			if(string[j][i] == 'A')
				agct[0]++;
			else if(string[j][i] == 'G')
				agct[1]++;
			else if(string[j][i] == 'C')
				agct[2]++;
			else if(string[j][i] == 'T')
				agct[3]++;
		}

		max = agct[0];
		index = 0;

		for(j=1; j<4; j++)
		{
			if(max < agct[j])
			{
				max = agct[j];
				index = j;
			}
		}

		if(index == 0)
		{
			result[i] = 'A';
			resultNum += (m - agct[index]);
		}
		else if(index == 1)
		{
			result[i] = 'G';
			resultNum += (m - agct[index]);
		}
		else if(index == 2)
		{
			result[i] = 'C';
			resultNum += (m - agct[index]);
		}
		else if(index == 3)
		{
			result[i] = 'T';
			resultNum += (m - agct[index]);
		}
		
	}

	for(i=0; i<n; i++)
	{
		printf("%c", result[i]);
	}
	printf("\n");
	printf("%d", resultNum);
	printf("\n");
}
