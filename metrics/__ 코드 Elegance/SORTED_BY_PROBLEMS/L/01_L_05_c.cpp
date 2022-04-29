#include<iostream>
#include <algorithm>
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

struct ABC
{
     int s=0, e=0, t=0;
};

ABC tc[10010];

bool compare(const ABC &i, const ABC &j)
{
    if (i.s == j.s)return i.e < j.e;
    else return i.s < j.s;
}

int m, n, ans;
int mt[101];
long long dp[15000];

int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>mt[i];
    for(int i=1; i<=n;i++)
    {
        cin >> tc[i].s >> tc[i].e >> tc[i].t;
        tc[i].e=tc[i].e-tc[i].s;
    }

    sort(tc + 1, tc + 1 + n, compare);

    for(int i=1; i<=n; i++)
    {
        dp[tc[i].s+tc[i].e]=max(dp[tc[i].s]+mt[tc[i].t]*tc[i].e,dp[tc[i].s+tc[i].e]);
        for(int j=tc[i].s+tc[i].e+1; j<15000; j++)
        {
            dp[j]=max(dp[j],dp[tc[i].s+tc[i].e]);
        }

    }
    for(int i=1; i<15000; i++)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
