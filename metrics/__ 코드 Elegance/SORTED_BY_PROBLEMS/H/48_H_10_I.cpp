#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Crd{ int x, y; };

Crd crd1[1005], crd2[1005];
int cum1[1005][1005], cum2[1005][1005];
vector<int> xs, ys;

pii count(int x1, int x2, int y1, int y2){
//    printf("%d %d %d %d\n", x1, x2, y1, y2);
    return make_pair(cum1[x2][y2] - cum1[x1 - 1][y2] - cum1[x2][y1 - 1] + cum1[x1 - 1][y1 - 1],
                     cum2[x2][y2] - cum2[x1 - 1][y2] - cum2[x2][y1 - 1] + cum2[x1 - 1][y1 - 1]);
}

int main()
{
    int N1, N2; scanf("%d", &N1);
    for(int i = 0; i < N1; i++){
        scanf("%d %d", &crd1[i].x, &crd1[i].y);
        xs.push_back(crd1[i].x);
        ys.push_back(crd1[i].y);
    }
    scanf("%d", &N2);
    for(int i = 0; i < N2; i++){
        scanf("%d %d", &crd2[i].x, &crd2[i].y);
        xs.push_back(crd2[i].x);
        ys.push_back(crd2[i].y);
    }

    ll C1, C2; scanf("%lld %lld", &C1, &C2);
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int X = 0, Y = 0;
    map<int, int> xidx, yidx;
    xidx[xs[0]] = ++X;
    for(int i = 1; i < xs.size(); i++)
        if(xs[i] != xs[i - 1]) xidx[xs[i]] = ++X;
    yidx[ys[0]] = ++Y;
    for(int i = 1; i < ys.size(); i++)
        if(ys[i] != ys[i - 1]) yidx[ys[i]] = ++Y;

    for(int i = 0; i < N1; i++)
        crd1[i].x = xidx[crd1[i].x], crd1[i].y = yidx[crd1[i].y];
    for(int i = 0; i < N2; i++)
        crd2[i].x = xidx[crd2[i].x], crd2[i].y = yidx[crd2[i].y];

    for(int i = 0; i < N1; i++)
        cum1[crd1[i].x][crd1[i].y]++;
    for(int i = 0; i < N2; i++)
        cum2[crd2[i].x][crd2[i].y]++;

    for(int i = 1; i <= X; i++)
        for(int j = 1; j <= Y; j++){
            cum1[i][j] += cum1[i - 1][j] + cum1[i][j - 1] - cum1[i - 1][j - 1];
            cum2[i][j] += cum2[i - 1][j] + cum2[i][j - 1] - cum2[i - 1][j - 1];
        }

    ll ans = 0;
    for(int i = 0; i < N1; i++)
        for(int j = i + 1; j < N1; j++){
            pii ret = count(min(crd1[i].x, crd1[j].x), max(crd1[i].x, crd1[j].x), min(crd1[i].y, crd1[j].y), max(crd1[i].y, crd1[j].y));
//            printf("%lld: %d * %lld + %d * %lld\n", ret.first * C1 + ret.second * C2, ret.first, C1, ret.second, C2);
            ans = max(ans, ret.first * C1 - ret.second * C2);
        }
    for(int i = 0; i < N2; i++)
        for(int j = i + 1; j < N2; j++){
            pii ret = count(min(crd2[i].x, crd2[j].x), max(crd2[i].x, crd2[j].x), min(crd2[i].y, crd2[j].y), max(crd2[i].y, crd2[j].y));
//            printf("%lld: %d * %lld + %d * %lld\n", ret.first * C1 + ret.second * C2, ret.first, C1, ret.second, C2);
            ans = max(ans, ret.first * C1 - ret.second * C2);
        }
    for(int i = 0; i < N1; i++)
        for(int j = 0; j < N2; j++){
            pii ret = count(min(crd1[i].x, crd2[j].x), max(crd1[i].x, crd2[j].x), min(crd1[i].y, crd2[j].y), max(crd1[i].y, crd2[j].y));
//            printf("%lld: %d * %lld + %d * %lld\n", ret.first * C1 + ret.second * C2, ret.first, C1, ret.second, C2);
            ans = max(ans, ret.first * C1 - ret.second * C2);
        }

    printf("%lld\n", ans);

    return 0;
}

