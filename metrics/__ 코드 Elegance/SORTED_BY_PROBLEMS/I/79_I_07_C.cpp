#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

vector<pii> vt;

bool check(int k)
{
    int prev = -(((int)1) << 56);
    for (auto i : vt) {
        int s = i.first, e = i.second;
        if (max(prev + k, s) > e)
            return false;
        else {
            prev = max(prev + k, s);
        }
    }
    return true;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, x;
        cin >> s >> x;
        vt.push_back({s, s + x});
    }

    sort(vt.begin(), vt.end());

    int s = 0, e = ((int)1) << 55;
    while (s <= e) {
        int m = (s + e) / 2;

        if (check(m))
            s = m + 1;
        else
            e = m - 1;

    }

    cout << e;

    return 0;
}