#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pll;
ll N, lo=1, hi=1000000001;
vector<pll> arr;
ll f(ll x){
    ll now=0;//arr[0].first;
    for (int i=0;i<arr.size();now+=x){
        if (now<arr[i].first){
            now=arr[i].first;
            i++;
        }
        else if (arr[i].first<=now && now<=arr[i].second){
            i++;
        }
        else if (arr[i].second<now){
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({a,a+b});
    }
    sort(arr.begin(),arr.end());
    for (int i=0;i<40;i++){
        ll mid=(lo+hi)/2;
        if (f(mid))
            lo=mid;
        else
            hi=mid;
    }
    cout << lo;
    return 0;
}
/*
6
2 5 8 0
6 0
1 10 0
4 6 11 0
5 7 9 0
*/
