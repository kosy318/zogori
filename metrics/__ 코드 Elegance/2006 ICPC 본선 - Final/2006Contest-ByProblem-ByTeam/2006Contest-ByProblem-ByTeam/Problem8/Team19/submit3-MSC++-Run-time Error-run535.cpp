#include <stdio.h>
#include <string.h>
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 500
typedef struct{
	int cost;
	int parent;
}cell;

cell m[MAXLEN + 1][MAXLEN + 1];
void row_init(int i)
{
	m[0][i].cost = i;
	if(i > 0)
		m[0][i].parent = INSERT;
	else
		m[0][i].parent = -1;
}

void column_init(int i)
{
	m[i][0].cost = i;
	if(i > 0)
		m[i][0].parent = DELETE;
	else
		m[i][0].parent = -1;
}
int match(char c, char d)
{
	if(c == d)
		return 0;
	else
		return 1;
}

int indel(char c)
{
	return 1;
}

void goal_cell(char *s, char *t, int *i, int *j)
{
	*i = strlen(s) - 1;
	*j = strlen(t) - 1;
}
int string_compare(char *s, char *t)
{
	int i, j, k;
	int opt[3];

	for(i = 0; i < MAXLEN; i++)
	{
		row_init(i);
		column_init(i);
	}

	for(i = 1; i < strlen(s); i++)
	{
		for(j = 1; j < strlen(t); j++)
		{
			opt[MATCH] = m[i-1][j-1].cost + match(s[i], t[j]);
			opt[INSERT] = m[i][j-1].cost + indel(t[j]);
			opt[DELETE] = m[i-1][j].cost + indel(s[i]);

			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;

			for(k = INSERT; k <= DELETE; k++)
			{
				if(opt[k] < m[i][j].cost)
				{
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
			}
		}
	}
	goal_cell(s, t, &i, &j);
	return m[i][j].cost;
}
int main()
{
	//printf("%d\n", string_compare("aabc", "xabb"));
	int nTestCase;
	char temp[2];
	// test case
	scanf("%d", &nTestCase);
	gets(temp);

	while(nTestCase--)
	{
		char str[100];
		char longStr[5002];
		char currStr[5020];
		int begin;
		int count;
		int k, min;
		currStr[0] = ' ';
		str[0] = ' ';
		gets(str + 1);
		gets(longStr + 1);
		begin = 0;
		min = 0;
		for(int i = 1; longStr[i]; i++)
		{
			if(begin == 0)
			{
				count = 1;
				currStr[count] = longStr[i];
				begin = 1;
			}
			else if(longStr[i] == str[1])
			{
				if(longStr[i] == str[count])
				{
					currStr[count] = longStr[i];
				}
				else
				{
					currStr[count] = '\0';
					k = string_compare(currStr, str);
					//printf("%d %s %s\n", k, currStr, str);
					if(min < k)
						min = k;
					count = 1;
					currStr[count] = longStr[i];
				}
			}
			else
			{
				currStr[count] = longStr[i];
			}
			//printf("%c %c ,", longStr[i], currStr[count]);
			count++;
		}
		
		currStr[count] = '\0';
//		printf("%s %s\n", str+1, currStr+1);
		k = string_compare(currStr, str);
		if(min < k)
			min = k;
//		printf("%d\n", min);
		if(min > strlen(str+1))
            printf("%d\n", strlen(str+1));
		else
			printf("%d\n", min);
	}
	return 0;
}