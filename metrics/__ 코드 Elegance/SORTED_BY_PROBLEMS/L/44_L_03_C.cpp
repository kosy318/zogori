#include <bits/stdc++.h>

using namespace std;

int m, n, p[105];
vector<pair<int, int>> a[15005];

long long dp[15005];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        a[s].push_back({e, p[t]});
    }
    for (int i = 0; i <= 15000; i++) {
        if (i) {
            dp[i] = max(dp[i - 1], dp[i]);
        }
        for (auto p: a[i]) {
            int e = p.first;
            int price = p.second;
            dp[e] = max(dp[e], dp[i] + price * (e - i));
        }
    }
    printf("%lld\n", dp[15000]);
}
