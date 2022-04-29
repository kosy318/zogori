#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 99999999
using namespace std;
int graph[1002][1002];
int path[1002];
int n, m;

int get_augment_path(int s, int t)
{
	int min1;
	int i, j, k;
	queue<int> q;
	q.push(s);
	memset(path, -1, sizeof(path));
	while (!q.empty() && path[t] == -1) {
		k = q.front();
		q.pop();
		for (i = 1; i <= t; i++) {
			if (path[i] == -1 && graph[k][i] > 0) {
				path[i] = k;
				q.push(i);
			}
		}
	}
	if (path[t] == -1) {
		return 0;
	}
	min1 = INF;
	j = t;
	for (i = path[j]; j != s; i = path[j=i]) {
		if (min1 > graph[i][j]) {
			min1 = graph[i][j];
		}
	}
	j = t;
	for (i = path[j]; j != s; i = path[j = i]) {
		graph[i][j] -= min1;
		graph[j][i] += min1;
	}
	return min1;
}

int main()
{
	int tc;
	int a, b, c, d, x, y;
	int i, j, k;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		memset(graph, 0, sizeof(graph));
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			graph[a][b] = graph[b][a]  = 1;
		}
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d", &k);
		for (i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			graph[x][y] = graph[y][x] = 0;
		}

		if (a == c) {
			graph[0][b] = 1;
			graph[d][n+1] = 1;
			for (i = 0; i <= n+1; i++) {
				graph[a][i] = graph[i][a] = 0;
			}
		}
		else if (a == d) {
			graph[0][b] = 1;
			graph[c][n+1] = 1;
			for (i = 0; i <= n+1; i++) {
				graph[a][i] = graph[i][a] = 0;
			}
		}
		else if (b == c) {
			graph[0][a] = 1;
			graph[d][n+1] = 1;
			for (i = 0; i <= n+1; i++) {
				graph[b][i] = graph[i][b] = 0;
			}
		}
		else if (b == d) {
			graph[0][a] = 1;
			graph[c][n+1] = 1;
			for (i = 0; i <= n+1; i++) {
				graph[b][i] = graph[i][b] = 0;
			}
		}
		else {
			graph[0][a] = 1;
			graph[0][b] = 1;
			graph[c][n+1] = graph[d][n+1] = 1;
		}

		d = 0;
		while ((c = get_augment_path(0, n+1)) > 0) {
			d += c;
		}
		if (a != c && a != d  && b != c && b != d) {
			if (d == 2)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			if (d == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
