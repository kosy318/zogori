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

vi v[55];
int vid[55];
int dtoid[1011];
bool ex[1011];
bool f[1011];

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL

    int n; cin>>n;
    int m=-1;
    int i,x;
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            cin>>x;
            if(!x) break;
            ex[x]=1;
            v[i].push_back(x);
            dtoid[x]=i;
            m=max(m,x);
        }
    }

    int nxt,id;
    int j;
    int ans=0;
    vector<pii> ansset;
    for(i=1;i<=m;i++) ans+=ex[i];
    for(i=1;i<=m;i++)
    {
        if (f[i]) continue;
        if (!ex[i]) continue;
        id=dtoid[i];
        if (vid[id]==v[id].size())
        {
            ansset.push_back({id,vid[id]});
            continue;
        }
        nxt=v[id][++vid[id]];
        for(j=i+1;j<nxt;j++)
        {
            if (abs(dtoid[j] - id)<=1) break;
        }
        if (j==nxt)
        {
            f[i]=1;
            f[nxt]=1;
            ans-=2;
        }
        else ansset.push_back({id,vid[id]});
    }
    int cnt[55]={};
    cout<<ansset.size()<<'\n';
    for(pii px:ansset) cout<<px.first<<' '<<px.second<<'\n';

    return 0;
}
