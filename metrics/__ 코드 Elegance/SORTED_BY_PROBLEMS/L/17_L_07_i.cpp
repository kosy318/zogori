/*
#include <cstdio>
#include <algorithm>
using namespace std;
// type -> max 100
// maximum -> max 10000

int dp[102][15001];
int val[101];
int finish[101];

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

    for(int i = 0; i<101; i++){
        finish[i] = 0;
    }

    int max_total = 0;
    for(int i = 1; i<=total_cnt; i++){
        int ftime, stime, val_num;
        scanf("%d%d%d", &ftime, &stime, &val_num);
        for(int k = 1; k<ftime; k++){
            dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
        }
        int check_point = 0;
        int check_max = 0;
        for(int k = i-1; k>=1; k--){
            if(finish[k] <= ftime && dp[k][finish[k]] > check_max){
                check_max = dp[k][finish[k]];
                check_point = k;
            }
        }

        int total = check_max;
        for(int k = ftime; k<stime; k++){
            total += val[val_num];
            dp[i][k] = max(dp[i-1][k], total);
            max_total = max(max_total, dp[i][k]);
        }
        finish[i] = stime-1;
        for(int k = stime; k<15001; k++){
            if(dp[i-1][k] == 0) break;
            dp[i][k] = dp[i-1][k];
        }
    }

    printf("%d\n",max_total);
    return 0;
}
*/

#include <iostream>
using namespace std;

int cost[101], dp[10001][15001];
pair<int, int> se[10001];
int M, N, s, e, t, max_time, ms, me;

int Max(int x, int y){
    return x>y?x:y;
}

int main(){
    cin>>M>>N;
    for(int i=1; i<=M; i++){
        cin>>cost[i];
    }

    for(int i=1; i<=N; i++){
        cin>>se[i].first>>se[i].second>>t;

        for(int j=1; j<se[i].second; j++){
            if(se[i].first>j) dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=dp[i-1][j];
                for(int k=1; k<i; k++){
                    if(se[k].second<=se[i].first){
                        dp[i][j]=Max(dp[i][j], dp[k][se[k].second - 1] + (j-se[i].first+1)*cost[t]);
                    }
                }
                dp[i][j]=Max(dp[i][j], (j-se[i].first+1)*cost[t]);
            }
            max_time=Max(max_time, dp[i][j]);
        }
    }

    cout<<max_time<<'\n';

    return 0;
}
