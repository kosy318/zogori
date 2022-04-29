#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, n; cin>>T>>n;
    vector<ll> price(T+1);
    for(int i=1; i<=T; i++) cin>>price[i];
    vector<vector<pair<ll, ll>>> event(15001);
    for(int i=0; i<n; i++){
        ll s,e,t; cin>>s>>e>>t;
        event[e].push_back({s, (e-s)*price[t]});
    }

    vector<ll> dp(15001);
    for(int t=1; t<=15000; t++){
        dp[t] = max(dp[t], dp[t-1]);
        for(auto &SC: event[t]){
            ll s,c; tie(s,c) = SC;
            dp[t] = max(dp[t], dp[s]+c);
        }
    }
    cout << dp[15000];
}