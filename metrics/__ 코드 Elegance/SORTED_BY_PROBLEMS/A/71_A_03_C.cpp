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

    int a[1006] = {1,1,2,1,1,2,2,4,4};
    int n;

    scanf("%d", &n);

    if ( n < 9) {
        printf("%d\n", a[n]);
        return 0;
    }
    int k;
    for (int i=9 ; i<=n ; i++) {
//        int buf[200] = {0};
//        for (int k = 1; i - ( 2 * k) >= 0; k++) {
//            buf[a[i - k] * 2 - a[i - 2 * k]] = 1;
//        }
//        for (int j = 1; j < 1005; j++) {
//            if (buf[j] == 0) {
//                a[i] = j;
//            }
//        }

        for (int tmp=1 ; ; tmp++) {
            int k;
            for (k = 1; i - (2 * k) >= 0; k++) {
                if (tmp - a[i - k] == a[i - k] - a[i - (2 * k)])
                    break;
            }
            if (i - (2 * k) < 0) {
                //cout << tmp << ", " << i << endl;
                a[i] = tmp;
                break;            }
        }
    }

    printf("%d", a[n]);
    return 0;
    /*
    for (int i = 0; ; i++) {
        printf("%d\n", buf[i]);
        if (buf[i] == 0) {
            printf("%d\n", i + 1);
            return 0;
        }
    }*/

    return 0;
}