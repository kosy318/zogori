#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll arr[1000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        p[i].first = x;
        p[i].second = x+y;
    }
    sort(p.begin(), p.end());

    auto possible = [&](int d) {
        int x = p[0].first;
        for(int i=1; i<n; i++) {
            if(p[i].second < x + d) return false;
            if(x + d < p[i].first) x = p[i].first;
            else x = x + d;
        }

        return true;
    };

    int l=1, r=1e9;
    int res=1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(possible(mid)) {
            l = mid + 1;
            res = max(res, mid);
        } else r = mid - 1;
    }

    cout << res << endl;

    return 0;
}
