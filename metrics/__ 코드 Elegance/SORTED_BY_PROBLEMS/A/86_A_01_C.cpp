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
    int i,k,v;
    int d[1011]={1};
    bool f;
//    int mx=-1;
    for(i=1;i<=n;i++)
    {
        v=1;
        for(v=1;;v++)
        {
            f=1;
            for(k=1;2*k<=i;k++)
            {
                if (v-d[i-k] == d[i-k]-d[i-2*k]) {f=0; break;}
            }
            if (f) break;
        }
        d[i]=v;
    }

    //for(i=0;i<=n;i++) cout<<d[i]<<' ';
    cout<<d[n];
    return 0;
}
