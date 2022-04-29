#include <stdio.h>
#include <algorithm>

struct str{
    int x0;
    int y0;
    int score;
}y[10010];

bool cmp(str a, str b)
{
    return a.x0<b.x0;
}

int x[110],next[10010];
long long int DP[10010];

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++) scanf("%d",&x[i]);
    for(int i=1;i<=b;i++) scanf("%d%d%d",&y[i].x0,&y[i].y0,&y[i].score);
    for(int i=1;i<=b;i++) y[i].score = x[y[i].score] * (y[i].y0-y[i].x0);
    std::sort(y+1,y+b+1,cmp);
    y[b+1].x0 = 1234567;

    for(int i=1;i<=b;i++)
    {
        int m = i+1, M = b+1;
        int ans = b+1;
        while(m<=M)
        {
            int h = (m+M)/2;
            if(y[i].y0>y[h].x0) m = h+1;
            else ans = h, M = h-1;
        }
        next[i] = ans;
    }

    for(int i=b;i>=1;i--)
    {
        long long int s1 = y[i].score + DP[next[i]];
        long long int s2 = DP[i+1];
        DP[i] = s1>s2?s1:s2;
    }

    long long int ans = 0;
    for(int i=1;i<=b;i++) ans = ans>DP[i]?ans:DP[i];
    printf("%lld",ans);
}
