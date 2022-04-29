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

int  solve(int n) {
    if (n==3)
        return 0;
    if (n==4)
        return 1;
    if (n%2 ==0 )
        return solve(n/2) + 2;
    else
        return solve(n-1) + 1;

}

int main() {

    //freopen("../input", "rb", stdin);

    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
}