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
node a[N];
priority_queue<pii,vector<pii>,greater<pii> > ans;

ll func(int i)
{
    return (ll)(a[i].e-a[i].s)*price[a[i].t];
}

int main()
{
    //freopen("input","r",stdin);
    cin>>m>>n;
    for(int i=1;i<=m;i++) scanf("%d",price+i);
    for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].t);
    sort(a+1,a+n+1);
    ll dap=func(1);
    ans.push({a[1].e,dap});
    ll tmp=0;
    for(int i=2;i<=n;i++)
    {
        while(!ans.empty()&&ans.top().ff<=a[i].s)
        {
            tmp=max(tmp,ans.top().ss);
            ans.pop();
        }
        ll ttmp=func(i);
        ans.push({a[i].e,tmp+ttmp});
        dap=max(dap,tmp+ttmp);
    }
    cout<<dap;
    return 0;
}
