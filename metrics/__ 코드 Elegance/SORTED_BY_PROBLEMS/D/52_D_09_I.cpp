#include<bits/stdc++.h>
using namespace std;

struct S
{
    int l,x,y;
    bool operator<(const S& aa) const
    {
        return l<aa.l;
    }
};
vector<S> V[51];
int n,num[51][51],era[51][51],a[51],now,lo,ans;

int main()
{
    scanf("%d",&n);
    for(int p,i=1;i<n;i++)
    {
        while(1)
        {
            scanf("%d",&p);
            if(p==0) break;
            V[i].push_back({p,0,0});
        }
    }
    for(int i=1;i<=n;i++)
    {
        now=0; lo=i;
        while(1)
        {
            int now1=10001,now2=10001;
            vector<S>::iterator it1,it2;
            if(lo<n)
            {
                S p={now,0,0};
                it1 = lower_bound(V[lo].begin(),V[lo].end(),p);
                if(it1 != V[lo].end()) now1=it1->l;
            }
            if(lo>1)
            {
                S p={now,0,0};
                it2 = lower_bound(V[lo-1].begin(),V[lo-1].end(),p);
                if(it2 != V[lo-1].end()) now2=it2->l;
            }
            //printf("%d : %d %d %d %d\n",i,now,lo,now1,now2);
            if(now1==10001&&now2==10001) break;
            if(now1<now2)
            {
                now=now1+1,lo++;
                if(it1->x==0) it1->x=i;
                else it1->y=i;
            }
            else
            {
                now=now2+1,lo--;
                if(it2->x==0) it2->x=i;
                else it2->y=i;
            }
        }
        a[i]=lo;
    }
    //for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
    for(int i=1;i<n;i++)
    {
        for(auto p : V[i])
        {
            ans++;
            if(p.x<p.y) num[p.x][p.y]++;
            else num[p.y][p.x]++;
        }
    }
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
    {
        ans-=num[i][j]/2*2;
        era[i][j]=num[i][j]/2*2;
    }
    printf("%d\n",ans);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            S p=V[i][j];
            if(era[p.x][p.y]) era[p.x][p.y]--;
            else printf("%d %d\n",i,j+1);
        }
    }
    return 0;
}
