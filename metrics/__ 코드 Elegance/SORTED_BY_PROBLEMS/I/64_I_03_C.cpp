#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
int N;
vector<l_l> v;
bool check(ll mid) {
    //cout<< "---" << mid << "--" << endl;
    ll pos = v[0].first;
    for(int i = 1; i < v.size(); i++)  {
        auto now = v[i];
        //cout << pos << " " << now.first << endl;
        pos = max(now.first, pos + mid);
        if(pos > now.second) return false;
    }
    return true;
}
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second = v[i].first + v[i].second;
        //cout << v[i].first << " " << v[i].second << endl;
    }
    sort(v.begin(), v.end());
    ll ok = -1;
    ll ng = 1e17;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}