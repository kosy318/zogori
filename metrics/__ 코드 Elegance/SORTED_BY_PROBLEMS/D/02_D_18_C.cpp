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
int vis[55][55];
vector<pair<int, pii>> v;
vector<pair<int, pii>> ansv;
int die[100100];
int cur[100100], cur2[100100];
int main () {
	scanf("%d",&N);
	repp(i, N) cur[i] = cur2[i] = i;
	repp (i, N-1){
		int d;
		for (int j = 1; j <= 1000000; j++) {
			scanf("%d",&d);
			if ( d == 0 ) break;
			v.push_back({d, {i, j}});
		}
	}

	sort(all(v));
	while ( true ){
		bool found = false;
		for (int i = 1; i <= N; i++) for (int j = i + 1; j <= N; j++) vis[i][j] = -1;
		for (int i = 0; i < sz(v); i++){
			if ( die[i] ) continue;
			auto &e = v[i];
			int a = e.Se.Fi, b = e.Se.Se;
			int x = cur[a], y = cur[a+1];

			if ( x > y ) swap(x,y);

			if ( vis[x][y] != -1 ) {
				die[i] = 1;
				die[vis[x][y]] = 1;
				found = true;
				break;
			}

			vis[x][y] = i;

//			printf("[%d] (%d,%d) - [%d,%d]\n", e.Fi, x,y, a,b);
			swap(cur[a], cur[a+1]);
		}
		if( !found ) break;
	}

	for (int i = 0; i < sz(v); i++) {
		if( die[i] ) continue;
		auto &e = v[i];
		ansv.push_back({e.Fi, e.Se});
	}

	sort(all(ansv));
	printf("%d\n",sz(ansv));
	for (auto e : ansv) {
		printf("%d %d\n", e.Se.Fi, e.Se.Se);
	}
	/*
	for (auto e : ansv) {
		int a = e.Se.Fi;
		swap(cur2[a], cur2[a+1]);
	}
	for (int i = 1; i <= N; i++) printf("%d ", cur2[i]);
	*/
}
