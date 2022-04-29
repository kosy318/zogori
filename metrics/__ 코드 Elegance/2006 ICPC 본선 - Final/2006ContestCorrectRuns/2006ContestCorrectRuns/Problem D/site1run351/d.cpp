#include <cstdio>
#include <queue>

using namespace std;

#define MAX 1010
#define VMAX 10000000

int F[MAX][MAX];
int P[MAX];
int n, s, t;

int ap()
{
	int i, j, m;
	queue<int> Q;

	Q.push(s);
	memset(P, -1, sizeof(P));
	while(!Q.empty() && P[t] == -1)
	{
		i = Q.front(), Q.pop();
		for(j = 1; j <= t; j++)
			if(F[i][j] > 0 && P[j] == -1) P[j] = i, Q.push(j);
	}	
	if(P[t] == -1) return 0;
	else 
	{
		for(i = P[j = t], m = VMAX; j != s; i = P[j = i])
			if(m > F[i][j]) m = F[i][j];
		return m;
	}
}

int main()
{
	int tc;
	int a, b, c, d, x, y;
	int i, j, k, m, f, sum;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		memset(F, 0, sizeof(F));
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			F[a][b] = F[b][a]  = 1;
		}
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d", &k);
		for (i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			F[x][y] = F[y][x] = 0;
		}

		s = 0, t = n+1;
		if (a == c) {
			F[s][b] = 1;
			F[d][t] = 1;
			for (i = 0; i <= n+1; i++) {
				F[a][i] = F[i][a] = 0;
			}
		}
		else if (a == d) {
			F[s][b] = 1;
			F[c][t] = 1;
			for (i = 0; i <= n+1; i++) {
				F[a][i] = F[i][a] = 0;
			}
		}
		else if (b == c) {
			F[s][a] = 1;
			F[d][t] = 1;
			for (i = 0; i <= n+1; i++) {
				F[b][i] = F[i][b] = 0;
			}
		}
		else if (b == d) {
			F[s][a] = 1;
			F[c][t] = 1;
			for (i = 0; i <= n+1; i++) {
				F[b][i] = F[i][b] = 0;
			}
		}
		else {
			F[s][a] = 1;
			F[s][b] = 1;
			F[c][t] = F[d][t] = 1;
		}

		for(sum = 0; f = ap(); sum += f)
		{
			for(i = P[j = t]; j != s; i = P[j = i])
				F[i][j] -= f, F[j][i] += f;
		}
		if (a != c && a != d && b != c && b != d) {
			if (sum == 2)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			if (sum == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
