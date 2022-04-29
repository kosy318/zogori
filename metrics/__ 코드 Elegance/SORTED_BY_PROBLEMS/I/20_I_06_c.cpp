/*
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int t = 1;
    int ans = 1e9;
    for(int i=0;n-t >= 2;i++,t*=2) {
        int a = n-t;
        int b = a - (a+1)/2 - 1;
        a = (a+1)/2 - 1;
        int cnt = 0;
        while(a) {
            a/=2;
            cnt++;
        }
        int cnt2 = 0;
        while(b) {
            b/=2;
            cnt2++;
        }
        ans = min(ans, max({cnt + i, cnt + cnt2, cnt2 + i}) );
    }
    printf("%d\n",ans);
    return 0;
}
*/
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
