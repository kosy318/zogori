#include<bits/stdc++.h>
using namespace std;


int a,b,c,d,e,n,m;
int o[1111];
int l[1111];

struct P
{
    long long x,y;
    bool operator <(const P &a)const
    {
        return y>a.y;
    }
};

P u[111111];

priority_queue<P> q;

bool as(P a,P b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
    {
    long long n,m;
        scanf("%lld %lld",&n,&m);
        u[t]={n,n+m};
        q.push(u[t]);
    }
    sort(u+1,u+a+1,as);
    long long n=0,m=2000000010;
    for(;n<m;)
    {
        long long h=(n+m)/2+1;
        long long x=0;
        for(;q.size();q.pop());
        for(int t=1;t<=a||q.size();)
        {
            if(q.size()==0&&x<u[t].x) x=u[t].x;
            for(;t<=a&&x>=u[t].x;)
            {
                q.push(u[t]);
                t++;
            }
            if(q.top().y<x)
            {
                m=h-1;
                goto qwe;
            }
            else
            {
            //printf("%lld ",x);
            q.pop();
            x+=h;
            }
        }
        n=h;
        qwe:;
        //puts("");
    }
    printf("%lld",n);
}
