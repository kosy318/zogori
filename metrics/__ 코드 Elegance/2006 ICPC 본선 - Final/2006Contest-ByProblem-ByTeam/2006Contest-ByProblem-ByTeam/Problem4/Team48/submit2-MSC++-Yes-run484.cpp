#include <cstdio>
#include <algorithm>

int vertex, s, t, cap[3005][3005];
int path[2000];
bool visit[2000];

int flow();
int dfs(int st, int en, int depth);

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vertex = (n + 1) * 2;
		for (int i = 0; i < vertex; ++i)
			for (int j = 0; j < vertex; ++j)
				cap[i][j] = 0;
		for (int i = 0; i < n; ++i)
			cap[2 * i][2 * i + 1] = 1;
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			cap[2 * u + 1][2 * v] = 1;
			cap[2 * v + 1][2 * u] = 1;
		}
		int a, b, c, d;
		scanf("%d%d", &a, &b);
		scanf("%d%d", &c, &d);
		--a, --b, --c, --d;
		{
			int temp;
			scanf("%d", &temp);
			while (temp--) {
				int u, v;
				scanf("%d%d", &u, &v);
				--u, --v;
				cap[2 * u + 1][2 * v] = 0;
				cap[2 * v + 1][2 * u] = 0;
			}
		}
		cap[2 * a + 1][2 * b] = 0;
		cap[2 * b + 1][2 * a] = 0;
		cap[2 * c + 1][2 * d] = 0;
		cap[2 * d + 1][2 * c] = 0;
		cap[2 * n][2 * a] = 1;
		cap[2 * n][2 * b] = 1;
		cap[2 * c + 1][2 * n + 1] = 1;
		cap[2 * d + 1][2 * n + 1] = 1;
		//if (a == c || a == d)
		//	cap[2 * a][2 * a + 1] = 0;
		//if (b == c || b == d)
		//	cap[2 * b][2 * b + 1] = 0;
		s = 2 * n;
		t = 2 * n + 1;
		int tt = flow();
		if (tt >= 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int flow() {
	int ret = 0;
	while (true) {
		std::fill(visit, visit + vertex, false);
		int len = dfs(s, t, 0);
		if (len < 0)
			break;
		++ret;
		for (int i = 0; i < len - 1; ++i) {
			--cap[path[i]][path[i + 1]];
			++cap[path[i + 1]][path[i]];
		}
	}
	return ret;
}

int dfs(int st, int en, int depth) {
	if (visit[st])
		return -1;
	visit[st] = true;
	path[depth] = st;
	if (st == en)
		return depth + 1;
	for (int i = 0; i < vertex; ++i)
		if (cap[st][i] > 0) {
			int len = dfs(i, en, depth + 1);
			if (len >= 0)
				return len;
		}
	return -1;
}
