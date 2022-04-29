#include <bits/stdc++.h>

using namespace std;

int n;
long long mx = -1;

void solve(int n, long long cnt_a, long long cnt_b){
    if(n <= 2)
    {
        mx = cnt_a + cnt_b - 1;
        return;
    }
    else if(n <= 3)
    {
       mx = cnt_a + cnt_b;
       return;
    }

    int val = n / 2;

    if(n % 2 == 0)
    {
        solve(val, cnt_a + 1, cnt_b + 1);
    }
    else
    {
        cnt_a += 1;
        solve(val, cnt_a + 1, cnt_b + 1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n <= 4) cout<<n - 3;
    else
    {
        solve(n, 0, 0);
        cout<<mx;
    }
    return 0;
}
