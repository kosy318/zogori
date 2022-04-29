#include <stdio.h>

int T;
int graph[1001][1001];
int edge[1001][1001];
int nedge[1001];
int N, E;

int f11, f12, f21, f22;
int id[1001], cid, cnt;
int rid[1001];
int p[1001];
int group[1001];
int parent[1001];

int bicon(int u)
{
	int i, v, pp, t;

	pp = id[u] = ++cid;
	rid[cid] = u;

	for (i = 1; i <= nedge[u]; i++)
	{
		v = edge[u][i];
		if (id[v])
		{
			if (id[v] < pp && parent[u] != v) pp = id[v];
		}
		else
		{
			//if (u == 1) cnt++;
			parent[v] = u;
			t = bicon(v);
			if (t < pp) pp = t;
		}
	}

	p[u] = rid[pp];
	return pp;
}

int main()
{
	int i, j;
	int u, v;
	int t1, t2;
	int goal, flag;

	scanf("%d", &T);
	while (--T >= 0)
	{
		cid = cnt = 0;
		for (i = 1; i <= 1000; i++)
		{
			nedge[i] = id[i] = group[i] = parent[i] = 0;
			for (j = 1; j <= 1000; j++) graph[i][j] = 0;
		}

		scanf("%d%d", &N, &E);
		for (i = 1; i <= E; i++)
		{
			scanf("%d%d", &t1, &t2);
			graph[t1][t2] = graph[t2][t1] = 1;
		}

		scanf("%d%d%d%d", &f11, &f12, &f21, &f22);

		scanf("%d", &j);
		for (i = 1; i <= j; i++)
		{
			scanf("%d%d", &t1, &t2);
			graph[t1][t2] = graph[t2][t1] = 0;
		}

		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (graph[i][j] == 1)
					edge[i][++nedge[i]] = j;
		for (i = 1; i <= N; i++)
			if (id[i] == 0) bicon(i);

		for (i = N; i >= 1; i--)
		{			
			v = rid[i];
			//if (group[v]) continue;
			goal = p[v];
			group[v] = ++cnt;
			if (v == f11) flag = 1; else flag = 0;
			while (parent[v] != 0 && v != goal)
			{
				u = parent[v];
				group[u] = cnt;
				if (u == f11) flag = 1;
				if (u == goal) break;
				v = u;
			}
			if (flag == 1)
			{
				if (group[f11] != 0 && group[f11] == group[f12] && group[f12] == group[f21] && group[f21] == group[f22]) 
				{
					printf("YES\n");
					break;
				}
			}
		}
		if (i == 0) printf("NO\n");
	}
}