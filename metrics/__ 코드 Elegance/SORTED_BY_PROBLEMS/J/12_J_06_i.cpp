#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void report(int n) {
    cout << n << endl;
    exit(0);
}

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    if(n == 3) cout << 0 << endl;
    else if(n == 4) cout << 1 << endl;
    else if(n == 5) cout << 2 << endl;
    else if(n == 6) cout << 2 << endl;
    else {
        int res = 2;
        n -= 6;
        int a = 6;
        int b = 2;

        while(n > 0) {
            if(n <= b) report(res+1);
            if(n <= a) report(res+2);
            res += 2;
            n -= a;
            a *= 2;
            b *= 2;
        }
    }

    return 0;
}
