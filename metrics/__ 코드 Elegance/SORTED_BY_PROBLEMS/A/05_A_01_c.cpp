#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second

int n, a[1234], chk[1234567];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    a[0] = 1;
    for(int i=1; i<=1000; ++i){
        for(int j=1; ;++j){
            int y = i-j;
            int x = i-j-j;
            if(x < 0) break;
            int tmp = 2*a[y]-a[x];
            if(0 <= tmp && tmp < 1234567)
                chk[tmp] = i;
        }
        for(int k=1; ;++k)
            if(chk[k] != i){
                a[i] = k;
                break;
            }
    }
    cin >> n;
    cout << a[n];
}
