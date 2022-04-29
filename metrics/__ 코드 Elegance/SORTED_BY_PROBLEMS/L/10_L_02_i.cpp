#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int price[110];
pair<pair<int,int>,int> a[11010];
int dp[10010];
int nex[10010];
int xx[15010];
int func(int here){
    if(here==m||here==1234567890)return 0;
    int &ret=dp[here];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,func(here+1));
    ret=max(ret,func(nex[a[here].first.second])+(a[here].first.second-a[here].first.first)*price[a[here].second]);
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&price[i]);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&a[i].first.first,&a[i].first.second,&a[i].second);
    sort(a,a+m);
    for(int i=0;i<=15000;i++)
        xx[i]=1234567890;
    for(int i=m-1;i>=0;i--){
        xx[a[i].first.first]=i;
    }
    for(int i=15000-1;i>=0;i++)
        xx[i]=min(xx[i],xx[i+1]);
    printf("%d\n",func(0));
}
