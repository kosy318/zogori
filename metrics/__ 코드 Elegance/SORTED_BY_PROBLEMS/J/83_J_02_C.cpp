#include <cstdio>
int dp[1000010];

int dfs(int n) {
    if(dp[n] != -1) return dp[n];

    return dp[n] = dfs((n + 1) / 2) + 2;
}

int main() {
    dp[0] = dp[1] = dp[2] = dp[3] = 0;
    dp[4] = 1;
    for(int i = 5; i <= 1000000; i++) dp[i] = -1;

    int n;
    scanf("%d", &n);
    printf("%d", dfs(n));

    return 0;
}