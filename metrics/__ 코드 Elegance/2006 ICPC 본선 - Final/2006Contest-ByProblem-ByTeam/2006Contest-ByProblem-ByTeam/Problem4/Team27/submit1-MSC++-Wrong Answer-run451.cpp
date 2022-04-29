#include <cstdio>
#include <stack>

using namespace std;

int n;
bool connected[1001][1001];
int f1[2], f2[2];
int dfs_num[1001];
int back[1001];
int now_dfs_num;
bool check;

stack<int> tt;

void dfs(int now)
{
	int i;
	int min;
	int cnt, temp;

	tt.push(now);

	dfs_num[now] = now_dfs_num++;

	back[now] = dfs_num[now];
	
	for(i = 1 ; i <= n ; i++)
	{
		if(connected[now][i])
		{
			if(dfs_num[i] == -1)
			{
				dfs(i);
				if(back[now] > back[i])
					back[now] = back[i];
				if (back[i] == dfs_num[now])
				{
					cnt = 0;
					while (tt.top() != now)
					{
						temp = tt.top();
						tt.pop();

						//printf("%d ", temp);

						if(temp == f1[0] || temp == f1[1] || temp == f2[0] || temp == f2[1])
							cnt++;

					}
					if(tt.top() == f1[0] || tt.top() == f1[1] || tt.top() == f2[0] || tt.top() == f2[1])
						cnt++;

					//printf("%d\n", tt.top());

					if(cnt == 4)
						check = true;
				}
			}
			else
			{
				if(back[now] > dfs_num[i])
					back[now] = dfs_num[i];
			}
		}
	}
}

int main()
{
	int case_num, now_case;
	int m, f;
	int i, j;
	int a, b;

	scanf("%d", &case_num);

	for(now_case = 0 ; now_case < case_num ; now_case++)
	{
		scanf("%d %d", &n, &m);

		for(i = 1 ; i <= n ; i++)
			for(j = 1 ; j <= n ; j++)
				connected[i][j] = false;

		for(i = 0 ; i < m ; i++)
		{
			scanf("%d %d", &a, &b);
			connected[a][b] = connected[b][a] = true;
		}

		scanf("%d %d", &f1[0], &f1[1]);
		scanf("%d %d", &f2[0], &f2[1]);

		scanf("%d", &f);

		for(i = 0 ; i < f ; i++)
		{
			scanf("%d %d", &a, &b);
			connected[a][b] = connected[b][a] = false;
		}

		now_dfs_num = 0;
		for(i = 1 ; i <= n ; i++)
			dfs_num[i] = -1;

		check = false;

		dfs(f1[0]);

		if(check)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
