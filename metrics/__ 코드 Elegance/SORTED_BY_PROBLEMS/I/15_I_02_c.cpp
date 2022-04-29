#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> T;
ll n,ans=0;
int main() {
    cin>>n;
    T.resize(n);
    for(int i=0;i<n;i++) cin>>T[i].first>>T[i].second;
    sort(T.begin(),T.end());
    ll lo=0,hi=2e9;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        bool able=true;
        ll prev=T[0].first;
        for(int i=1;i<n;i++){
            if(T[i].first-prev>=mid) prev=T[i].first;
            else if(T[i].first+T[i].second>=prev+mid) prev=prev+mid;
            else {
                able=false;
                break;
            }
        }
        if(able) {
            ans = mid;
            lo = mid + 1;
        }
        else hi=mid-1;
    }
    cout<<ans;
}