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

int main(){
	fio;
	int n;
	cin >> n;
	for(int i = 4; i <= n; i++){
		dp[i] = dp[(i+2)/2] + 1;
	}
	if(n <= 4){
		cout << n - 3 << '\n';
		return 0;
	}
	switch(n % 3){
		case 0:
			cout << dp[n/3+1] * 2 + 2 << '\n';
			break;
		case 1:
			cout << dp[n/3+1] + dp[n/3+2] + 2 << '\n';
			break;
		case 2:
			cout << dp[n/3+2] * 2 + 2 << '\n';
			break;
	}
}
