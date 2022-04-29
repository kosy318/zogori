#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > line;
ll dot[101010];

int solve(ll x){
    dot[0] = line[0].first;
    for(int i=1; i<line.size(); i++){
        dot[i] = max(dot[i-1]+x, line[i].first);
        if(line[i].first + line[i].second < dot[i]) return 0;
    }
    return 1;
}
ll binary_search(ll x, ll y){
    ll lo = x-1;
    ll hi = y+1;
    while(lo+1 < hi){
        ll mid = (lo+hi)/2;
        if(solve(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        ll x, len;
        scanf("%lld %lld", &x, &len);
        line.push_back({x, len});
    }
    sort(line.begin(), line.end());
    printf("%lld\n", binary_search(0, (ll)1e9));
    return 0;
}
