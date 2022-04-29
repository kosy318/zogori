#include<bits/stdc++.h>
using namespace std;

int a,b,i,j,c1,c2,x[2222],y[2222];
long long d[2222];
long long ans=0;

vector<int>X,Y;

int main()
{
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        X.push_back(x[i]);
    }
    scanf("%d",&b);
    for(i=a;i<a+b;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        X.push_back(x[i]);
    }
    scanf("%d%d",&c1,&c2);
    sort(X.begin(),X.end());
    for(i=0;i<a+b;i++)
    {
        x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
        if(i<a)d[x[i]+1]=c1;
        else d[x[i]+1]=-c2;
    }

    for(i=1;i<=X.size();i++)
    {
        d[i]=d[i-1]+d[i];
    }
    for(i=0;i<=X.size();i++)
    {
        for(j=i+1;j<=X.size();j++)
        {
            ans=max(ans,d[j]-d[i]);
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

