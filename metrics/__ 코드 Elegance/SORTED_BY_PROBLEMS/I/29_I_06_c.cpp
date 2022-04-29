#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

const int MAX_N=100001;

int N;
P point[MAX_N];

bool check(int D) {
    ll start = point[0].first;
    for (int i=1; i<N; i++) {
        start = max(start+D, point[i].first);
        if (point[i].first + point[i].second < start) return false;
    }
    return true;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        point[i] = P(a,b);
    }
    sort(point, point+N);

    ll left = 0;
    ll right = 2e9;

    ll ret = 0;
    while (left <= right) {
        ll mid = (left+right)/2;
        if (check(mid)) {
            left = mid + 1;
            ret = max(ret, mid);
        } else {
            right = mid - 1;
        }
    }
    printf("%lld\n", ret);
    return 0;
}