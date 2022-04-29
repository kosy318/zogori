#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pll;
ll N, M, arr[105], dp[105][10005], ans;
vector<pll> v[105];

bool cmp(pll a, pll b){
    if (a.second<b.second)
        return 0;
    else
        return 1;
}
int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for (int i=0;i<M;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        v[c].push_back({a,b});
    }
    for (int i=1;i<=N;i++){
        sort (v[i].begin(),v[i].end(), cmp);
    }

    for (int i=1;i<=N;i++){
        for (int j=1;j<=10000;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            while (!v[i].empty() && j>=v[i][v[i].size()-1].second){
                pll x=v[i][v[i].size()-1];
                dp[i][j]=max(dp[i][j],dp[i][x.first]+(x.second-x.first)*arr[i]);
                v[i].pop_back();
            }

        }
    }
    for (int i=0;i<=10000;i++){
        ans=max(ans,dp[N][i]);
    }
    cout << ans;
    return 0;
}
/*
6
2 5 8 0
6 0
1 10 0
4 6 11 0
5 7 9 0
*/
