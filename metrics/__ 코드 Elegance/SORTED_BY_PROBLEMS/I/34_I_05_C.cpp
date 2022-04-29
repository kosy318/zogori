#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<pair<ll,ll>> T(n);
    for(int i=0; i<n; i++){
        ll x,l; cin>>x>>l;
        T[i].first = x, T[i].second = x+l;
    }
    sort(T.begin(), T.end());

    ll l = 0, u = 2000000000, ans;
    while(l <= u){
        bool flag = true;
        ll m = (l+u)/2;
        ll knot = -2000000000;
        for(auto &SE: T){
            ll s,e; tie(s,e) = SE;
            if(knot+m > e){flag = false; break;}
            knot = max(s, knot+m);
        }
        if(flag) ans = m, l = m+1;
        else u = m-1;
    }
    cout<<ans;
}