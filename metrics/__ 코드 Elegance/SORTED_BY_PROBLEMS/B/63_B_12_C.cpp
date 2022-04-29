#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define pb push_back
typedef long long LL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
LL siz[MXN];
LL v1[MXN], v2[MXN], ans = 0;
vector<PII> edge[MXN];
void dfs(int u, int pa) {
	bool f = true;
	for (PII x : edge[u]) {
		if (x.F == pa) continue ;
		f = false; break ;
	}
	if (f) siz[u] = 1;
	for (PII x : edge[u]) {
		if (x.F == pa) continue ;
		dfs(x.F, u);
		int d = x.S;
		v2[x.F] += 2*d*v1[x.F] + siz[x.F]*d*d;
		v1[x.F] += siz[x.F]*d;
		ans += siz[u]*v2[x.F];
		ans += siz[x.F]*v2[u];
		ans += 2*v1[x.F]*v1[u];
		siz[u] += siz[x.F];
		v2[u] += v2[x.F];
		v1[u] += v1[x.F];
	}
}
int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		edge[u].pb({v, d});
		edge[v].pb({u, d});
	}
	int rt = 0;
	for (int i = 1; i <= n; i++)
		if (SZ(edge[i]) >= 2) {
			rt = i; break ;
		}
	dfs(rt, 0);
	LDB a1 = (LDB) ans;
	printf("%.0Lf\n", a1);
	return 0;
}

