#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
vector<pair<ll,ll> > a;
bool parametric_search(ll mid) {
    ll dist = -1234987654321;
    for(int i = 0; i < a.size(); i++) {
        pair<ll,ll> curr = a[i];
        ll s = a[i].first;
        ll e = a[i].second;
        if((dist + mid <= s)) {
            dist = s;
        }
        else if(dist + mid > e) {
            return false;
        }
        else {
            dist += mid;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
    ll s,e;
        cin >> s >> e;
        a.push_back({s, s + e});
    }
    sort(a.begin(), a.end());
    ll l = 0, r = (10e9) * 3 + 5;
    while(l <= r) {
        ll mid = (l + r)/2;
        if(parametric_search(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l - 1;
    return 0;
}
