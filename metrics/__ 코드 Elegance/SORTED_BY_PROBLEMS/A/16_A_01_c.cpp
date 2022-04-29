#include <stdio.h>
#include <cstring>

long long dp[1010];
bool check[1010];

int main(void) {
    int n;
    scanf("%d", &n);

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        memset(check, false, sizeof(check));
        for(int k = 1; k <= i / 2; k++) {
            long long a = dp[i - k] * 2 - dp[i - 2 * k];
            if(1 <= a && a <= 1000)
                check[a] = true;
        }

        for(int j = 1; j <= 1000; j++) {
            if (check[j] == false) {
                dp[i] = j;
                break;
            }
        }
    }

    printf("%lld\n", dp[n]);

}