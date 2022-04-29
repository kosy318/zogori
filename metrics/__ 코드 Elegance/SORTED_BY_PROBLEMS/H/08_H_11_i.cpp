#include<bits/stdc++.h>
using namespace std;


int a,b,c,d,e,n,m;

int l[1111];
long long x=0;
struct P
{
    int x,y,z,z1;
    bool operator <(const P &a)const
    {
        return y>a.y;
    }
};

P u[111111];
P o[5555];
priority_queue<P> q;

bool as(P a,P b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

vector<int> v1;
vector<P> v[2111];
map<int,int> p;


void g(int i,int n,int m,int p,int k)
{
    if(n!=m&&o[i].z)
    {
        int s=o[i].z;
        //if(i*2==3||i*2+1==3) printf("#####%d\n",o[3].x);
        o[i*2].x+=s;
        o[i*2+1].x+=s;
        o[i*2].z+=s;
        o[i*2+1].z+=s;
        o[i].z=0;
    }
    if(n!=m&&o[i].z1)
    {
        int s=o[i].z1;
        o[i*2].y+=s;
        o[i*2+1].y+=s;
        o[i*2].z1+=s;
        o[i*2+1].z1+=s;
        o[i].z1=0;
    }
    if(m<p) return;
    if(n>=p)
    {

        o[i].x+=k;
        o[i].z+=k;
        return;
    }
    g(i*2,n,(n+m)/2,p,k);
    g(i*2+1,(n+m)/2+1,m,p,k);
    long long x=max(max(o[i*2].x+o[i*2].y,o[i*2+1].x+o[i*2+1].y),o[i*2].x+o[i*2+1].y);
    if(x==o[i*2].x+o[i*2].y) o[i]={o[i*2].x,o[i*2].y,0,0};
    else if(x==o[i*2+1].x+o[i*2+1].y) o[i]={o[i*2+1].x,o[i*2+1].y,0,0};
    else o[i]={o[i*2].x,o[i*2+1].y,0,0};
}

void f(int i,int n,int m,int p,int k)
{
    if(n!=m&&o[i].z)
    {
        int s=o[i].z;
        //if(i*2==3||i*2+1==3) printf("#####%d\n",o[3].x);
        o[i*2].x+=s;
        o[i*2+1].x+=s;
        o[i*2].z+=s;
        o[i*2+1].z+=s;
        o[i].z=0;
    }
     if(n!=m&&o[i].z1)
    {
        int s=o[i].z1;
        o[i*2].y+=s;
        o[i*2+1].y+=s;
        o[i*2].z1+=s;
        o[i*2+1].z1+=s;
        o[i].z1=0;
    }
    if(m<p)
    {
    o[i].y+=k;
    o[i].z1+=k;
     return;
    }
    if(n>=p)
    {
        return;
    }
    f(i*2,n,(n+m)/2,p,k);
    f(i*2+1,(n+m)/2+1,m,p,k);
    long long x=max(max(o[i*2].x+o[i*2].y,o[i*2+1].x+o[i*2+1].y),o[i*2].x+o[i*2+1].y);
    if(x==o[i*2].x+o[i*2].y) o[i]={o[i*2].x,o[i*2].y,0,0};
    else if(x==o[i*2+1].x+o[i*2+1].y) o[i]={o[i*2+1].x,o[i*2+1].y,0,0};
    else o[i]={o[i*2].x,o[i*2+1].y,0,0};
}

int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;t++)
    {
        scanf("%d %d",&n,&m);
        u[t]={n,m};
    }
    scanf("%d",&b);
    for(int t=a+1;t<=a+b;t++)
    {
        scanf("%d %d",&n,&m);
        u[t]={n,m};
    }
    scanf("%d %d",&c,&d);
    for(int t=1;t<=a;t++)
    u[t].z=c;
    for(int t=a+1;t<=a+b;t++)
    u[t].z=-d;
    a+=b;
    for(int t=1;t<=a;t++)
    v1.push_back(u[t].x);
    sort(v1.begin(),v1.end());
    v1.resize(unique(v1.begin(),v1.end())-v1.begin());
    for(int h=0;h<v1.size();h++)
    p[v1[h]]=h+1;
    for(int t=1;t<=a;t++)
    u[t].x=p[u[t].x];

    v1.clear();
    p.clear();
    for(int t=1;t<=a;t++)
    v1.push_back(u[t].y);
    sort(v1.begin(),v1.end());
    v1.resize(unique(v1.begin(),v1.end())-v1.begin());
    for(int h=0;h<v1.size();h++)
    p[v1[h]]=h+1;
    for(int t=1;t<=a;t++)
    u[t].y=p[u[t].y];
    sort(u+1,u+a+1,as);
    for(int t=1;t<=a;t++)
    v[u[t].x].push_back(u[t]);
    for(int i=1;i<=a;i++)
    {
        memset(o,0,sizeof(o));
        long long y=0;
        for(int j=i;j<=a;j++)
        {
            for(int h=0;h<v[j].size();h++)
            {
                g(1,0,a,v[j][h].y,-v[j][h].z);
                f(1,0,a,v[j][h].y,-v[j][h].z);
                y+=v[j][h].z;
            }

            x=max(x,y+o[1].x+o[1].y);
            //printf("%lld %d %d %d %d\n",y,o[1].x,o[1].y,o[3].x,o[13].x);
        }

    }/*
    for(int t=1;t<=a;t++)
    {
        printf("%d %d %d\n",u[t].x,u[t].y,u[t].z);
    }*/
    printf("%lld",x);
}

/*
3
0 8
3 3
8 -1
3
1 4
6 0
7 1
3 2


2
-1 -1
4 4
2
0 0
2 2
5 2
*/
