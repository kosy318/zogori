#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];
    vector<vector<pair<int, int>>> g(15001);
    for(int i=0; i<m; i++) {
        int x, y, z; cin >> x >> y >> z;
        g[y].push_back({x, z});
    }

    vector<int> dp(15001, 0);
    int res = 0;
    for(int i=1; i<=15000; i++) {
        for(pair<int, int> x : g[i]) {
            int j = x.first;
            int t = x.second;

            dp[i] = max(dp[i], dp[j]+(i-j)*p[t]);
        }
        res = max(res, dp[i]);
        dp[i] = max(dp[i], dp[i-1]);
        // if(i <= 15) cout << i << ' ' << dp[i] << endl;
    }

    cout << res << endl;

    return 0;
}
