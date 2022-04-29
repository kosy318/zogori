#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];
long long make_dp(int x){
    if(dp[x]!=-1)   return dp[x];
    if(x%2){
        dp[x]=make_dp(x/2+1)+2;
    }
    else dp[x]=make_dp(x/2)+2;
    return dp[x];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)   dp[i]=-1;
    dp[0]=0;
    dp[1]=0;
    dp[2]=0;
    dp[3]=0;
    dp[4]=1;
    cout<<make_dp(n);
}
