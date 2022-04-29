#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 123;

int n, m, a[N], dp[N], x[N], l[N], r[N];

bool good(int j, int i) {
    return abs(x[l[i]] - x[i]) <= abs(x[l[i]] - x[j]) && abs(x[j] - x[r[j]]) <= abs(x[i] - x[r[j]]);
}

int T[N * 4];

void update(int pos, int x, int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        T[v] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(pos, x, v * 2, tl, tm);
    else update(pos, x, v * 2 + 1, tm + 1, tr);
    T[v] = min(T[v * 2], T[v * 2 + 1]);
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    if (tl > r || tr < l || l > r) return 1e9;
    if (l <= tl && tr <= r) return T[v];
    int tm = (tl + tr) / 2;
    return min(get(l, r, v * 2, tl, tm), get(l, r, v * 2 + 1, tm + 1, tr));
}

void build(int v = 1, int tl = 1, int tr = n) {
    T[v] = 1e9;
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
}

int main() {

    scanf("%d%d", &m, &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        l[i] = i;
        if (i > 1 && a[i - 1] == a[i]) l[i] = l[i - 1];
    }
    for (int i = n;i > 0;i--) {
        r[i] = i;
        if (i < n && a[i + 1] == a[i]) r[i] = r[i + 1];
    }

    build();
    int answer = N + 1;
    for (int i = 1;i <= n;i++) {

        dp[i] = N + 1;
        if (l[i] == 1) {
            dp[i] = 1;
        } else {
            int first = l[l[i] - 1], last = l[i] - 1;
            int pos = -1;
            while(first <= last) {
                int mid = (first + last) / 2;
                if (good(mid, i)) {
                    pos = mid;
                    last = mid - 1;
                } else first = mid + 1;
            }

            dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (pos != -1) {
                dp[i] = min(dp[i], get(pos, l[i] - 1) + 1);
            }
            if (i > l[i]) {
                dp[i] = min(get(l[i], i - 1) + 1, dp[i]);
            }

            //cout << "i : " << i << " dp: " << dp[i] << " " << pos << endl;
        }

        update(i, dp[i]);

        if (r[i] == n) answer = min(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}
