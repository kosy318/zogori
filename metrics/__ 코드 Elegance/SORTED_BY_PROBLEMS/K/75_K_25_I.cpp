#include <bits/stdc++.h>
#define init(x) memset((x),0,sizeof(x))
using namespace std;
using ll = long long;

ll N, K, X[105], Y[105], Z[105], cnt[2];
ll sx[2], sy[2], sz[2];
long double ans1 = 1e18, ans2;

void add(ll x, ll y) {
    cnt[y]++;
    sx[y] += X[x], sy[y] += Y[x], sz[y] += Z[x];
}

ll f(ll x) { return x * x; }

int main() {
    scanf("%lld %lld", &N, &K);
    ll ssx = 0LL, ssy = 0LL, ssz = 0LL;
    ll ssxx = 0LL, ssyy = 0LL, sszz = 0LL;
    for(ll i=1; i<=N; i++) {
        scanf("%lld %lld %lld", X+i, Y+i, Z+i);
        ssx += X[i], ssy += Y[i], ssz += Z[i];
        ssxx += X[i] * X[i], ssyy += Y[i] * Y[i], sszz += Z[i] * Z[i];
    }
    for(ll i=1; i<=N; i++) for(ll j=i+1; j<=N; j++) for(ll k=j+1; k<=N; k++) {
        ll dx1 = X[i] - X[j], dy1 = Y[i] - Y[j], dz1 = Z[i] - Z[j];
        ll dx2 = X[i] - X[k], dy2 = Y[i] - Y[k], dz2 = Z[i] - Z[k];
        ll ux = dy1 * dz2 - dy2 * dz1, uy = dz1 * dx2 - dz2 * dx1, uz = dx1 * dy2 - dx2 * dy1;
        ll cmp = 1LL * ux * X[i] + 1LL * uy * Y[i] + 1LL * uz * Z[i];
        ll cmp2 = 1LL * ux * X[j] + 1LL * uy * Y[j] + 1LL * uz * Z[j];
        ll cmp3 = 1LL * ux * X[k] + 1LL * uy * Y[k] + 1LL * uz * Z[k];
        cnt[0] = cnt[1] = 0;
        for(ll p=1; p<=N; p++) {
            ll res = 1LL * ux * X[p] + 1LL * uy * Y[p] + 1LL * uz * Z[p];
            if(res < cmp) add(p, 1);
            else if(res > cmp) add(p, 0);
        }
        for(ll p=0; p<8; p++) {
            ll _cnt[2];
            ll _x[2], _y[2], _z[2];
            init(_cnt); init(_x), init(_y), init(_z);
            if(p & 1) _cnt[0]++, _x[0] += X[i], _y[0] += Y[i], _z[0] += Z[i];
            if(p & 2) _cnt[0]++, _x[0] += X[j], _y[0] += Y[j], _z[0] += Z[j];
            if(p & 4) _cnt[0]++, _x[0] += X[k], _y[0] += Y[k], _z[0] += Z[k];
            if(~p & 1) _cnt[1]++, _x[1] += X[i], _y[1] += Y[i], _z[1] += Z[i];
            if(~p & 2) _cnt[1]++, _x[1] += X[j], _y[1] += Y[j], _z[1] += Z[j];
            if(~p & 4) _cnt[1]++, _x[1] += X[k], _y[1] += Y[k], _z[1] += Z[k];
            ans1 = min(ans1, -(long double)1.0 * ( f(sx[0] + _x[0]) + f(sy[0] + _y[0]) + f(sz[0] + _z[0]) ) / max(1.0, 1.0 * _cnt[0] + cnt[0])
                           -1.0 * ( f(sx[1] + _x[1]) + f(sy[1] + _y[1]) + f(sz[1] + _z[1]) ) / max(1.0, 1.0 * _cnt[1] + cnt[1])
                           + ssxx + ssyy + sszz);
        }
    }
    ans2 = -1.0 * (f(ssx) + f(ssy) + f(ssz)) / N + ssxx + ssyy + sszz;
    if(K == 1) printf("%.6Lf\n", ans2);
    else printf("%.6Lf\n", min(ans1, ans2));
}
