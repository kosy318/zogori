#include <bits/stdc++.h>
using namespace std;

int dp[1001], pos[5001];
int main() {
    int n;
    scanf("%d",&n);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int k=1;i-2*k>=0;k++){
            if(2*dp[i-k]-dp[i-k*2] > 0)
                pos[2*dp[i-k]-dp[i-k*2]] = i;
        }
        for(int j=1;j<=5000;j++){
            if(pos[j] != i) {
                dp[i] = j;
                break;
            }
        }
    }
    printf("%d",dp[n]);

    return 0;
}