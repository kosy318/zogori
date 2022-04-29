#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;

int cost[101];
int dp[15001];
vector<pii> vec[15001];
int main() {
    int n,m, a, b, c;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back({b,cost[c]});
    }
    for(int i=1;i<=15000;i++){
        dp[i] = max(dp[i], dp[i-1]);
        for(pii v : vec[i]){
            dp[v.first] = max(dp[v.first], dp[i] + (v.first-i)*v.second);
        }
    }
    printf("%d",dp[15000]);
}
