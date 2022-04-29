#include <stdio.h>
#include <algorithm>
#include <cstring>

struct info {
    long long s, e;
};

info input[100010];
int n;

bool OK(long long num) {
    long long start = 0;
    int index = 1;

    for(int i = 1; i <= n; i++) {
        if(start > input[i].e)
            return false;
        start = std::max(start, input[i].s) + num;
    }
    return true;
}

int main(void) {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        input[i].s = a;
        input[i].e = a + b;
    }

    std::sort(input + 1, input + 1 + n, [](info a, info b){
       return a.e < b.e;
    });

    long long s = 0, e = 2000000000, r = 0;

    while(s <= e) {
        long long mid = (s + e) / 2;
        if(OK(mid)) {
            s = mid + 1;
            r = std::max(r, mid);
        }
        else
            e = mid - 1;
    }

    printf("%lld\n", r);
}