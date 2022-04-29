#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second

int n;
vector<pll> V;
bool can(ll d){
    ll x = V[0].xx;
    for(int i=1; i<n; ++i){
        x += d;
        if(V[i].xx + V[i].yy < x){
            return 0;
        }
        x = max(x, V[i].xx);
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i){
        int x, l;
        cin >> x >> l;
        V.push_back({x,l});
    }
    sort(V.begin(), V.end());
    ll lo = 0, hi = 2123456789LL;
    while(lo+1 != hi){
        ll mid = (lo+hi)/2;
        if(can(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
}
