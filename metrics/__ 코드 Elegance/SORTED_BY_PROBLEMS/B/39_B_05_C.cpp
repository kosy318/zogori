#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

using ll = long long;
using pil = pair<int, ll>;

const int N = 100005;

int n, sz[N], leaf[N], chk[N];
vector<pil> e[N];
ll ans;

int sf(int x, int y){
	sz[x] = 1;
	for(pil i : e[x]) if(!chk[i.x] && i.x != y) sz[x] += sf(i.x, x);
	return sz[x];
}

int cf(int x, int y, int t){
	for(pil i : e[x]) if(!chk[i.x] && i.x != y && sz[i.x] > t / 2)
		return cf(i.x, x, t);
	return x;
}

void g(int x, int y, ll d, vector<ll> &v){
	if(leaf[x]) v.push_back(d);
	for(pil i : e[x]) if(!chk[i.x] && i.x != y) g(i.x, x, d + i.y, v);
}

void f(int x){
	x = cf(x, 0, sf(x, 0));
	chk[x] = 1;
	ll C = leaf[x], D = 0, S = 0;
	for(pil i : e[x]){
		if(chk[i.x]) continue;
		ll TC = 0, TD = 0, TS = 0;
		vector<ll> v;
		g(i.x, x, i.y, v);
		for(ll t : v){
			ans += C * t * t;
			ans += 2 * D * t;
			ans += S;
			TC++;
			TD += t;
			TS += t * t;
		}
		C += TC; D += TD; S += TS;
	}
	for(pil i : e[x]) if(!chk[i.x]) f(i.x);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int x, y; ll z;
		scanf("%d%d%lld", &x, &y, &z);
		e[x].emplace_back(y, z);
		e[y].emplace_back(x, z);
	}
	for(int i = 1; i <= n; i++) leaf[i] = (e[i].size() == 1);
	f(1);
	printf("%lld\n", ans);
}
