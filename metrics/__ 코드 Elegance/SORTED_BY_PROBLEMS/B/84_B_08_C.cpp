#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) ((int)x.size())
#define N 100005
#define ii pair<int,int>
#define st first
#define nd second
using namespace std;

int n;
ll ans;
ll sum[N],tot[N],sq[N];
vector<ii> v[N];

void dfs(int node,int dad) {
	
	if(sz(v[node])==1) tot[node]=1;

	for(auto x:v[node]) {
		
		int go=x.st;
		int c=x.nd;
		
		if(go==dad) continue ;
		
		dfs(go,node);
		
		sq[go]+=(ll)c*c*tot[go]+2*sum[go]*c;
		sq[node]+=sq[go];
		
		sum[go]+=tot[go]*c;
	
		ans+=sum[go]*sum[node]*2;
		
		tot[node]+=tot[go];
		sum[node]+=sum[go];
		
	}
	
	for(auto x:v[node]) {
		
		int go=x.st;	
		
		if(go==dad) continue ;
		
		ans+=(tot[node]-tot[go])*sq[go];
		
	}
	
}

int main() {
	
	scanf("%d",&n);
	
	for(int i=1;i<n;i++) {
		
		int a,b,c;
		
		scanf("%d %d %d",&a,&b,&c);
		
		v[a].pb({b,c});
		v[b].pb({a,c});
				
	}
	
	int root=1;
	
	for(int i=1;i<=n;i++) {
		
		if(sz(v[i])>1) root=i;
		
	}
	
	dfs(root,0);
		
	printf("%lld",ans);
}
