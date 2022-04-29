#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

vector<pii> vt;

bool check(int x,int k)
{
    int prev = x;
    for (auto i : vt) {
        int s = i.second, e = i.first;
        if (max(prev + k, s) > e)
            return false;
        else {
            prev = max(prev + k, s);
        }
    }
    return true;
}

main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, x;
        cin >> s >> x;
        vt.push_back({s + x, s});
    }

    int x = 0x3f3f3f3f, idx;
    for (int i = 0; i < n; i++) {
        if (vt[i].second < x) {
            x = vt[i].second;
            idx = i;
        }
    }
    vt.erase(vt.begin() + idx);

    sort(vt.begin(), vt.end());

    int s = 0, e = 1e9 + 10;

    while (s <= e) {
        int m = (s + e) >> 1;

        if (check(x, m))
            s = m + 1;
        else
            e = m - 1;
    }

    cout << e;




    return 0;
}