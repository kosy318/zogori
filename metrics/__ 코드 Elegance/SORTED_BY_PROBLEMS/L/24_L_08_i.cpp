#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, M[100], dp[15001], l;
pair<pair<int, int>, int> N[10001];
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d", &m, &n);
    for (int i=1;i<=m;i++) scanf("%d ", &M[i]);
    for (int i=0, e,s,t;i<n;i++) {
        scanf("%d %d %d", &s, &e, &t);
        N[i].first.second = s;
        N[i].first.first = e;
        N[i].second = M[t] * (e - s);
        l = max(l, e);
    }
    sort(N, N + n);
    int idx = 0;
    for (int i=1;i<=l;i++) {
        dp[i] = dp[i - 1];
        while(idx < n && i == N[idx].first.first) {
            dp[i] = max(dp[i], dp[N[idx].first.second] + N[idx].second);
            idx++;
        }
    }
    printf("%d", dp[l]);
    return 0;
}

