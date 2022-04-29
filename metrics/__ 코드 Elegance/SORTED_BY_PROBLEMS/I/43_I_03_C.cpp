#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll>p;
p xy[100005];
ll n, ans;

int chk(ll mid){
    ll now = xy[0].first;
    for(int i = 1;i<n;i++){
        ll nnow = now + mid;
        if(xy[i].second < nnow) return 0;
        else{
            if(nnow < xy[i].first) now = xy[i].first;
            else now = nnow;
        }
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        ll a, b;
        scanf("%d %d",&a,&b); xy[i] = {a, a + b};
    }
    sort(xy,xy+n);
    ll s = 0, e = 3000000000;
    while(s <= e){
        ll mid = (s+e)/2;
        if(chk(mid)) ans = max(ans,mid), s = mid+1;
        else e = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
