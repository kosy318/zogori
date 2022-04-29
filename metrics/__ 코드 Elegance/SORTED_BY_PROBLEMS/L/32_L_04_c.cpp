#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

int n, m;
int p[110];
struct data
{
    int s, e, v;
    bool operator < (const data &r) const
    {
        if (e != r.e) return e < r.e;
        return s < r.s;
    }
} in[10010];

ll maxv[15010];
ll tree[32768];
int t_size;

void upd(int x, ll v)
{
    if (x == 0) return;
    tree[x] = max(tree[x], v);
    upd(x/2, v);
}

ll getv(int s, int e)
{
    ll ret = 0;
    while (s < e)
    {
        if (s%2 == 1) ret = max(ret, tree[s++]);
        if (e%2 == 0) ret = max(ret, tree[e--]);
        s >>= 1;
        e >>= 1;
    }
    if (s == e) ret = max(ret, tree[s]);
    return ret;
}

ll ans;

int main(void){

    t_size = 16384;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &in[i].s, &in[i].e, &in[i].v);
        in[i].v = p[in[i].v]*(in[i].e-in[i].s);
    }

    sort(in+1, in+n+1);
    for (int i = 1; i <= n; i++)
    {
        ll v = getv(0 + t_size, in[i].s + t_size);
        v += in[i].v;
        if (v < maxv[in[i].e]) continue;
        upd(in[i].e + t_size, v);

        ans = max(ans, v);
    }

    printf("%lld\n", ans);
}

/*
2 5
2
3
2 5 1
4 5 2
4 6 1
7 11 2
6 10 1

5 7
1 2 3 4 5
1 5 2
3 8 1
2 4 3
3 9 2
4 10 5
7 11 4
5 7 3
 */