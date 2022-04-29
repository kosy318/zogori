#include<bits/stdc++.h>
using namespace std;


int n,K,i,j,k,l;

long long C,S,MJ,MM,r[102],g[102],b[102],st1[102],sz1,st2[102],sz2,rr,gg,bb;

struct V{
    long long x,y,z;
}v1,v2,v3;

long double o,R,G,B;

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

    long double ans=0;
    ans=(long double)MJ/(long double)MM;

    if(K==2)
    {
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    v1={r[j]-r[i],g[j]-g[i],b[j]-b[i]};
                    v2={r[k]-r[i],g[k]-g[i],b[k]-b[i]};
                    v3={v1.y*v2.z-v1.z*v2.y,v1.z*v2.x-v1.x*v2.z,v1.x*v2.y-v1.y*v2.x};
                    C=v3.x*r[i]+v3.y*g[i]+v3.z*b[i];
                    sz1=0;
                    sz2=0;
                    for(l=1;l<=n;l++)
                    {
                        if(v3.x*r[l]+v3.y*g[l]+v3.z*b[l]<C){
                        st1[sz1++]=l;
                        }
                        else if(v3.x*r[l]+v3.y*g[l]+v3.z*b[l]>C)
                        {
                            st2[sz2++]=l;
                        }
                        else continue;
                    }

                    st1[sz1++]=i;
                    st1[sz1++]=j;
                    st1[sz1++]=k;
                    o=0;
                    R=G=B=0;

                    for(l=0;l<sz1;l++)
                    {
                        o+=r[st1[l]]*r[st1[l]]+g[st1[l]]*g[st1[l]]+b[st1[l]]*b[st1[l]];

                        R+=r[st1[l]];
                        G+=g[st1[l]];
                        B+=b[st1[l]];
    long double ans=0;
    ans=(long double)MJ/(long double)MM;;
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz1;
                    G/=(long double)sz1;
                    B/=(long double)sz1;
                    o-=(R+G+B);

                    R=G=B=0;

                    for(l=0;l<sz2;l++)
                    {
                        o+=r[st2[l]]*r[st2[l]]+g[st2[l]]*g[st2[l]]+b[st2[l]]*b[st2[l]];

                        R+=r[st2[l]];
                        G+=g[st2[l]];
                        B+=b[st2[l]];
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz2;
                    G/=(long double)sz2;
                    B/=(long double)sz2;
                    o-=(R+G+B);

                    ans=min(ans,o);
                    sz1--;sz1--;sz1--;




                    st1[sz1++]=i;
                    st1[sz1++]=j;
                    st2[sz2++]=k;
                    o=0;
                    R=G=B=0;

                    for(l=0;l<sz1;l++)
                    {
                        o+=r[st1[l]]*r[st1[l]]+g[st1[l]]*g[st1[l]]+b[st1[l]]*b[st1[l]];

                        R+=r[st1[l]];
                        G+=g[st1[l]];
                        B+=b[st1[l]];
    long double ans=0;
    ans=(long double)MJ/(long double)MM;;
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz1;
                    G/=(long double)sz1;
                    B/=(long double)sz1;
                    o-=(R+G+B);

                    R=G=B=0;

                    for(l=0;l<sz2;l++)
                    {
                        o+=r[st2[l]]*r[st2[l]]+g[st2[l]]*g[st2[l]]+b[st2[l]]*b[st2[l]];

                        R+=r[st2[l]];
                        G+=g[st2[l]];
                        B+=b[st2[l]];
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz2;
                    G/=(long double)sz2;
                    B/=(long double)sz2;
                    o-=(R+G+B);

                    ans=min(ans,o);
                    sz1--;sz1--;sz2--;


                    st1[sz1++]=i;
                    st2[sz2++]=j;
                    st1[sz1++]=k;
                    o=0;
                    R=G=B=0;

                    for(l=0;l<sz1;l++)
                    {
                        o+=r[st1[l]]*r[st1[l]]+g[st1[l]]*g[st1[l]]+b[st1[l]]*b[st1[l]];

                        R+=r[st1[l]];
                        G+=g[st1[l]];
                        B+=b[st1[l]];
    long double ans=0;
    ans=(long double)MJ/(long double)MM;;
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz1;
                    G/=(long double)sz1;
                    B/=(long double)sz1;
                    o-=(R+G+B);

                    R=G=B=0;

                    for(l=0;l<sz2;l++)
                    {
                        o+=r[st2[l]]*r[st2[l]]+g[st2[l]]*g[st2[l]]+b[st2[l]]*b[st2[l]];

                        R+=r[st2[l]];
                        G+=g[st2[l]];
                        B+=b[st2[l]];
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz2;
                    G/=(long double)sz2;
                    B/=(long double)sz2;
                    o-=(R+G+B);

                    ans=min(ans,o);
                    sz1--;sz2--;sz1--;


                    st2[sz2++]=i;
                    st2[sz2++]=j;
                    st2[sz2++]=k;
                    o=0;
                    R=G=B=0;

                    for(l=0;l<sz1;l++)
                    {
                        o+=r[st1[l]]*r[st1[l]]+g[st1[l]]*g[st1[l]]+b[st1[l]]*b[st1[l]];

                        R+=r[st1[l]];
                        G+=g[st1[l]];
                        B+=b[st1[l]];
    long double ans=0;
    ans=(long double)MJ/(long double)MM;;
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz1;
                    G/=(long double)sz1;
                    B/=(long double)sz1;
                    o-=(R+G+B);

                    R=G=B=0;

                    for(l=0;l<sz2;l++)
                    {
                        o+=r[st2[l]]*r[st2[l]]+g[st2[l]]*g[st2[l]]+b[st2[l]]*b[st2[l]];

                        R+=r[st2[l]];
                        G+=g[st2[l]];
                        B+=b[st2[l]];
                    }
                    R*=R;

                    G*=G;
                    B*=B;
                    R/=(long double)sz2;
                    G/=(long double)sz2;
                    B/=(long double)sz2;
                    o-=(R+G+B);

                    ans=min(ans,o);
                    sz2--;sz2--;sz2--;

                }
            }
        }
    }
    printf("%.6Lf",ans);
}
/*
2 1
36 16 85
74 87 38
*/

