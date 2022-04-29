#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
int N,M;
ll seg[32],cost[101];
piii arr[10001];
ll ans;
void update(int s, int e, int idx, int x, ll n){
    if(x>=s&&x<=e) seg[idx] = max(seg[idx],n);
    else return;
    if(s==e)return;
    int m = (s+e)>>1;
    update(s,m,idx*2,x,n);
    update(m+1,e,idx*2+1,x,n);
}
ll ret(int s, int e, int idx, int x){
    if(e<=x) return seg[idx];
    if(s>x) return 0;
    int m = (s+e)>>1;
    return max(ret(s,m,idx*2,x),ret(m+1,e,idx*2+1,x));
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>M;
for(int i=1;i<=N;i++)cin>>cost[i];
for(int i=0;i<M;i++)cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
sort(arr,arr+M);
for(int i=0;i<M;i++){
    ll tmp = ret(1,15000,1,arr[i].first.first);
    tmp += (arr[i].first.second - arr[i].first.first)* cost[arr[i].second];
    ans = max(tmp,ans);
    update(1,15000,1,arr[i].first.second,tmp);
}
cout<<ans;
}
/*
5 7 1 2 3 4 5 1 5 2 3 8 1 2 4 3 3 9 2 4 10 5 7 11 4 5 7 3
*/
