#include <bits/stdc++.h>

using namespace std;

int ans[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ans[3] = 0;
    ans[4] = 1;
    ans[5] = 2;
    ans[6] = 2;

    for(int i=7; i<=n; i++) {
        if(n%2) ans[i] = 2 + ans[i/2];
        else ans[i] = 1 + ans[i-1];
    }
    cout << ans[n];

    return 0;
}
