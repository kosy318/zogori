#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int m, n;
int val[102];
vector<pii> vec[15001];

ll dp[15001];

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++) scanf("%d", &val[i]);
    for(int i = 1, s, e, t; i <= n; i++){
        scanf("%d %d %d", &s, &e, &t);
        vec[e].push_back(make_pair(s, t));
    }

    for(int x = 1; x <= 15000; x++){
        dp[x] = dp[x - 1];
        for(pii p: vec[x]){
            int s = p.first, t = p.second;
            dp[x] = max(dp[x], dp[s] + (x - s) * 1ll * val[t]);
        }
    }

    printf("%lld", dp[15000]);
    return 0;
}
