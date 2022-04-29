#include <bits/stdc++.h>

using namespace std;

struct line {
    int s, e;
};

line arr[100001];
int n;

bool check(int v) {
    int location = arr[0].s;
    for ( int i = 0; i < n-1; i++ ) {
        if ( arr[i+1].e < location + v )
            return false;
        if ( arr[i+1].s > location + v )
            location = arr[i+1].s;
        else
            location += v;
    }
    return true;
}

bool cmp(line a, line b) {
    return a.s < b.s;
}

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int s, d;
        cin >> s >> d;
        arr[i].s = s;
        arr[i].e = s+d;
    }
    sort(arr, arr+n, cmp);

    int mi = 0, ma = 1e9;
    int result = 0;
    while ( mi < ma ) {
        int mid = (ma+mi) / 2;
        if ( check(mid) ) {
            mi = mid+1;
            result = mid;
        }
        else
            ma = mid;
    }
    cout << result << endl;
}
