#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n1,n2,n;
pair<ll,ll> b[1005],s[1005];
vector<pair<pair<int,int>,int>> p;
vector<vector<pair<ll,ll>>> dp,sum;
vector<ll> x,y;
ll c1,c2;

ll cal(int s, int b){
    return c1*(ll)s - c2*(ll)b;
}

int main(){
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%lld%lld",&s[i].first,&s[i].second);
        x.push_back(s[i].first);
        y.push_back(s[i].second);
    }
    scanf("%d",&n2);
    for(int i=0;i<n1;i++){
        scanf("%lld%lld",&b[i].first,&b[i].second);
        x.push_back(b[i].first);
        y.push_back(b[i].second);
    }
    scanf("%lld%lld",&c1,&c2);

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    //x.erase(unique(x.begin(),x.end()),x.end());
    dp.resize(x.size()+1),sum.resize(x.size()+1);
    //y.erase(unique(y.begin(),y.end()),y.end());
    for(int i=0;i<dp.size();i++) dp[i].resize(y.size()+1),sum[i].resize(y.size()+1);

    for(int i=0;i<n1;i++){
        int idx_x = lower_bound(x.begin(),x.end(),s[i].first)-x.begin()+1;
        int idx_y = lower_bound(y.begin(),y.end(),s[i].second)-y.begin()+1;
        dp[idx_x][idx_y].first=1;
        p.push_back({{idx_x,idx_y},1});
    }
    for(int i=0;i<n2;i++){
        int idx_x = lower_bound(x.begin(),x.end(),b[i].first)-x.begin()+1;
        int idx_y = lower_bound(y.begin(),y.end(),b[i].second)-y.begin()+1;
        dp[idx_x][idx_y].second=1;
        p.push_back({{idx_x,idx_y},0});
    }

    sort(p.begin(),p.end());

    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            //printf("%d/%d ",dp[i][j].first,dp[i][j].second);
            if(!i){
                if(!j) sum[i][j]=dp[i][j];
                else{
                    sum[i][j].first = dp[i][j].first + sum[i][j-1].first;
                    sum[i][j].second = dp[i][j].second + sum[i][j-1].second;
                }
            }
            else{
                if(!j){
                    sum[i][j].first = dp[i][j].first + sum[i-1][j].first;
                    sum[i][j].second = dp[i][j].second + sum[i-1][j].second;
                } else{
                    sum[i][j].first = dp[i][j].first + sum[i-1][j].first + sum[i][j-1].first - sum[i-1][j-1].first;
                    sum[i][j].second = dp[i][j].second + sum[i-1][j].second + sum[i][j-1].second - sum[i-1][j-1].second;
                }
            }
        }
        //printf("\n");
    }

    ll ans=-1000000000;
    for(int i=0;i<p.size();i++){
        for(int j=i+1;j<p.size();j++){
            int i_x = p[i].first.first, i_y = p[i].first.second;
            int j_x = p[j].first.first, j_y = p[j].first.second;

            int s = sum[j_x][j_y].first-sum[i_x-1][j_y].first-sum[j_x][i_y-1].first+sum[i_x-1][i_y-1].first;
            int b = sum[j_x][j_y].second-sum[i_x-1][j_y].second-sum[j_x][i_y-1].second+sum[i_x-1][i_y-1].second;

            //printf("%d %d %lld\n",s,b,cal(s,b));
            ans = max(ans, cal(s,b));
        }
    }

    printf("%lld",ans);

    return 0;
}