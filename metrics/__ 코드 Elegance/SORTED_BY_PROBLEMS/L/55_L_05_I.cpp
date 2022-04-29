#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define pb push_back
#define ff first
#define ss second
#define N 10010

struct node
{
    int s,e,t;
    bool operator<(const node &rhs)const
    {
        if(s==rhs.s) return e<rhs.e;
        return s<rhs.s;
    }
};

int n,m,price[110];
ll dap=-1;
node a[N];
set<pii> ans;

int main()
{
   // freopen("input","r",stdin);
    cin>>m>>n;
    for(int i=1;i<=m;i++) scanf("%d",price+i);
    for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].t);
    sort(a+1,a+n+1);
    ans.insert({a[1].e,(ll)(a[1].e-a[1].s)*price[a[1].t]});
    auto pos=ans.begin();
    int flag=0;
    ll tmp=0;
    for(int i=2;i<=n;i++)
    {
        if(!flag&&ans.begin()->ff<=a[i].s) flag=1,pos=ans.begin();
        if(flag)
        {
            while(pos!=ans.end()&&pos->ff<=a[i].s)
            {
                tmp=max(tmp,pos->ss);
                ++pos;
            }
        }
        ans.insert({a[i].e,tmp+(ll)(a[i].e-a[i].s)*price[a[i].t]});
        dap=max(dap,tmp+(ll)(a[i].e-a[i].s)*price[a[i].t]);
    }
//    for(int i=1;i<=m;i++) printf("%d\n",price[i]);
    //for(int i=1;i<=n;i++) printf("%d %d %d\n",a[i].s,a[i].e,a[i].t);
    //for(auto i:ans) printf("%d %lld\n",i.ff,i.ss);
    cout<<dap;
    return 0;
}
