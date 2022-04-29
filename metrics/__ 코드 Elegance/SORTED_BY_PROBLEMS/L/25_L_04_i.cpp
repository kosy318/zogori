#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;

int dp[15000];
vector<pii> v[15000];
int cost[100];

int go(int o) {
    if (o == 15000) return 0;
    if (dp[o] != -1) return dp[o];

    int mav = go(o + 1);
    for (pii i : v[o]) {
        mav = max(mav, go(i.first) + (i.first - o) * i.second);
    }
    return dp[o] = mav;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &cost[i]);

    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--; c--;
        v[a].push_back({b, cost[c]}); // b+1 moves.
    }

    printf("%d", go(0));
}
