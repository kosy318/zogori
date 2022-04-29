#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, M[101], dp[15001], l;
vector<pair<int, int>> N[15000];
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d", &m, &n);
    for (int i=1;i<=m;i++) scanf("%d ", &M[i]);
    for (int i=0, e,s,t;i<n;i++) {
        scanf("%d %d %d", &s, &e, &t);
        N[e].push_back({s,M[t] * (e - s)});
        l = max(l, e);
    }
    for (int i=1;i<=l;i++) {
        dp[i] = dp[i - 1];
        for (auto t : N[i])
            dp[i] = max(dp[i], dp[t.first] + t.second);
    }
    printf("%d", dp[l]);
    return 0;
}

