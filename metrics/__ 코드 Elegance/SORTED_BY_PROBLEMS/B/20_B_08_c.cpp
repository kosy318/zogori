#include<bits/stdc++.h>
using namespace std;

vector< pair<int, long long> > g[100005];
int p[100005];
long long ans[100005][4];

void dfs(int x){
	if(g[x].size() == 1){
		ans[x][0] = 1;
		ans[x][1] = 0;
		ans[x][2] = 0;
		ans[x][3] = 0;
	}else{
		for(auto &nxt: g[x]){
			if(p[x] == nxt.first) continue;
			p[nxt.first] = x;
			dfs(nxt.first);
			ans[nxt.first][2] += (2 * nxt.second * ans[nxt.first][1]) + (nxt.second * nxt.second * ans[nxt.first][0]);
			ans[nxt.first][1] += (nxt.second * ans[nxt.first][0]);
			if(ans[x][0] == 0){
				ans[x][0] = ans[nxt.first][0];
				ans[x][1] = ans[nxt.first][1];
				ans[x][2] = ans[nxt.first][2];
			}else{
				ans[x][3] += (ans[x][2] * ans[nxt.first][0]) + (ans[nxt.first][2] * ans[x][0]) + (2 * ans[nxt.first][1] * ans[x][1]);
				ans[x][2] = (ans[x][2] + ans[nxt.first][2]);
				ans[x][1] = (ans[x][1] + ans[nxt.first][1]);
				ans[x][0] = (ans[x][0] + ans[nxt.first][0]);
			}
			//printf("%d %lld %lld %lld %lld\n", x, ans[x][0], ans[x][1], ans[x][2], ans[x][3]);
		}
	}
	//printf("%d %lld %lld %lld %lld\n", x, ans[x][0], ans[x][1], ans[x][2], ans[x][3]);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int aa, bb;
		long long cc;
		scanf("%d%d%lld", &aa, &bb, &cc);
		g[aa].push_back({bb, cc});
		g[bb].push_back({aa, cc});
	}
	int r = -1;
	for(int i=1;i<=n;i++){
		if(g[i].size() > 1){
			r = i;
			break;
		}
	}
	p[r] = r;
	dfs(r);	
	long long dap = 0;
	for(int i=1;i<=n;i++) dap += ans[i][3];
	printf("%lld\n", dap); 
}
