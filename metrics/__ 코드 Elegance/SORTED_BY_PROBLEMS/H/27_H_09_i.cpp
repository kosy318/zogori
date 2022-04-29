#include<bits/stdc++.h>
using namespace std;

int i,j,a,b,c1,c2,n,x[2222],u,y[2222];
long long m,d[2222],S[2222];
long long ans=0;

struct A{
    int x,y;
    long long z;
}dat[2222];
bool cmp(A aa,A bb){return aa.x<bb.x;}

long long seg[1<<12],mseg[1<<12],lseg[1<<12],rseg[1<<12],Z=1<<11;

vector<int>X,Y;

int main()
{
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }scanf("%d",&b);
    for(i=a;i<a+b;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    scanf("%d%d",&c1,&c2);
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    for(i=0;i<a+b;i++)
    {
        x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
        y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
        dat[i].x=x[i];
        dat[i].y=y[i];
        if(i<a)dat[i].z=c1;
        else dat[i].z=-c2;
    }
    sort(dat,dat+a+b,cmp);

    for(i=0;i<a+b;i++)
    {
        for(j=0;j<Z*2;j++)mseg[j]=lseg[j]=rseg[j]=seg[j]=0;
        for(j=i;j<a+b;j++)
        {
            u=Z+j;
            seg[u]=dat[j].z;
            lseg[u]=max(seg[u],0ll);
            rseg[u]=lseg[u];
            mseg[u]=lseg[u];
            u/=2;
            while(u!=0)
            {
                seg[u]=seg[2*u]+seg[2*u+1];
                lseg[u]=max(lseg[2*u],seg[2*u]+lseg[2*u+1]);
                rseg[u]=max(rseg[2*u+1],seg[2*u+1]+rseg[2*u]);
                mseg[u]=max(max(lseg[2*u+1]+rseg[2*u],mseg[2*u]),mseg[2*u+1]);
                u/=2;
            }
            ans=max(mseg[1],ans);
        }
    }



    printf("%lld",ans);
}

/*
int n,K,i,j,k;

long long S,MJ,MM,r[102],g[102],b[102],rr,gg,bb;
long long D[52][102][102];

int main()
{
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&r[i],&g[i],&b[i]);
        S+=r[i]*r[i]+g[i]*g[i]+b[i]*b[i];
        rr+=r[i];
        gg+=g[i];
        bb+=b[i];
    }
    MJ=S*n-rr*rr-gg*gg-bb*bb;
    MM=n;

    if(K==2)
    {

    }
    long double ans=0;
    ans+=(long double)S;
    ans-=(long double)MJ/(long double)MM;
    ans*=1000000;
    long long ANS=(long long)ans;
    printf("%.6Lf",ans);
}
/*
2 1
36 16 85
74 87 38
*/

