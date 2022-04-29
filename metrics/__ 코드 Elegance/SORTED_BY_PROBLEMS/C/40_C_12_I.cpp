#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

int lst[2][100000];
int idx[2][100000];
int L[2][100000], R[2][100000];
int LL[2][100000], RR[2][100000];

int get_common(int now) {
    if (L[0][now] == L[1][now] || L[0][now] == R[1][now]) return L[0][now];
    if (R[0][now] == L[1][now] || R[0][now] == R[1][now]) return R[0][now];
    return -1;
}
void remove(int now) {
    R[0][L[0][now]] = R[0][now];
    L[0][R[0][now]] = L[0][now];

    R[1][L[1][now]] = R[1][now];
    L[1][R[1][now]] = L[1][now];
}
int main() {
    //freopen("input.txt", "r", stdin);
    fastio;
    int n;
    cin >> n;

    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            cin >> lst[k][i];
            idx[k][--lst[k][i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            int index = idx[k][i];
            L[k][i] = lst[k][(index + n - 1) % n];
            R[k][i] = lst[k][(index + 1) % n];
        }
    }

    memcpy(LL, L, sizeof(L));
    memcpy(RR, R, sizeof(R));

    int f = 1;
    for (int i = n / 2; i >= 0 && i < n; i += f) {
        if (get_common(i) == -1) continue;

        memcpy(L, LL, sizeof(L));
        memcpy(R, RR, sizeof(R));

        int now = i;
        vector<int> path;

        while (L[0][now] != now) {
            int common = get_common(now);
            if (common == -1) break;

            path.push_back(common);
            remove(common);
            now = common;
        }

        if (sz(path) == n) {
            for (int it : path) cout << it + 1 << ' ';
            return 0;
        }
        //else break;

        f = -(f + 1);
    }

    cout << -1;

    return 0;
}