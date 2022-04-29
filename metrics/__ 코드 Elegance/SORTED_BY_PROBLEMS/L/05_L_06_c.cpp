#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second

int m, n;
vector<pll> V[15123];
ll dp[15123], price[123];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> m >> n;
    for(int i=1; i<=m; ++i){
        cin >> price[i];
    }
    for(int i=0; i<n; ++i){
        ll s, e, t;
        cin >> s >> e >> t;
        V[e].push_back({s,t});
    }

    dp[0] = 0;
    for(int i=1; i<=15000; ++i){
        dp[i] = dp[i-1];
        for(auto &p : V[i]){
            dp[i] = max(dp[i], dp[p.xx] + (i - p.xx)*price[p.yy]);
        }
    }
    cout << dp[15000];
}
