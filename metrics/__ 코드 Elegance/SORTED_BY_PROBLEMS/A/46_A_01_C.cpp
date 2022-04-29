#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int mat[1001][1001];
    int ans[1001];
    ans[0] = 1;
    ans[1] = 1;
    for(int i=2; i<=n; i++) {
        int ret = 1;
        for(int k=i/2; k>=1; k--) {
            int d = ans[i-k] - ans[i-2*k];
            mat[i][ans[i-k]+d] = -1;

        }
        for(int k=1; k<=n; k++) {
            if(mat[i][k] != -1) {
                ans[i] = k;
                break;
            }
        }
    }
    cout << ans[n];

    return 0;
}
