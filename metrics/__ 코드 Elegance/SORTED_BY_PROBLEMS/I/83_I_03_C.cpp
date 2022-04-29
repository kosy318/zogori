#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    long long x;
    long long y;
    const bool operator< (const node &a) {
        return x < a.x;
    }
};

node o[100010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &o[i].x, &o[i].y);
        o[i].y += o[i].x;
    }
    sort(o, o+n);

    long long l = 0, r = 2e9 + 10;
    while(l <= r) {
        long long mid = (l + r) / 2;
        int st = o[0].x;
        int flag = 1;
        for(int i = 1; i < n; i++) {
            if(o[i].x - st >= mid) {
                st = o[i].x;
                continue;
            }
            if(st + mid <= o[i].y) st = st + mid;
            else {
                flag = 0;
                break;
            }
        }

        if(flag) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", l - 1);
    return 0;
}