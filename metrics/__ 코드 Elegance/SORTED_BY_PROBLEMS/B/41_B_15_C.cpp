#include <bits/stdc++.h>
using namespace std;

#define int long long

using lint = long long;
using pint = pair<lint, lint>;
#define x first
#define y second

int n, o;
vector<pint> g[100004];

int sz[100004], sum[100004], sumsq[100004], ans[100004];
void dfs(int x, int p) {
	sz[x] = 0; sum[x] = 0; sumsq[x] = 0; ans[x] = 0;
	
	if (g[x].size() == 1) sz[x]++;
	for (pint i : g[x]) if (i.x != p) {
		dfs(i.x, x);
		ans[x] += ans[i.x] + sz[i.x] * sumsq[x] + sz[x] * sumsq[i.x] + i.y * i.y * sz[x] * sz[i.x] + 2 * sum[x] * sum[i.x] + 2 * i.y * (sum[x] * sz[i.x] + sz[x] * sum[i.x]);
		sumsq[x] += sumsq[i.x] + i.y * i.y * sz[i.x] + 2 * i.y * sum[i.x];
		sum[x] += sum[i.x] + i.y * sz[i.x];
		sz[x] += sz[i.x];
	}
//	cout << x << ' ' << sz[x] << ' ' << sum[x] << ' ' << sumsq[x] << ' ' << ans[x] << '\n';
}
/*
6
1 5 1
5 2 1
5 6 1
6 4 3
6 3 2
1 1 0 0 0
2 1 0 0 0
4 1 0 0 0
3 1 0 0 0
6 2 5 13 25
5 4 9 27 101
101
team041@icpc01:~$ ./b
10
1 2 10
10 2 7
3 2 8
3 9 3
9 8 2
7 9 1
6 4 3
4 5 2
3 4 4
1 1 0 0 0
10 1 0 0 0
8 1 0 0 0
7 1 0 0 0
9 2 3 5 9
6 1 0 0 0
5 1 0 0 0
4 2 5 13 25
3 4 22 126 475
2 6 71 883 4290
4290

*/

main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	
	for (o=1; g[o].size() == 1; o++);
	
	dfs(o, o);
	
	cout << ans[o] << '\n';
}
