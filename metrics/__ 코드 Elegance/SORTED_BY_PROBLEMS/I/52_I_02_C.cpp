#include<bits/stdc++.h>
#define llt long long
using namespace std;

struct point
{
    llt x,y;
} a[100001];
bool cmp(point p,point q){return p.x<q.x;}

int n;
llt s,e,now;
bool check;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].y+=a[i].x;
        e=max(e,a[i].y);
    }
    e=e/(n-1)+1;
    sort(a+1,a+n+1,cmp);
    while(s<e)
    {
        llt mid=(s+e+1LL)/2;
        now=a[1].x;
        check=true;
        for(int i=2;i<=n;i++)
        {
            if(a[i].x>now+mid) now=a[i].x;
            else if(a[i].y<now+mid)
            {
                check=false;
                break;
            }
            else now+=mid;
        }
        if(check) s=mid;
        else e=mid-1;
    }
    printf("%lld",s);
    return 0;
}
