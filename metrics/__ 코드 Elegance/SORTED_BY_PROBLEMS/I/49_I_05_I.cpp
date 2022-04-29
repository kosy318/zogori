#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n;
pll t[100001];
ll k[100001];

bool det(ll x)
{
    k[0] = t[0].first; k[n-1] = t[n-1].second;
    for(ll i=1; i<n-1; i++)
    {
        ll p = k[i-1] + x;
        ll l = t[i].first;
        ll r = t[i].second;
        if(p < l) k[i] = l;
        else if(l <= p && p <= r) k[i] = p;
        else return false;
    }
    if(k[n-1] - k[n-2] >= x) return true;
    else return false;
}

int main()
{
    scanf("%lld", &n);
    for(ll i=0; i<n; i++)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        t[i].first = x; t[i].second = x+y;
    }
    sort(t, t+n);

    ll l = 0;
    ll r = 1000000001;
    ll mid = (l+r) / 2;
    while(1) // sol is l
    {
        mid = (l+r) / 2;
        if(det(mid)) l = mid+1;
        else r = mid;
        if(l == r) break;
    }

    printf("%lld", l-1);
    return 0;
}