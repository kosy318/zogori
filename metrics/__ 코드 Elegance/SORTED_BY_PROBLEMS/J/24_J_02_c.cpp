#include <iostream>

using namespace std;
int n, dp[1000001];
int main()
{
    scanf("%d", &n);
    dp[4] = 1;
    //dp[5] = dp[6] = 2;
    for (int i = 5; i <= n; i++) {
        if (i & 1) dp[i] = dp[i / 2 + 1] + 2;
        else dp[i] = dp[i / 2] + 2;
    }
    printf("%d", dp[n]);
    return 0;
}

