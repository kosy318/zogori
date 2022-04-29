#include<stdio.h>
#include<vector>
#include<algorithm>

using ll = long long;

ll N;
std::vector<std::pair<ll, ll> > v;

bool go(int x){
    ll prev = -2e9;
    for(const auto &i : v){
        prev = std::max(prev+x, i.first);
        if(prev > i.first+i.second) return 0;
    }
    return 1;
}

int main() {
    scanf("%lld", &N);
    for(ll i=0; i<N; i++){
        ll x,y;
        scanf("%lld %lld", &x, &y);
        v.push_back({x,y});
    }
    std::sort(v.begin(), v.end());
    ll left=0, right=2e9;
    while(left < right){
///        printf("%lld %lld""\n", left, right);
        ll mid = (left+right)/2;
        if(go(mid)) left = mid + 1;
        else right = mid - 1;
    }
    for(ll mid = left-3; ; mid++){
//        printf("%d %d\n", mid, go(mid));
        if(!go(mid)) {printf("%lld", mid-1); break;}
    }
    return 0;
}