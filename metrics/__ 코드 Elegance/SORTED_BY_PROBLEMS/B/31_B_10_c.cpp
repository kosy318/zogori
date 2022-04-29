#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
using lli = long long ;

int n;
vector<pii> adj[100001];

int sz[100001];
lli ps[100001],ss[100001],ans;

void dfs(int cur,int p) {
	if(adj[cur].size() == 1) {
		sz[cur] = 1;
		return;
	}
	
	for(auto &it:adj[cur]) if(it.se!=p) {
		dfs(it.se,cur);
		sz[cur] += sz[it.se];
	}
	for(auto &it:adj[cur]) if(it.se!=p) {
		lli css = ss[it.se] + 1ll*sz[it.se] * it.fi;
		lli cps = ps[it.se] + 2ll*it.fi*ss[it.se] + 1ll*sz[it.se] * it.fi * it.fi;

		ans += 2*ss[cur] * css;
		ans += cps * (sz[cur] - sz[it.se]);

		ps[cur] += cps;
		ss[cur] += css;
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) {
		scanf("%d%d%d",&u,&v,&w);
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}

	int root=1;
	for(int i=1;i<=n;i++) if(adj[i].size() > 1) {
		root=i;
		break;
	}

	dfs(root, 0);
	printf("%lld\n",ans);

	return 0;
}
