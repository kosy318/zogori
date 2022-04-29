#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        int a = (n - 7) / 6;
        int b = (n - 7) % 6;

        cout << (3+2*a+((b<2)?0:1)) << endl;
    }

    return 0;
}
