#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1000001];
int N;
int main()
{
    cin >> N;
    dp[3]=0;
    dp[4]=1;
    dp[5]=2;
    for(int i=6; i<=N; ++i){
        dp[i]=dp[i-i/2]+2;
    }
    printf("%d", dp[N]);
}
