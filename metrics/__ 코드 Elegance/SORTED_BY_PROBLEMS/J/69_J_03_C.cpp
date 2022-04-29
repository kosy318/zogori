#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int f[maxn];
int n;

int main()
{
    cin >> n;
    f[3] = 0;
    f[4] = 1;
    f[5] = 2;
    for (int i = 6; i <= n; i++) {
        f[i] = f[i - i / 2] + 2;
    }
    cout << f[n] << endl;
    return 0;
}
