#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 123;

int m, n;
int price[N];

int l[N];
int r[N];
int t[N];

vector<int> mines[N];

int dp[N];

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> price[i];

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        mines[r[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= 15000; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (int idx : mines[i]) {
            dp[i] = max(dp[i], dp[l[idx]] + (r[idx] - l[idx]) * price[t[idx]]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
