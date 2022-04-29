/*
#include <cstdio>
#include <algorithm>
using namespace std;
// type -> max 100
// maximum -> max 10000

int dp[102][15001];
int val[101];

int val_cnt;
int total_cnt;

int main(){
    scanf("%d%d",&val_cnt,&total_cnt);
    for(int i = 1; i<=val_cnt; i++){
        scanf("%d",&val[i]);
    }

    for(int i = 0; i<102; i++){
        for(int j = 0; j<15001; j++){
            dp[i][j] = 0;
        }
    }

    int max_total = 0;
    for(int i = 1; i<=total_cnt; i++){
        int ftime, stime, val_num;
        scanf("%d%d%d", &ftime, &stime, &val_num);
        for(int k = 1; k<ftime; k++){
            dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
        }
        int total = 0;
        for(int k = ftime; k<stime; k++){
            total += var[val_num];
            if()
            max_total = max(max_total, dp[i][k]);
        }
    }

    printf("%d\n",max_total);
}
*/

#include <iostream>
using namespace std;

int dp[1000002], N;

int find(){
    dp[4]=1;
    dp[5]=1;

    for(int i=6; i<=N; i+=2){
        dp[i]=dp[i-2]+1;
        dp[i+1]=dp[i-1]+1;
    }

    return dp[N];
}

int main(){
    cin>>N;

    cout<<find()<<'\n';

    return 0;
}
