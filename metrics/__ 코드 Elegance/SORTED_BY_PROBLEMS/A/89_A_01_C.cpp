#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++)
        for(int j=1;;j++)
        {
            bool flag = false;
            for(int k=1;0<=i-2*k;k++)
                if(j-dp[i-k]==dp[i-k]-dp[i-2*k]) flag = true;
            if(!flag)
            {
                dp[i] = j;
                break;
            }
        }
    printf("%d ", dp[n]);

    return 0;
}
