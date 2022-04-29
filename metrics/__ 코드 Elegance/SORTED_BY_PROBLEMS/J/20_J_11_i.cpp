
#include<bits/stdc++.h>
using namespace std;
int n;
int dp1[1000006], dp2[1000005];
int main(){
    scanf("%d",&n);
    n -= 2;

    for(int i=1;i<=1000000;i++) {
        dp2[i] = -1;
        int idx = i;

        while(idx) {
            dp2[i]++;
            idx /= 2;
        }
    }

    dp1[1] = 0;
    dp1[2] = 1;
    dp1[3] = 2;
    dp1[4] = 2;
    for(int i=5;i<=1000000;i++) {
        //dp1[i] = min(1 + dp2[i-1] + dp2[1], dp1[i-1]);
        dp1[i] = 1e9;
        for(int j=1;j<i;j = j * 2 + 1) {
            dp1[i] = min(dp1[i], max({dp1[j], dp1[i-j], dp2[j] + dp2[i-j] + 1}) );
        }
    }
    printf("%d\n",dp1[n]);
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
