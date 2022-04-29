#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n;
int prices[15000];
vector<pair<int,int>> minerals[15000];
int lastDay = -1;
int dp[15001];

int main() {
    dp[0] = 0;

    scanf("%d %d", &m, &n);

    for(int i=1;i<=m;i++){
        scanf("%d", &prices[i]);
    }

    for(int i=0;i<n;i++){
        int s,e,t;
        scanf("%d %d %d", &s, &e, &t);
        lastDay = max(lastDay, e);
        minerals[e].push_back(make_pair(s, t));
    }

    for(int i=1;i<=lastDay;i++){
        if(minerals[i].empty()) dp[i] = dp[i-1];
        else{
            int res = dp[i-1];
            for(pair<int, int> temp : minerals[i]){
                res = max(res, dp[temp.first] + (prices[temp.second] * (i - temp.first)));
            }

            dp[i] = res;
        }
    }

    printf("%d", dp[lastDay]);
    return 0;
}