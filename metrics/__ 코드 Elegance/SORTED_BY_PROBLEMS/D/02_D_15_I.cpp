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

int N;
pii p[500500];
map<pii, vector<pii>> mp;
vector<pair<int, pii>> v;
vector<pii> ansv;
int cur[100100];
int main () {
	scanf("%d",&N);
	repp(i, N) cur[i] = i;
	repp (i, N-1){
		int d;
		for (int j = 1; j <= 1000000; j++) {
			scanf("%d",&d);
			if ( d == 0 ) break;
			v.push_back({d, {i, j}});
		}
	}

	sort(all(v));
	for (auto e : v){
		int a = e.Se.Fi, b = e.Se.Se;
		int x = cur[a], y = cur[a+1];
		
		if ( x > y ) swap(x,y);
		mp[{x,y}].push_back({a, b});
		//printf("(%d,%d) - [%d,%d]\n", x,y, a,b);
		swap(cur[a], cur[a+1]);
	}

	int inv = 0;
	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++) {
			if ( cur[i] > cur[j] ) inv++;
		}
	}


	for (auto &e : mp) {
		if ( sz(e.Se) % 2 == 1 ) ansv.push_back(e.Se.back());
	}
	
	assert( inv == sz(ansv) );
	if ( inv != sz(ansv) ) {
		while (true){
		}
	}
	printf("%d\n",sz(ansv));
	for (auto e : ansv) {
		printf("%d %d\n",e.first, e.second);
	}

}
