#include <stdio.h>

int dp[3000010];

int main(void) {
    long long n, r = 2, cnt = 2;
    scanf("%lld" ,&n);
    dp[3] = 0;
    dp[4] = 1;
    int i = 5;
    while(i <= n) {
        for(int j = 0; j < r; j++)
            dp[i++] = cnt;
        cnt++;
        for(int j = 0; j < r; j++)
            dp[i++] = cnt;
        cnt++;
        r *= 2;
    }
    printf("%d\n", dp[n]);
}