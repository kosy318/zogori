#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using ll = long long;

int N;
pr A[100005];

bool f(ll x) {
    ll l = A[1].first, r = A[1].second;
    for(int i=2; i<=N; i++) {
        ll _l = l + x, _r = r + x;
        if(_l > A[i].second) return 0;
        _l = min(_l, 1LL * A[i].second), _r = min(_r, 1LL * A[i].second);
        _l = max(_l, 1LL * A[i].first), _r = max(_r, 1LL * A[i].first);
        l = _l, r = _r;
    }
    return l <= r;
}

int main()
{
    scanf("%d", &N);
    for(int i=1, x, y; i<=N; i++) {
        scanf("%d %d", &x, &y);
        A[i] = pr(x, x + y);
    }
    sort(A + 1, A + N + 1);
    ll s = 0LL, e = 2e9;
    while(s <= e) {
        ll mid = s + e >> 1;
        f(mid) ? s = mid + 1 : e = mid - 1;
    }
    printf("%lld\n", e);
}
