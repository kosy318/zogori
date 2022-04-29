#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int) x.size()
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()

int c[2];

struct P {
	int x, y;
	int t;
	bool operator<(const struct P &A) const {
		return x<A.x;
	}
};
vector<P> d;

struct node {
	ll m, l, r, s;
} IT[5100];
int B;
void init(int N) {
	for(B=1; B<=N; B*=2);
	for(int i=1; i<=2*B; i++) {
		IT[i].m = IT[i].l = IT[i].r = IT[i].s = 0;
	}
}

void add(int x, int v) {
	x += B;
	IT[x].m += v;
	IT[x].l += v;
	IT[x].r += v;
	IT[x].s += v;
	while(x /= 2) {
		auto &u = IT[x];
		auto &l = IT[x*2];
		auto &r = IT[x*2+1];
		u.s = l.s + r.s;
		u.l = max(l.l, l.s + r.l);
		u.r = max(r.r, r.s + l.r);
		u.m = max({l.m, r.m, l.r + r.l});
	}
}

ll getMax() {
	return IT[1].m;
}

int main () {
	int n1, n2, n, x, y;
	vector<int> Y;
	scanf("%d", &n1);
	for(int i=0; i<n1; i++) {
		scanf("%d%d", &x, &y);
		Y.push_back(y);
		d.push_back({x, y, 0});
	}
	scanf("%d", &n2);
	for(int i=0; i<n2; i++) {
		scanf("%d%d", &x, &y);
		Y.push_back(y);
		d.push_back({x, y, 1});
	}
	
	scanf("%d%d", c, c+1); 
	c[1] = -c[1];
	
	sort(all(Y));
	Y.erase(unique(all(Y)), Y.end());
	for(auto &p: d) {
		p.y = lower_bound(all(Y), p.y) - Y.begin();
	}
	
	sort(all(d));
	ll M = 0;
	n = n1 + n2;
	for(int i=0, j; i<n; i=j) {
		init(Y.size());
		for(int u=i, v; u<n; u=v) {
			for(v=u; v<n && d[u].x == d[v].x; v++) {
				add(d[v].y, c[d[v].t]);
			}
			ll t = getMax();
//			printf("__%d %d %d\n", i, v, t); 
			if(M < t) M = t;
		}
		for(j=i; j<n && d[i].x == d[j].x; j++);
	}
	printf("%lld\n", M);
	return 0;
}

