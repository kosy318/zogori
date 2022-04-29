#include<bits/stdc++.h>
#define llt long long
#define _1 first
#define _2 second
using namespace std;

vector<pair<int,llt>> V[100001];
int n,mom[100001],root;
llt num[100001],sum[100001],sum2[100001],ans;

void dfs(int p)
{
    if(V[p].size()==1)
    {
        num[p]=1;
        return;
    }
    for(auto pp : V[p])
    {
        int q=pp._1; llt c=pp._2;
        if(q != mom[p])
        {
            mom[q]=p;
            dfs(q);
            num[p]+=num[q];
            sum[p]+=sum[q]+num[q]*c;
            sum2[p]+=sum2[q]+2*sum[q]*c+num[q]*c*c;
        }
    }
    //printf("%d %lld %lld %lld\n",p,num[p],sum[p],sum2[p]);
    for(auto pp : V[p])
    {
        int q=pp._1; llt c=pp._2;
        if(q == mom[p]) continue;
        llt c1 = sum[q]+num[q]*c;
        llt c2 = sum2[q]+2*sum[q]*c+num[q]*c*c;
        ans+=c2*(num[p]-num[q]);
        //printf("%d %lld %lld %lld\n",q,c1,c2,ans);
        ans+=c1*(sum[p]-c1);
        //printf("%d %lld %lld %lld\n",q,c1,c2,ans);

    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        llt dd; int p,q;
        scanf("%d%d%lld",&p,&q,&dd);
        V[p].push_back({q,dd});
        V[q].push_back({p,dd});
    }
    for(int i=1;i<=n;i++)
    {
        if(V[i].size()!=1)
        {
            root=i;
            dfs(i);
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
