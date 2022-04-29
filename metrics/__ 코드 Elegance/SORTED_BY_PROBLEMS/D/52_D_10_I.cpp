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
            if(p.x>p.y) swap(p.x,p.y);
            num[p.x][p.y]++;
        }
    }
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
    {
        ans-=num[i][j]/2*2;
        era[i][j]=num[i][j]/2*2;
    }
    printf("%d",ans);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            S p=V[i][j];
            if(era[p.x][p.y]) era[p.x][p.y]--;
            else printf("\n%d %d",i,j+1);
        }
    }
    return 0;
}
/*
6
20 39 45 52 67 70 0
6 9 28 32 34 46 0
7 11 25 0
8 13 0
19 33 43 49 67 81 0

12
4 12 22 0
15 17 30 0
7 16 25 36 46 48 0
4 17 0
8 13 27 0
6 23 26 29 0
15 33 45 52 68 0
19 37 0
20 25 40 46 52 0
14 32 35 45 62 76 0
7 10 25 41 46 52 0
*/
