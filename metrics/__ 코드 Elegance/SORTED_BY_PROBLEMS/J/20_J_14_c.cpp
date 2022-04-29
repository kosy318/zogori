
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000006], dp2[1000005];
int main(){
    scanf("%d",&n);
    n -= 2;
    dp[1] = 0;
    int cnt = 1;
    int i = 2;
    while(i <= 1000000) {
        for(int j=i;j<i+cnt && j<=1000000;j++) {
            dp[j] = dp[i-1] + 1;
        }
        for(int j=i+cnt;j<i+cnt*3 && j<=1000000;j++) {
            dp[j] = dp[i-1] + 2;
        }
        i = i+cnt*3;
        cnt *= 2;
    }
    cout<<dp[n];
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000010];
int main(){
    scanf("%d",&n);
    if(n==3){
        printf("0");
        return 0;
    }
    for(int i=2; i<=n-2; i++){
        int cnt=0, t = i;
        while(t!=1){
            t=(t+1)/2;
            cnt++;
        }
        dp[i]=cnt-1;
    }
    int res = n;
    for(int i=2; i<=n-2; i++){
        res = min(res, dp[i]+dp[n-i]+1);
    }
    printf("%d",res);
    return 0;
}
*/
