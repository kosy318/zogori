#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;



struct SegmentTree
{
    vector<int> arr;

    SegmentTree(int n)
    {
        arr.resize(4*(n + 2), 0);
    }

    int query(int i, int s, int e, int l, int r)
    {
        if (s > r || e < l)
            return 0;
        else if (l <= s && e <= r)
            return arr[i];
        else
        {
            int m = (s + e ) / 2;
            return max(query(2*i, s, m, l, r), query(2*i + 1, m +1 , e, l, r));
        }
    }

    void update(int i, int s, int e, int idx, int diff)
    {
        if (!(s <= idx && idx <= e))
            return;
        else if (s == e)
            arr[i] = max(arr[i], diff);
        else
        {
            int m = (s+ e)/2;
            update(2*i,s, m, idx, diff);
            update(2*i+1,m+1, e, idx, diff );
            arr[i] = max(arr[2*i], arr[2*i+1]);
        }
    }
};

int dp[20000];
int price[105];
vector<tuple<int, int, int>> vt;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    SegmentTree Tree(30000);

    int n, m;
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        cin >> price[i];

    for (int i=1; i<=n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vt.push_back({x, y, z});
    }
    sort(vt.begin(), vt.end());

    for (auto i : vt)
    {
        int s, e, x;
        tie(s, e, x) = i;
        int cur = Tree.query(1, 1, 30000, 1, s);
        Tree.update(1, 1, 30000, e, cur + (e - s) * price[x]);
    }

    cout << Tree.query(1, 1, 30000, 1, 30000);

    return 0;
}