#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#define START int testcase; \
	cin >> testcase;\
	while(testcase--)

#define LOOP(a, b, c) for(int a = b ; a < c ; a++)
#define FOR(a, b) LOOP(a, 0, b)

using namespace std;

#define MATCH	0
#define INSERT	1
#define DELETE	2
#define MAXLEN 51

typedef struct
{
	int cost;
	int parent;
} cell;

cell m[MAXLEN+1][MAXLEN+1];

int match(char c, char d)
{
	if( c==d) return 0;
	else return 1;
}

int indel(char c, char d)
{
	if( c==d) return 1;
	else return 2;
}


void goal_cell(char* s, char* t, int& i, int& j)
{
	i = strlen(s)-2;
	j = strlen(t)-2;
}
int sc(char* s, char* t, int b, int e)
{
	int i, j, k;
	int opt[3];

	FOR(i, MAXLEN)
	{
		m[0][i].cost = i;
		if(i > 0)
		{
			m[0][i].parent = INSERT;
		}
		else
		{
			m[0][i].parent = -1;
		}
	}

	FOR(i, MAXLEN)
	{
		m[i][0].cost = i;
		if(i > 0)
		{
			m[i][0].parent = INSERT;
		}
		else
		{
			m[i][0].parent = -1;
		}
	}

	LOOP(i, 1, strlen(s)+2)
	{
		LOOP(j, 1, e-b+2)
		{
			opt[MATCH] = m[i-1][j-1].cost + match(s[i], t[j]);
			opt[INSERT] = m[i][j-1].cost + 1;
			opt[DELETE] = m[i-1][j].cost + 1;

			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for(int k = INSERT ; k <= DELETE ;k++)
			{
				if(opt[k] < m[i][j].cost)
				{
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
			}
		}
	}

	goal_cell(s, t, i, j);
	return m[i][j].cost;
}

int main()
{
	vector<int> results;

	START
	{
		char s[51];
		char nt[5001];

		char t[51];

		s[0] = ' ';
		t[0] = ' ';

		scanf("%s", &(s[1]));
		scanf("%s", &nt);

		int begin = 0;
		int end = strlen(s);

		int match_val = 0;
		int delete_val = 0;

		int k;
		for(int i = 0 ; i + end <= strlen(nt) ; )
		{
			//MATCH
			t[0] = ' ';
			for(int j = begin, k = 1 ; j < end ; j++, k++)
			{
				t[k] = nt[j];
			}
			t[k] = '\0';
			
			int maxlen = strlen(t);
			end = begin + maxlen-2;

			match_val = sc(s, t, begin, end+1);
			//insert
			delete_val = sc(s, t, begin, end);

			if(delete_val > match_val)
			{
				begin = end +1;
				end = begin + strlen(s)-1;
			}
			else
			{
				begin = end+1;
				end = begin + strlen(s)-1;
			}
		
			results.push_back(max(match_val, delete_val));
		}
		cout << *max_element(results.begin(), results.end()) << endl;
	}
}