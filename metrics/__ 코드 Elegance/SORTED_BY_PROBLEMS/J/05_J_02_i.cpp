#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    if(n == 3) cout << 0;
    else if(n==4) cout << 1;
    else cout << (n+1)/2 -1;
}
