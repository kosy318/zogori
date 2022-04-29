#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int y;
    long long c;
    bool operator< (const node &a) {
        return y < a.y;
    }
};

int ore[110];
long long dp[10010];
node o[10010];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++) scanf("%d", &ore[i]);
    for(int i = 0; i < n; i++) {
        int z;
        scanf("%d %d %d", &o[i].x, &o[i].y, &z);
        o[i].c = ore[z] * (o[i].y - o[i].x);
    }
    sort(o, o + n);
    long long tans = -(1ll << 60);
    for(int i = 0; i < n; i++) {
        long long ans = o[i].c;
        for(int j = 0; j < i; j++) {
            if(o[i].x < o[j].y) break;
            ans = max(ans, dp[j] + o[i].c);
        }
        dp[i] = ans;
        if(dp[i] > tans) tans = dp[i];
    }
    printf("%lld\n", tans);
    return 0;
}