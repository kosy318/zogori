//
// Created by team076 on 19. 11. 9..
//

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const int N = 100005;

pll line[N];
int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;

        cin >> x >> y;
        line[i].first = x;
        line[i].second = x + y;
    }

    sort(line, line + n);

    ll s = 0, e = 2000000000, ans = 0;

    while (s <= e) {
        ll m = (s + e) / 2, prev = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prev = line[i].first;
                continue;
            }

            if (line[i].second < prev + m) {
                possible = false;
                break;
            }
            prev = max(line[i].first, prev + m);
        }

        if (possible) {
            ans = m;
            s = m + 1;
        }
        else e = m - 1;
    }

    cout << ans << '\n';
}