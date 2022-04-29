#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[10100];
int nex[15010];
int cst[110];
int n,m;
pair<pair<int,int>,int> a[10100];
int func(int here){
    if(here==m||here==1234567890)return 0;
    int &ret=dp[here];
    if(ret!=-1)return ret;
    ret=max(ret,func(here+1));
    ret=max(ret,func(nex[a[here].first.second])+(a[here].first.second-a[here].first.first)*cst[a[here].second]);
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&cst[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a[i].first.first,&a[i].first.second,&a[i].second);
    }
    sort(a,a+m);
    for(int i=15000;i>=0;i--)
        nex[i]=1234567890;
    for(int i=m-1;i>=0;i--)
        nex[a[i].first.first]=i;
    for(int i=15000-1;i>=0;i--)
        nex[i]=min(nex[i],nex[i+1]);
    printf("%d\n",func(0));
}
