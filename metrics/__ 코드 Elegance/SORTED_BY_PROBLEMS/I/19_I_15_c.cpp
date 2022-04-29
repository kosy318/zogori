#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pll;
ll N, lo=1, hi=2000000001;
vector<pll> v;
ll f(ll x){
    ll st=v[0].first;
    for (int i=0;i<N;i++){
        if (st<v[i].first){
            st=v[i].first+x;
        }
        else if (v[i].first<=st && st<=v[i].second){
            st+=x;
        }
        else
            return 0;
    }
    return 1;
}
int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a,a+b});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<50;i++){
        ll mid=(lo+hi)/2;
        if (f(mid))
            lo=mid;
        else
            hi=mid;
    }
    cout << lo;
    return 0;
}
