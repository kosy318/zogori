#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll offset = 1000000001;
ll n, m;
ll c1, c2;
vector<pll> b, r;
vector<ll> x, y;
map<ll, ll> mx, my;
set<ll> sx, sy;

const ll N = 2003;
ll a[N][N] = {0};
ll tree[N][N] = {0};

void update(ll x, ll y, ll v)
{
    for(ll xx=x; xx<N; xx += (xx & -xx))
        for(ll yy=y; yy<N; yy += (yy & -yy))
            tree[xx][yy] += v;
}
ll query(ll x, ll y)
{
    ll ret = 0;
    for(ll xx=x; xx; xx -= (xx & -xx))
        for(ll yy=y; yy; yy -= (yy & -yy))
            ret += tree[xx][yy];
    return ret;
}
ll sol(ll x, ll y, ll xx, ll yy)
{
    x--; y--;
    return query(xx, yy) - query(x, yy) - query(xx, y) + query(x, y);
}

int main()
{
    scanf("%lld", &n);
    for(ll i=0; i<n; i++)
    {
        ll xx, yy; scanf("%lld %lld", &xx, &yy);
        xx += offset; yy += offset;
        b.push_back(pll(xx, yy));
        if(sx.find(xx) == sx.end()) x.push_back(xx), sx.insert(xx);
        if(sy.find(yy) == sy.end()) y.push_back(yy), sy.insert(yy);
    }
    scanf("%lld", &m);
    for(ll i=0; i<m; i++)
    {
        ll xx, yy; scanf("%lld %lld", &xx, &yy);
        xx += offset; yy += offset;
        r.push_back(pll(xx, yy));
        if(sx.find(xx) == sx.end()) x.push_back(xx), sx.insert(xx);
        if(sy.find(yy) == sy.end()) y.push_back(yy), sy.insert(yy);
    }
    scanf("%lld %lld", &c1, &c2);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(ll i=0; i<x.size(); i++) mx[x[i]] = i+1;
    for(ll i=0; i<y.size(); i++) my[y[i]] = i+1;

    for(ll i=0; i<b.size(); i++)
    {
        pll p = b[i];
        ll px = p.first, py = p.second;
        b[i].first = mx[px]; b[i].second = my[py];
    }
    for(ll i=0; i<r.size(); i++)
    {
        pll p = r[i];
        ll px = p.first, py = p.second;
        r[i].first = mx[px]; r[i].second = my[py];
    }

    for(ll i=0; i<b.size(); i++)
        update(b[i].first, b[i].second, c1);
    for(ll i=0; i<r.size(); i++)
        update(r[i].first, r[i].second, -1 * c2);

    ll ans = -1;
    for(ll i=0; i<b.size(); i++)
        for(ll j=0; j<b.size(); j++)
            ans = max(ans, sol(b[i].first, b[i].second, b[j].first, b[j].second));

    printf("%lld", ans);
    return 0;
}