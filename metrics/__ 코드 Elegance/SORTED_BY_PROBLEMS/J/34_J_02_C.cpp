#include <bits/stdc++.h>

using namespace std;
using lint = long long;

lint n;
int main() {
    cin >> n;

    lint k = 0;
    while(!(3 * (k == 0 ? 0 : (1ll<<(k-1))) < n && n <= 3 * (1ll<<k))) {
        k++;
    }

    assert((3 * (k == 0 ? 0 : (1ll<<(k-1))) < n && n <= 3 * (1ll<<k)));

    if(n <= (1ll << (k+1))) {
        cout << (2 * k - 1) << endl;
    }else {
        cout << (2 * k) << endl;
    }
    return 0;
}