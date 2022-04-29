#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int dp[1001] = {0, };
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        int min = i;
        for(int j=i; j>0; j--)
        {
            dp[i] = j;
            bool flag = true;
            for(int k=1; k<i; k++)
            {
                if(i - 2*k < 0)
                    break;
                if(dp[i] - dp[i-k] == dp[i-k] - dp[i-2*k])
                    flag = false;
            }
            if(flag)
                if(j < min) min = j;
        }
        dp[i] = min;
    }

    printf("%d", dp[n]);
}
