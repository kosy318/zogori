#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;

const int N = 1005;

int n1, n2;
pll p1[N], p2[N];
vl p1x, p1y;
ll c1, c2, ans;

ll s[N][N];
ll d[2][N][N];

ll ss(int i, int j, int k) {
    return s[i][k] - s[i][j] + c1 * (p1[i].second >= p1y[j] && p1[i].second <= p1y[k] ? 1 : 0);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n1;
    for (int i = 0; i < n1; i++) cin >> p1[i].first >> p1[i].second;
    cin >> n2;
    for (int i = 0; i < n2; i++) cin >> p2[i].first >> p2[i].second;
    cin >> c1 >> c2;

    sort(p1, p1 + n1);

    for (int i = 0; i < n1; i++) p1x.push_back(p1[i].first);
    for (int i = 0; i < n1; i++) p1y.push_back(p1[i].second);

    sort(p1y.begin(), p1y.end());

    for (int i = 0; i < n2; i++) {
        int x = lower_bound(p1x.begin(), p1x.end(), p2[i].first) - p1x.begin(), y = lower_bound(p1y.begin(), p1y.end(), p2[i].second) - p1y.begin();

        s[x][y] -= c2;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 1; j < n1; j++) {
            s[i][j] += s[i][j - 1];
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            for (int k = j; k < n1; k++) {
                if (i == 0) {
                    d[i%2][j][k] = max(ss(i, j, k), 0LL);
                }
                else d[i%2][j][k] = max(d[(i+1)%2][j][k] + ss(i, j, k), 0LL);

                ans = max(ans, d[i%2][j][k]);
            }
        }
    }

    cout << ans << "\n";
}