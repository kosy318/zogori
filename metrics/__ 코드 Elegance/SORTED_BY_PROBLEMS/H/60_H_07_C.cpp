#include <stdio.h>
#include <algorithm>

struct segTree{
    int sum0[10010];
    int maxL[10010];
    int maxR[10010];
    int max0[10010];

    void clear()
    {
        for(int i=0;i<=10000;i++) sum0[i] = maxL[i] = maxR[i] = max0[i] = 0;
    }

    void update(int k)
    {
        sum0[k] = sum0[2*k] + sum0[2*k+1];
        maxL[k] = maxL[2*k] > sum0[2*k]+maxL[2*k+1]? maxL[2*k] : sum0[2*k]+maxL[2*k+1];
        maxR[k] = maxR[2*k+1] > sum0[2*k+1]+maxR[2*k]? maxR[2*k+1] : sum0[2*k+1]+maxR[2*k];
        max0[k] = max0[2*k] > max0[2*k+1]? max0[2*k] : max0[2*k+1];
        max0[k] = max0[k]>maxR[2*k]+maxL[2*k+1]? max0[k]:maxR[2*k]+maxL[2*k+1];
    }
    void add(int ind, int val, int l =1, int r = 2000, int v=1)
    {
        if(l==r)
        {
            sum0[v] += val, maxL[v] += val, maxR[v] += val, max0[v] += val;
            return;
        }
        int h = (l+r)/2;
        if(ind<=h) add(ind,val,l,h,2*v);
        else add(ind,val,h+1,r,2*v+1);
        update(v);
    }

    int getMax()
    {
        return max0[1];
    }
}T;


struct str{
    int first;
    int second;

    int x0;
    int y0;
    int color;
}x[2010];

bool cmp1(str a, str b)
{
    return a.first<b.first;
}
bool cmp2(str a, str b)
{
    return a.second<b.second;
}
int main()
{
    int a,b;
    scanf("%d",&a);
    for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
    for(int i=1;i<=a;i++) x[i].color = 1;
    scanf("%d",&b);
    for(int i=a+1;i<=a+b;i++) scanf("%d%d",&x[i].first,&x[i].second);
    for(int i=a+1;i<=a+b;i++) x[i].color=2;

    int c1,c2;
    scanf("%d%d",&c1,&c2);
    std::sort(x+1,x+a+b+1,cmp1);
    x[1].x0 = 1;
    for(int i=2;i<=a+b;i++)
    {
        if(x[i].first!=x[i-1].first) x[i].x0 = x[i-1].x0+1;
        else x[i].x0 = x[i-1].x0;
    }

    std::sort(x+1,x+a+b+1,cmp2);
    x[1].y0 = 1;
    for(int i=2;i<=a+b;i++)
    {
        if(x[i].second!=x[i-1].second) x[i].y0 = x[i-1].y0+1;
        else x[i].y0 = x[i-1].y0;
    }

    int ans = 0;
    for(int i=1;i<=a+b;i++)
    {
        T.clear();
        for(int j=i;j<=a+b;j++)
        {
            if(x[j].y0!=x[j-1].y0)
            {
                int s = T.getMax();
                ans = ans>s?ans:s;
            }
            if(x[j].color==1) T.add(x[j].x0,c1);
            else T.add(x[j].x0,-c2);
        }
        int s = T.getMax();
        ans = ans>s?ans:s;
    }
    printf("%d",ans);
}
