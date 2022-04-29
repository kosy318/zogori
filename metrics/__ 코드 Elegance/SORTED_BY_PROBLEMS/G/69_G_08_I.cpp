#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
pair<long long, long long> p[maxn];
int a[maxn],b[maxn],c[maxn],dp[maxn],cur=0;

const int maxs = 100010 << 3;

int mn[maxs];

void modify(int x, int l, int r, int x0, int val)
{
    if (l == r) {
        mn[x] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x0 <= mid) modify(x << 1, l, mid, x0, val);
    else modify(x << 1 | 1, mid + 1, r, x0, val);
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}

int query(int x, int l, int r, int l0, int r0)
{
    if (l == l0 && r == r0) {
        return mn[x];
    }
    int mid = (l + r) >> 1;
    if (r0 <= mid) return query(x << 1, l, mid, l0, r0);
    else if (l0 > mid) return query(x << 1 | 1, mid + 1, r, l0, r0);
    else return min(query(x << 1, l, mid, l0, mid), query(x << 1 | 1, mid + 1, r, mid + 1, r0));
}

void build(int x, int l, int r, int val)
{
    mn[x] = val;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(x << 1, l, mid, val);
    build(x << 1 | 1, mid + 1, r, val);
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first;
    for(int i=0;i<n;i++)
        cin>>p[i].second;
    sort(p,p+n);
    for(int i=1;i<=n;i++)
    {
        a[i]=p[i-1].first;
        b[i]=p[i-1].second;
    }
    build(1,1,n,1e9);
    int start = 1;
    while(start<=n)
    {
        if(b[start]==b[1])
        {
            modify(1,1,n,start,1);
            dp[start]=1;
            start++;
        }
        else break;
    }
    if(start > n)
    {
        cout<<1<<endl;
        exit(0);
    }
    int last=0,cur=1,res=1e9;
    for(int i=start;i<=n;i++)
    {
        if(b[i]!=b[i-1])
        {
            last = cur;
            cur = i;
            res=1e9;
        }
        int ans=0;
        if(last != 0){
            int u=a[cur]*2-a[i];
            int v=a[cur-1]*2-a[i];
            int p=lower_bound(a+1,a+n+1,v)-a;
            int q=upper_bound(a+1,a+n+1,u)-a-1;
            int low=max(p,last);
            int high=min(q,cur-1);
            if(low<=high)ans=max(ans,query(1,1,n,low,high));
        }
        if(cur<=i-1)ans=max(ans,query(1,1,n,cur,i-1));
        dp[i]=ans+1;
        res=min(res,dp[i]);
        modify(1,1,n,i,dp[i]);
        //cout<<i<<" "<<last<<" "<<cur<<" "<<dp[i]<<endl;
    }
    cout<<res<<endl;
return 0;
}
