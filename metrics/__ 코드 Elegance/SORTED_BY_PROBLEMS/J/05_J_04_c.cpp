#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second


ll dp[1123123];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    dp[3] = 0;
    dp[4] = 1;
    cin >> n;
    for(int i=5; i<=n; ++i)
        dp[i] = dp[(i+1)/2]+2;
    cout << dp[n];
}
