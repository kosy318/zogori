#include <bits/stdc++.h>

using namespace std;

struct ore
{
    int s, e, v;

    bool operator <(ore r)
    {
        return e < r.e;
    }
};

int price[101];
int dp[15005];
ore o[10000];

int main()
{
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
    {
        cin >> price[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> o[i].s >> o[i].e >> o[i].v;
        o[i].v = price[o[i].v] * (o[i].e - o[i].s);
    }
    sort(o, o+n);
    int p = 1;
    for(int i = 0; i < n; ++i)
    {
        while(p < o[i].e)
        {
            dp[p] = dp[p-1];
            p++;
        }
        if(p > o[i].e)
            p = o[i].e;
        dp[p] = max(dp[p], dp[p-1]);
        dp[p] = max(dp[p], o[i].v + dp[o[i].s]);
        p++;
    }
    cout << dp[p-1];
    return 0;
}
