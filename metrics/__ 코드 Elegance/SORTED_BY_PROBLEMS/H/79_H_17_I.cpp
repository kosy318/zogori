#include <iostream>
#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#pragma gcc optimize("O3")
#pragma gcc optimize("unroll-loops")
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef tuple<int, int, int> tt;
const int MAX = 100005;

int n, m, s, b;
vector<int> xvt, yvt;
vector<pii> point1, point2;

int arr[1005][1005], dp[1005][1005];

int query(int x1, int y1, int x2, int y2)
{
    return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}


signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x, y;
        cin >> x >> y;
        point1.push_back({x, y});
        xvt.push_back(x);
        yvt.push_back(y);
    }
    cin >> m;
    for (int i=1; i<=m; i++)
    {
        int x, y;
        cin >> x >> y;
        point2.push_back({x, y});
        xvt.push_back(x);
        yvt.push_back(y);
    }
    cin >>s >> b;

    sort(xvt.begin(), xvt.end());
    sort(yvt.begin(), yvt.end());
    sort(point1.begin(), point1.end(), [](pii & a, pii & b) { return a.second < b.second; });

    for (auto & p : point1)
    {
        p.first = lower_bound(xvt.begin(), xvt.end(), p.first) - xvt.begin() + 1;
        p.second = lower_bound(yvt.begin(), yvt.end(), p.second) - yvt.begin() + 1;
        arr[p.first][p.second] += s;
    }

    for (auto & p : point2)
    {
        p.first = lower_bound(xvt.begin(), xvt.end(), p.first) - xvt.begin() + 1;
        p.second = lower_bound(yvt.begin(), yvt.end(), p.second) - yvt.begin() + 1;
        arr[p.first][p.second] -= b;
    }
    for (int i=1; i<=1000; i++)
    {
        if (i != 1)
            dp[1][i] = dp[1][i-1] + arr[1][i];
        dp[i][1] = dp[i-1][1] + arr[i][1];
    }

    for (int y=2; y<=1000; y++)
    {
        for (int x = 2; x <= 1000; x++)
        {
            dp[x][y] = dp[x-1][y] + dp[x][y-1] - dp[x-1][y-1] + arr[x][y];
        }
    }

    int ans = 0;
    for (int i = 0; i<n;i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int xl = point1[i].first, xr = point1[j].first;
            int bottom = point1[0].second;
            bool flag = false;

            for (int k = 0; k < n; k++)
            {
                if (flag)
                {
                    bottom = point1[k].second;
                    flag = false;
                }
                int q = query(xl, bottom, xr, point1[k].second);
                if (q < 0)
                    flag = true;
                ans = max(ans, q);
            }
        }
    }
    cout << ans;


}