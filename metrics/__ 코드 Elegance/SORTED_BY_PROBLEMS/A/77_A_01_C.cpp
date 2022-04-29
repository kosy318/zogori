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

int a[1005] = {1,1};
int n;
unordered_set<int> ok;

int main(){
	fio;
	cin >> n;
	for(int i = 2; i <= n; i++){
		ok.clear();
		for(int j = 1; i - 2 * j >= 0; j++){
			ok.insert(2 * a[i-j] - a[i-2*j]);
		}
		for(int x = 1;;x++){
			if(!ok.count(x)){
				a[i] = x;
				break;
			}
		}
	}
	cout << a[n] << '\n';
}
