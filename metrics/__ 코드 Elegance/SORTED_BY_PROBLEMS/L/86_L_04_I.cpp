#include <bits/stdc++.h>

#ifdef LOCAL
    #define watch(x) cout<<(#x)<<" is "<<(x)<<'\n'
    #define dashline() cout<<"================\n"
#else
    #define watch(x)
    #define dashline()
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX=2e9;

int price[111];
int n,m;
pair<pii,int> arr[10011];

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("input3.txt","r",stdin);
    cin>>m>>n;
    int i;
    for(i=1;i<=m;i++) cin>>price[i];
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    }
    sort(arr+1,arr+1+n);
    arr[n+1].first.first=MX;

    int d[15011]={};
    int id=1;
    int cur;
    int e,v;
    for(i=1;i<=15000;i++)
    {
        d[i]=max(d[i],d[i-1]);
        //watch(d[i]);
        cur=arr[id].first.first;
        //watch(id);
        //watch(i);
        //dashline();
        if (i<cur) continue;
        while(cur==i)
        {

            e=arr[id].first.second;
            v=(e-cur)*price[arr[id].second];
            d[e]=max(d[e],d[i]+v);
            id++;
            cur=arr[id].first.first;
        }
    }

    cout<<d[15000];

    return 0;
}
