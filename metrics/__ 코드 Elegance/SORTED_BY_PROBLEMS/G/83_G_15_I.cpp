#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[200010][2][2];

long long o[200010];
long long c[200010];

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    o[0] = -(1ll<<60) - 10;
    c[0] = -1;
    o[1] = -(1ll<<60) - 9;
    c[1] = 0;
    o[n + 2] = (1ll << 60) + 9;
    c[n + 2] = -2;

    for(int i = 2; i <= n + 1; i++) scanf("%lld", &o[i]);
    for(int i = 2; i <= n + 1; i++) scanf("%lld", &c[i]);

    for(int i = 2; i <= n + 1; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = 1ll << 60;

    for(int i = 2; i <= n + 1; i++) { //  0 set 1 cset   0 succ 1 fail
        if(o[i - 1] - o[i - 2] >= o[i] - o[i - 1]) {
            if(c[i - 1] == c[i]) dp[i][0][0] = min(dp[i - 1][1][1] + 1, dp[i][0][0]);
        }
        if(o[i + 1] - o[i] >= o[i] - o[i - 1]) {
            if(c[i - 1] == c[i]) dp[i][1][0] = min(dp[i - 1][0][0], dp[i][1][0]);
        }
        dp[i][0][0] = min(dp[i - 1][0][0] + 1, dp[i][0][0]);
        dp[i][0][0] = min(dp[i - 1][1][0] + 1, dp[i][0][0]);
        dp[i][1][1] = min(dp[i - 1][0][0], dp[i][1][1]);
        dp[i][1][1] = min(dp[i - 1][1][0], dp[i][1][1]);
    }
    printf("%lld\n", min(dp[n + 1][1][0], dp[n + 1][0][0]));
    return 0;
}