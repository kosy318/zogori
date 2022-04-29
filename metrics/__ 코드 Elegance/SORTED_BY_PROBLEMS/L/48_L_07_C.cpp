#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll cost[1005];

struct Block {
    ll s, e, cost;
    bool operator<(const Block &o) const {
        return e < o.e;
    }
} inp[10005];

ll dp[10005];

int main() {
    int M, N; scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; i++) {
        scanf("%lld", cost + i);
    }

    for (int i = 1; i <= N; i++) {
        int s, e, t; scanf("%d %d %d", &s, &e, &t);
        ll c = (e - s) * cost[t];
        inp[i] = {s, e, c};
    }
    sort(inp + 1, inp + N + 1);

    for (int i = 1; i <= N; i++) {
        ll s = inp[i].s;
        dp[i] = dp[i - 1];
        Block f = {0, s, 0};
        int before = upper_bound(inp + 1, inp + N + 1, f) - inp - 1;
        dp[i] = max(dp[i] , dp[before] + inp[i].cost);
    }

    printf("%lld\n", dp[N]);
}