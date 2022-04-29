/*
#include<bits/stdc++.h>
using namespace std;

int a,i,j,x[1<<20];
int main()
{
    x[3]=0;
    x[4]=1;

    for(i=4;i<(1<<20);)
    {
        for(j=i+1;j<=i+(i/2);j++)
        {
            x[j]=x[i]+1;
        }
        for(j=i+(i/2)+1;j<=i*2;j++)
        {
            x[j]=x[i]+2;
        }
        i*=2;
    }
    scanf("%d",&a);
    printf("%d",x[a]);
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int a,i,j,ch;
long long p,q,h,m;

struct A{
    long long x,l;
}dat[100003];
bool cmp(A aa,A bb){return aa.x<bb.x;}

int main()
{
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%lld%lld",&dat[i].x,&dat[i].l);
    }
    sort(dat,dat+a,cmp);
    p=0;
    q=1e9;q*=2;
    while(p!=q-1)
    {
        h=(p+q)/2;
        m=0;
        ch=0;
        for(i=0;i<a;i++)
        {
           if(m>dat[i].x+dat[i].l)
           {
            ch=1;
                break;
           }
           else
           {
                m=min(m,dat[i].x);
                m+=h;
           }
        }
        if(ch)q=h;
        else p=h;
    }
    printf("%lld",p);
}*/
/*
6
0 67
127 36
110 23
50 51
100 12
158 17
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ppair;
vector<ppair>v[15010];
int n,m,b[15010],d[15010];
int main()
{
    //freopen("input.txt","r",stdin);
    int i,j,x,y,t;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&x,&y,&t);
        v[y].push_back(make_pair(x,t));
    }
    for(i=1;i<=15000;i++)
    {
        d[i]=d[i-1];
        for(j=0;j<v[i].size();j++)
        {
            x=v[i][j].first;
            y=i;
            t=v[i][j].second;
            d[i]=max(d[i],d[x]+(y-x)*b[t]);
        }
    }
    printf("%d",d[15000]);
    return 0;
}
