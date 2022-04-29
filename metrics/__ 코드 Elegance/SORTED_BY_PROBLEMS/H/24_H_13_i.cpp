#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int,int> p;
int n1, n2, c1, c2, ans = INT_MIN, p1[1001][1001], p2[1001][1001];
int p1x[1001],p1y[1001],p2x[1001],p2y[1001];
pair<int, int> P1[1001], P2[1001];
int main()
{
    scanf("%d", &n1);
    for (int i=1; i<=n1; i++)
    {
        scanf("%d %d", &P1[i].first, &P1[i].second);
        p1x[i] = P1[i].first;
        p1y[i] = P1[i].second;
    }
    sort(p1x + 1, p1x + n1 + 1);
    sort(p1y + 1, p1y + n1 + 1);
    scanf("%d", &n2);
    for (int i=1; i<=n2; i++)
    {
        scanf("%d %d", &P2[i].first, &P2[i].second);
        p2x[i] = P2[i].first;
        p2y[i] = P2[i].second;
    }
    sort(p2x + 1, p2x + n2 + 1);
    sort(p2y + 1, p2y + n2 + 1);
    sort(P2 + 1, P2 + n2 + 1);
    scanf("%d %d", &c1, &c2);
    // p1 sum
    for (int i = 1; i <= n1; i++)
    {
        int idx = lower_bound(p1y + 1, p1y + n1 + 1, P1[i].second) - p1y;
        p1[i][idx]+=1;
    }
    for(int i=1; i<=n1; i++)
    {
        for(int j=2; j<=n1; j++)
        {
            p1[i][j]+=p1[i][j-1];
        }
    }
    for(int i=1; i<=n1; i++)
    {
        for(int j=2; j<=n1; j++)
        {
            p1[j][i]+=p1[j-1][i];
        }
    }


    //2 p2 sum
    for (int i = 1; i <= n2; i++)
    {
        p2[i][lower_bound(p2y + 1,p2y + n2 + 1,P2[i].second) - p2y]+=1;
    }
    for(int i=1; i<=n2; i++)
    {
        for(int j=2; j<=n2; j++)
        {
            p2[i][j]+=p2[i][j-1];
        }
    }
    for(int i=1; i<=n2; i++)
    {
        for(int j=2; j<=n2; j++)
        {
            p2[j][i]+=p2[j-1][i];
        }
    }
    for (int i=1; i <= n1; i++)
    {
        for(int j= i; j <= n1; j++)
        {
            int x1 = P1[i].first, y1 = P1[i].second, x2 = P1[j].first, y2 = P1[j].second;
            int lx, rx, ly, ry;
            lx = min(x1, x2), rx = max(x1, x2), ly = min(y1, y2), ry = max(y1, y2);
            int p1x1 = lower_bound(p1x + 1, p1x + n1 + 1, lx) - p1x, p1y1 = lower_bound(p1y + 1, p1y + n1 + 1, ly) - p1y;
            int p1x2 = lower_bound(p1x + 1, p1x + n1 + 1, rx) - p1x, p1y2 = lower_bound(p1y + 1, p1y + n1 + 1, ry) - p1y;
            int s = p1[p1x2][p1y2]-p1[p1x1-1][p1y2]-p1[p1x2][p1y1-1]+p1[p1x1-1][p1y1-1];


            int p2x1 = lower_bound(p2x + 1, p2x + n2 + 1, lx) - p2x, p2y1 = lower_bound(p2y + 1, p2y + n2 + 1, ly) - p2y;
            int p2x2 = lower_bound(p2x + 1, p2x + n2 + 1, rx) - p2x, p2y2 = lower_bound(p2y + 1, p2y + n2 + 1, ry) - p2y;
            if (p2x[p2x2] < rx) p2x2--;
            if (p2y[p2y2] < ry) p2y2--;
            int b= p2[p2x2][p2y2]-p2[p2x1-1][p2y2]-p2[p2x2][p2y1-1]+p2[p2x1-1][p2y1-1];

            ans = max(ans, c1 * s - c2 * b);
        }
    }
    printf("%d", ans);
}

