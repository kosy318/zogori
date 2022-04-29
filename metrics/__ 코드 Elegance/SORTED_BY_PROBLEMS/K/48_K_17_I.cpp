#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int x, y, z;
} inp[105];

typedef long long ll;
typedef long double ld;
vector<int> vx, vy, vz;
int N, K;
ll r2[102][102][102];
ll g2[102][102][102];
ll b2[102][102][102];
ll r[102][102][102];
ll g[102][102][102];
ll b[102][102][102];
ll cnt[102][102][102];

ll totr2, totr;
ll totg2, totg;
ll totb2, totb;

ll count(int x1, int y1, int z1, int x2, int y2, int z2, ll psum[102][102][102]) {
    return psum[x2][y2][z2] - psum[x1 - 1][y2][z2] - psum[x2][y1 - 1][z2] - psum[x2][y2][z1 - 1]
                          + psum[x1 - 1][y1 - 1][z2] + psum[x1 - 1][y2][z1 - 1] + psum[x2][y1 - 1][z1 - 1]
                          - psum[x1 - 1][y1 - 1][z1 - 1];
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        inp[i] = {x, y, z};
        totr2 += x * x;
        totg2 += y * y;
        totb2 += z * z;
        totr += x;
        totg += y;
        totb += z;
        vx.push_back(x);
        vy.push_back(y);
        vz.push_back(z);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(vz.begin(), vz.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    vz.erase(unique(vz.begin(), vz.end()), vz.end());

    for (int i = 1; i <= N; i++) {
        int x = inp[i].x;
        int y = inp[i].y;
        int z = inp[i].z;
        inp[i].x = lower_bound(vx.begin(), vx.end(), inp[i].x) - vx.begin() + 1;
        inp[i].y = lower_bound(vy.begin(), vy.end(), inp[i].y) - vy.begin() + 1;
        inp[i].z = lower_bound(vz.begin(), vz.end(), inp[i].z) - vz.begin() + 1;

        r2[inp[i].x][inp[i].y][inp[i].z] += x * x;
        g2[inp[i].x][inp[i].y][inp[i].z] += y * y;
        b2[inp[i].x][inp[i].y][inp[i].z] += z * z;
        r[inp[i].x][inp[i].y][inp[i].z] += x;
        g[inp[i].x][inp[i].y][inp[i].z] += y;
        b[inp[i].x][inp[i].y][inp[i].z] += z;
        cnt[inp[i].x][inp[i].y][inp[i].z] += 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                r2[i][j][k] += r2[i - 1][j][k] + r2[i][j - 1][k] + r2[i][j][k - 1]
                               - r2[i - 1][j - 1][k] - r2[i - 1][j][k - 1] - r2[i][j - 1][k - 1]
                               + r2[i - 1][j - 1][k - 1];
                g2[i][j][k] += g2[i - 1][j][k] + g2[i][j - 1][k] + g2[i][j][k - 1]
                               - g2[i - 1][j - 1][k] - g2[i - 1][j][k - 1] - g2[i][j - 1][k - 1]
                               + g2[i - 1][j - 1][k - 1];
                b2[i][j][k] += b2[i - 1][j][k] + b2[i][j - 1][k] + b2[i][j][k - 1]
                               - b2[i - 1][j - 1][k] - b2[i - 1][j][k - 1] - b2[i][j - 1][k - 1]
                               + b2[i - 1][j - 1][k - 1];
                r[i][j][k] += r[i - 1][j][k] + r[i][j - 1][k] + r[i][j][k - 1]
                               - r[i - 1][j - 1][k] - r[i - 1][j][k - 1] - r[i][j - 1][k - 1]
                               + r[i - 1][j - 1][k - 1];
                g[i][j][k] += g[i - 1][j][k] + g[i][j - 1][k] + g[i][j][k - 1]
                              - g[i - 1][j - 1][k] - g[i - 1][j][k - 1] - g[i][j - 1][k - 1]
                              + g[i - 1][j - 1][k - 1];
                b[i][j][k] += b[i - 1][j][k] + b[i][j - 1][k] + b[i][j][k - 1]
                              - b[i - 1][j - 1][k] - b[i - 1][j][k - 1] - b[i][j - 1][k - 1]
                              + b[i - 1][j - 1][k - 1];
                cnt[i][j][k] += cnt[i - 1][j][k] + cnt[i][j - 1][k] + cnt[i][j][k - 1]
                              - cnt[i - 1][j - 1][k] - cnt[i - 1][j][k - 1] - cnt[i][j - 1][k - 1]
                              + cnt[i - 1][j - 1][k - 1];
            }
        }
    }
    ld ans = totr2 - 1.0L * totr * totr / N
            + totg2 - 1.0L * totg * totg / N
            +totb2 - 1.0L * totb * totb / N;

//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N; j++) {
//            for (int k = 1; k <= N; k++) {
//                printf("[%d %d %d] : %lld\n", i, j, k, count(1, 1, 1, i, j, k, cnt));
//            }
//        }
//    }
    if (N == 1) {
        return !printf("0.000000");
    }
    if (K == 2) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    int sx[] = {1, i, 1, 1, i, i, 1, i};
                    int sy[] = {1, 1, j, 1, j, 1, j, j};
                    int sz[] = {1, 1, 1, k, 1, k, k, k};
                    int ex[] = {i, N, i, i, N, N, i, N};
                    int ey[] = {j, j, N, j, N, j, N, N};
                    int ez[] = {k, k, k, N, k, N, N, N};
                    for (int dd = 0; dd < 8; dd++) {
                        ld ret = 0;
                        ll incount = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], cnt);
                        if (incount == N || incount == 0) continue;
                        ll sumr = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], r);
                        ll sumr2 = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], r2);
                        ld ansr = sumr2 - (1.0L * sumr * sumr / incount);
                        ld elser = (totr2 - sumr2)
                                   - (1.0L * (totr - sumr) * (totr - sumr) / (N - incount));
                        ret += ansr + elser;

                        ll sumg = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], g);
                        ll sumg2 = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], g2);
                        ld ansg = sumg2 - (1.0L * sumg * sumg / incount);
                        ld elseg = (totg2 - sumg2)
                                   - (1.0L * (totg - sumg) * (totg - sumg) / (N - incount));
                        ret += ansg + elseg;

                        ll sumb = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], b);
                        ll sumb2 = count(sx[dd], sy[dd], sz[dd], ex[dd], ey[dd], ez[dd], b2);
                        ld ansb = sumb2 - (1.0L * sumb * sumb / incount);
                        ld elseb = (totb2 - sumb2)
                                   - (1.0L * (totb - sumb) * (totb - sumb) / (N - incount));
                        ret += ansb + elseb;

                        ans = min(ans, ret);
                    }
                }
            }
        }
    }
    printf("%.6Lf\n", ans);
    return 0;

}