#include <iostream>
#include <algorithm>
#include <stdio.h>
#define ll long long


using namespace std;

int bisect_left(int* a, ll lo, ll hi, ll x){
    while (lo < hi){
        ll mid = (lo + hi) / 2;

        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
int bisect_right(int* a, ll lo, ll hi, ll x){
    while (lo < hi){
        ll mid = (lo + hi) / 2;

        if (a[mid] > x)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {

    //freopen("../input", "rb", stdin);

    int buf[200] = {0};
    int a[1005] = {1,1,2,1,1,2,2,4,4};
    int n;

    scanf("%d", &n);

    if ( n < 10) {
        printf("%d\n", a[n]);
        return 0;
    }
    int k;
    for (int i=9 ; i<n ; i++) {
        int flag = 1;
        for (int tmp=1 ; flag ; tmp++) {
            int k;
            for (k = 1; n - (2 * k) >= 0; k++) {
                if (tmp - a[i - k] == a[i - k] - a[i - (2 * k)])
                    break;
            }
            if (n - (2 * k) < 0) {
                a[i] = tmp;
                flag = 0;
            }
        }
    }

    printf("%d", a[n-1]);
    return 0;
    for (int i = 0; ; i++) {
        printf("%d\n", buf[i]);
        if (buf[i] == 0) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    return 0;
}