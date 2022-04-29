#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Info {
    ll start, end;
    bool operator <(const Info& O) { return start < O.start;}
};

int n;
Info info[100000];

bool is_possible(ll p)
{
    ll curr = info[0].start;

    for(int i=1; i<n; i++) {
        if(info[i].end < curr + p)
            return false;
        else
            curr = max(curr + p, info[i].start);
    }
    return true;
}

int main() {

    int p, q;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &p, &q);
        info[i].start = p, info[i].end = p + q;
    }

    sort(info, info + n);

    ll l = 0, r = ~(1 << 31);
    while(l < r - 1)
    {
        ll mid = (ll(l) + ll(r)) / 2;

        if(is_possible(mid)) l = mid;
        else r = mid - 1;
    }

    if(is_possible(l + 1))
        printf("%d", l + 1);
    else
        printf("%d", l);
    return 0;
}