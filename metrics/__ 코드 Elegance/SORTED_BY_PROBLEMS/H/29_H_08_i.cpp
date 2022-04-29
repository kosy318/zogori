#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PP = pair<P, int>; // n , a(sum), b(square sum)

const int MAX_N=2001;
const int MAX_INF=2e9;

int N1, N2;
PP point[MAX_N];
P sum[MAX_N][MAX_N];
vector<int> xpos, ypos;
map<P,int> m;
int c, d;

ll segSum(int a, int b) {
    int ax = point[a].first.first;
    int ay = point[a].first.second;
    int bx = point[b].first.first;
    int by = point[b].first.second;
    int minx = min(ax, bx);
    int miny = min(ay, by);
    int maxx = max(ax, bx);
    int maxy = max(ay, by);
    int si = lower_bound(xpos.begin(), xpos.end(), minx) - xpos.begin() - 1;
    int sj = lower_bound(ypos.begin(), ypos.end(), miny) - ypos.begin() - 1;
    int ei = lower_bound(xpos.begin(), xpos.end(), maxx) - xpos.begin();
    int ej = lower_bound(ypos.begin(), ypos.end(), maxy) - ypos.begin();
    P ret;
    ret.first = (sum[ei][ej].first - sum[ei][sj].first - sum[si][ej].first + sum[si][sj].first);
    ret.second = (sum[ei][ej].second - sum[ei][sj].second - sum[si][ej].second + sum[si][sj].second);
    return ret.first*c * ret.second.d;
}

int main() {
    scanf("%d", &N1);
    xpos.push_back(-MAX_INF);
    ypos.push_back(-MAX_INF);
    for (int i=0; i<N1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        point[i] = PP(P(x,y), 0);
        m[P(x,y)] = 1;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    scanf("%d", &N2);
    for (int i=0; i<N2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        m[P(x,y)] = 2;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    scanf("%d%d", &c, &d);
    sort(xpos.begin(), xpos.end());
    xpos.erase(unique(xpos.begin(), xpos.end()));
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()));
    for (int i=1; i<xpos.size(); i++) {
        for (int j=1; j<ypos.size(); j++) {
            int x = xpos[i];
            int y = ypos[i];
            int f1 = 0;
            int f2 = 0;
            if (m[P(x,y)] == 1) f1 = 1;
            if (m[P(x,y)] == 2) f2 = 1;
            sum[i][j].first = sum[i][j-1].first + sum[i-1][j].first - sum[i-1][j-1].first + f1;
            sum[i][j].second = sum[i][j-1].second + sum[i-1][j].second - sum[i-1][j-1].second + f2;
        }
    }

    ll ret = -(1LL<<62);
    for (int i=0; i<N1; i++) {
        for (int j=i+1; j<N1; j++) {
            ret = max(ret, segSum(i,j));
        }
    }
    printf("%lld\n", ret);

    return 0;
}