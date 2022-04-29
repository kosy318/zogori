#include <bits/stdc++.h>
#define fs first
#define se second
#define va first
#define vb second
#define y0 qweriuot
#define y1 asdfjklhaks
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pp push_back
#define ep emplace_back

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using ll = long long; using llong = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;

int n;
pii c[1005][55];
int lad[55];
vector<pii> tans;

int main(){
	fio;
	cin >> n;
	for(int i = 1; i < n; i++){
		int a, cnt = 0;
		while(1){
			cin >> a;
			if(!a) break;
			c[a][i] = pii(++cnt, i);
		}
	}
	iota(lad + 1, lad + n + 1, 1);
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; j < n; j++){
			if(c[i][j].va) swap(lad[j], lad[j+1]);
		}
	}
	vector<pair<int,pii>> ans;
	for(int i = 1; i <= n; i++){
		ans.clear();
		int cur = lad[i];
		for(int j = 1000; j >= 1; j--){
			c[j][cur] = pii(0,0);
			if(c[j][cur-1].va){ 
				ans.ep(cur - 1, c[j][cur-1]); 
				--cur;
			}
		}
		reverse(ans.begin(), ans.end());
		for(int k = lad[i] - 1; k >= 1; k--){
			for(int j = 1000; j >= 1; j--){
				if(c[j][k] == ans[k-1].vb) break;
				if(!c[j][k].va) continue;
				c[j][k+1] = c[j][k];
				c[j][k] = pii(0,0);
			}
		}
		int L = lad[i];
		for(int k = 1; k <= n; k++){
			if(lad[k] < L) ++lad[k];
		}
		for(auto v : ans){
			tans.ep(v.vb);
		}
	}
	cout << tans.size() << '\n';
	for(pii p : tans){
		cout << p.vb << ' ' << p.va << '\n';
	}
}
