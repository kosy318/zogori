#include<bits/stdc++.h>
using namespace std;
int dp[15010]={0};
int f[15010]={0};
struct data
{
    int x,y,z;
};data st[100000];
inline bool cmp(const data a,const data b)
{
    return a.y<b.y || (a.y==b.y && a.x<b.x);
}
int main()
{
    int n,m,i,l=0,mt,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&f[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&st[i].x,&st[i].y,&st[i].z);
        l=max(l,max(st[i].x,st[i].y));
    }
    sort(st,st+m,cmp);
    for(i=0;i<m;i++)
    {
        mt=0;
        for(j=0;j<=st[i].x;j++)
        {
            mt=max(mt,dp[j]);
        }
        dp[st[i].y]=max(dp[st[i].y],mt+f[st[i].z]*(st[i].y-st[i].x));
    }
    mt=0;
    for(j=0;j<=l;j++)
    {
        mt=max(mt,dp[j]);
    }
    printf("%d",mt);
    return 0;
}
