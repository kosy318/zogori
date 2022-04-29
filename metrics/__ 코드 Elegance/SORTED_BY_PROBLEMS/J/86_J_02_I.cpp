#include <bits/stdc++.h>

#ifdef LOCAL
    #define watch(x) cout<<(#x)<<" is "<<(x)<<'\n'
    #define dashline() cout<<"================\n"
#else
    #define watch(x)
    #define dashline()
#endif // LOCAL

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    n++;
    int i=3;
    int ans=0,r=1;
    bool f=1;
    while(i<n)
    {
        if (f) {i+=r;f=0;ans++;}
        else
        {
            ans++;
            i+=r;
            r*=2;
            f=1;
        }
    }

    cout<<ans;
    return 0;
}
