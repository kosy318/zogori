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

int dp[1000005];
int dia(int n){
	int &d = dp[n];
	if(d) return d;
	if(n <= 3) return 0;
	if(n == 4) return d = 1;
	switch(n % 3){
		case 0:
		return d = 2 * dia(n/3 + 1) + 2;
		case 1:
		return d = dia((n+2)/3 + 1) + dia(n/3 + 1) + 2;
		case 2:
		return d = 2 * dia((n+2)/3 + 1) + 2;
	}
	return 0;
}

int main(){
	fio;
	int n;
	cin >> n;
	cout << dia(n) << '\n';
}
