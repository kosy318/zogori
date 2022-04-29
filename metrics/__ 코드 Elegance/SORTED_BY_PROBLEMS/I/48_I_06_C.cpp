#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> Point;

Point inp[100005];
int N;
bool chk(ll gap) {
    ll s = inp[1].first; ll e = inp[1].second;
    for (int i = 2; i <= N; i++) {
        s = max(s + gap, inp[i].first);
        if (inp[i].second < s) return 0;
    }
    return 1;
}


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int l, r; scanf("%d %d", &l, &r);
        inp[i] = {l, l + r};
    }
    sort(inp + 1, inp + N + 1);
    ll l = 0, r = 1e15;
    while (l + 1 < r) {
        ll mid = l + r >> 1;
        if (chk(mid)) l = mid;
        else r = mid;
    }
    printf("%lld", l);
}