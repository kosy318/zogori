#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct point {
    ld x, y, z;
    ld dist(point p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
    }
};

point P[110];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    point sum = {0.0, 0.0, 0.0};

    for (int i = 0; i < n; ++i) {
        cin >> P[i].x >> P[i].y >> P[i].z;
        sum.x += P[i].x;
        sum.y += P[i].y;
        sum.z += P[i].z;
    }

    sum.x /= n;
    sum.y /= n;
    sum.z /= n;

    cout << fixed << setprecision(15);

    if (k == 1) {
        ld ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ((P[i].x - sum.x) * (P[i].x - sum.x)
                    + (P[i].y - sum.y) * (P[i].y - sum.y)
                    + (P[i].z - sum.z) * (P[i].z - sum.z));
        }
        cout << ans;
    }

    ld ans = INFINITY;

    for (int K = 1; K <= n - 1; ++K) {
        // K-means clustering
        point means[2];
        means[0] = *max_element(P, P + n, [&](point a, point b) {
            return a.dist(P[0]) < b.dist(P[0]);
        });
        means[1] = *max_element(P, P + n, [&](point a, point b) {
            return a.dist(means[0]) < b.dist(means[0]);
        });

        for (int iter = 0; iter < 100; ++iter) {
            for (auto & mean : means) {
                partial_sort(P, P + K, P + n, [&](point a, point b) {
                    return mean.dist(a) < mean.dist(b);
                });

                point sum = {0.0, 0.0, 0.0};
                for (int j = 0; j < K; ++j) {
                    sum.x += P[j].x;
                    sum.y += P[j].y;
                    sum.z += P[j].z;
                }

                sum.x /= K;
                sum.y /= K;
                sum.z /= K;

                mean = sum;
            }
        }

        sort(P, P + n, [&](point a, point b) {
            return a.dist(means[0]) - a.dist(means[1]) < b.dist(means[0]) - b.dist(means[1]);
        });

        int i;
        point mean0 = {0.0, 0.0, 0.0};
        for (i = 0; P[i].dist(means[1]) > P[i].dist(means[0]); ++i) {
            mean0.x += P[i].x;
            mean0.y += P[i].y;
            mean0.z += P[i].z;
        }

        if (i == 0) continue;

        mean0.x /= i;
        mean0.y /= i;
        mean0.z /= i;

        int n2 = n - i;
        point mean1 = {0.0, 0.0, 0.0};
        for (; i < n; ++i) {
            mean1.x += P[i].x;
            mean1.y += P[i].y;
            mean1.z += P[i].z;
        }
        mean1.x /= n2;
        mean1.y /= n2;
        mean1.z /= n2;

        ld m = 0;
        for (i = 0; P[i].dist(means[1]) > P[i].dist(means[0]); ++i) {
            m += P[i].dist(mean0);
        }
        for (; i < n; ++i) {
            m += P[i].dist(mean1);
        }

        ans = min(ans, m);
    }

    cout << ans << endl;

    return 0;
}