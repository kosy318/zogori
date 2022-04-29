#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
pii a[100005];

bool f(ll x){
    ll bef = -x;
    for(int i = 1; i <= n; i++){
        if(bef + x > a[i].first + a[i].second) return false;
        bef = max((long long)a[i].first, bef + x);
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &a[i].first, &a[i].second);
    sort(a + 1, a + 1 + n);

    ll s = 0, e = 2000000000, ans = 2000000000;
    while(s <= e){
        ll mid = (s + e) / 2;
        if(f(mid)) ans = mid, s = mid + 1;
        else e = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}
