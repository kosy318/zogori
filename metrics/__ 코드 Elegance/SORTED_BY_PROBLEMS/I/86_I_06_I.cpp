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

pii arr[100011];
int n;
bool check(int mid)
{
    int i;
    int lx=-1;
    for(i=1;i<=n;i++)
    {
        if (lx==-1)
        {
            lx=arr[i].first;
            continue;
        }
        if (lx+mid>arr[i].second) return 0;
        if (lx+mid<=arr[i].first)
        {
            lx=arr[i].first;
            continue;
        }
        else lx+=mid;
    }
    return 1;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input3.txt","r",stdin);
    #endif
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        arr[i].second+=arr[i].first;
    }
    sort(arr+1,arr+n+1);

    int l=1,r=2e9,mid;
    while(l+1<r)
    {
        mid=l+r>>1;
        if (check(mid)) l=mid;
        else r=mid;
    }
    cout<<l;

    return 0;
}
