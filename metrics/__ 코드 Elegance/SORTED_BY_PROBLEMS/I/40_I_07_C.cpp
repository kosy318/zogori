#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    fastio;
    int n;
    cin >> n;

    vector<pii> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i].X >> vec[i].Y;

    sort(all(vec));

    ll s = 1, e = 2000000000;
    while (s <= e) {
        ll m = s + e >> 1;
        ll pos = vec[0].X;

        int flg = 0;
        for (int i = 1; i < n; ++i) {
            if (vec[i].X + vec[i].Y < pos + m) {
                flg = 1;
                break;
            }
            pos = max((ll)vec[i].X, pos + m);
        }

        if (flg == 1) e = m - 1;
        else s = m + 1;
    }

    cout << e;

    return 0;
}