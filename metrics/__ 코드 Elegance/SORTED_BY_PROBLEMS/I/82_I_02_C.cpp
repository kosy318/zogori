#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

struct Segment {
    long long l, r;
};

int n;
Segment a[N];

bool check(long long distance) {
    long long last = a[1].l;
    for (int i = 2; i <= n; i++) {
        long long cur = last + distance;

        if (cur < a[i].l) cur = a[i].l;

        if (cur > a[i].r) {
            return false;
        }
        last = cur;
    }
    return true;
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, l;
        cin >> x >> l;
        a[i].l = x;
        a[i].r = x + l;
    }

    sort(a + 1, a + n + 1, [](Segment &A, Segment &B) {
        if (A.l != B.l) return A.l < B.l;
        return A.r < B.r;
    });

    long long low = 1, high = 2e9 + 123;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid; low = mid + 1;
        } else high = mid - 1;
    }
    cout << ans;
    return 0;
}
