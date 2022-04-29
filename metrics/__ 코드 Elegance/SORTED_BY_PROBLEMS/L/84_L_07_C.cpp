#include <bits/stdc++.h>
#define int long long
#define N 200005
#define ii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
using namespace std;

vector<ii> V[N];
int F[N],m,n,i,val[N],l,r,x,dp,mx;

int qry(int x){
	int t = 0;
	for(; x ; x -= x&-x)
		t = max(t , F[x]);
	return t;
}


void up(int x, int t){
	for(; x < N ; x += x&-x)
		F[x] = max(t , F[x]);
}

signed main() {
		cin >> m >> n;
		for(i=1;i<=m;i++) scanf("%lld",&val[i]);
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&l,&r,&x);
			V[r].pb(mp(l,val[x]*(r-l)));
		}
		
		for(i=1;i<N;i++){
			for(auto t: V[i]){
				dp = qry(t.st) + t.nd;
				mx = max(mx,dp);
				up(i,dp);
				//cout << t.st << " " << i << " " << dp << endl;
			}
		}		
		
		cout << mx;
		return 0;
}
