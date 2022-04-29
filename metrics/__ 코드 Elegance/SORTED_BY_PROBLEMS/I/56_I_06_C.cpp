#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int N;
pii arr[100000];

bool chk(ll n){
    ll now = arr[0].first;
    for(int i =1;i<N;i++){
        now = max(now+n,arr[i].first);
        if(now>arr[i].second)return 0;
    }
    return 1;
}

ll lb(){
    ll s = 0;
    ll e = 2000000000;
    ll m;
    while(s<e){
        m = (s+e)/2+(s+e)%2;
        if(chk(m)) s =m;
        else e = m-1;
    }
    return e;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
        arr[i].second+=arr[i].first;
    }
    sort(arr,arr+N);
    cout<<lb();
}


