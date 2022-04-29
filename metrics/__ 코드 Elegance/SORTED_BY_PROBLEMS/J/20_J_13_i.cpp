
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
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    for(int i=5;i<=1000000;i++) {
        //dp1[i] = min(1 + dp2[i-1] + dp2[1], dp1[i-1]);
        dp1[i] = 1e9;
        for(int x : v) {
            dp1[i] = min(dp1[i], max({dp1[x], dp1[i-x], dp2[x] + dp2[i-x] + 1}));
        }
        if(dp1[i] != dp1[i-1]) v.push_back(i-1);
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
