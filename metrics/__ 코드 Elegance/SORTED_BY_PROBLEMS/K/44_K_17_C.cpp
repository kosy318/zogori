#include <bits/stdc++.h>

using namespace std;

int n, k;
struct point {
    int r, g, b;
} p[105];

struct plane {
    int a, b, c, d;
    plane(int a, int b, int c, int d): a(a), b(b), c(c), d(d) { }
    bool same_side(point x, point y) {
        return (a * x.r + b * x.g + c * x.b + d > 0) == (a * y.r + b * y.g + c * y.b + d > 0);
    }
};

plane get_plane(point x, point y, point z) {
    int a = (z.g - x.g) * (y.b - x.b) - (z.b - x.b) * (y.g - x.g);
    int b = (z.b - x.b) * (y.r - x.r) - (z.r - x.r) * (y.b - x.b);
    int c = (z.r - x.r) * (y.g - x.g) - (z.g - x.g) * (y.r - x.r);
    int d = -(x.r * a + x.g * b + x.b * c);
    return plane(a, b, c, d);
}

double ans = 1e9;
bool group[105];

double calc_ans() {
    int c1 = 0;
    long long sum_r1 = 0;
    long long sum_g1 = 0;
    long long sum_b1 = 0;
    int c2 = 0;
    long long sum_r2 = 0;
    long long sum_g2 = 0;
    long long sum_b2 = 0;
    for (int i = 0; i < n; i++) {
        if (group[i]) {
            sum_r1 += p[i].r;
            sum_g1 += p[i].g;
            sum_b1 += p[i].b;
            ++c1;
        } else {
            sum_r2 += p[i].r;
            sum_g2 += p[i].g;
            sum_b2 += p[i].b;
            ++c2;
        }
    }
    double r1;
    double g1;
    double b1;
    double r2;
    double g2;
    double b2;
    if (c1 == 0) {
        r1 = g1 = b1 = 0;
    } else {
        r1 = sum_r1 * 1.0 / c1;
        g1 = sum_g1 * 1.0 / c1;
        b1 = sum_b1 * 1.0 / c1;
    }
    if (c2 == 0) {
        r2 = g2 = b2 = 0;
    } else {
        r2 = sum_r2 * 1.0 / c2;
        g2 = sum_g2 * 1.0 / c2;
        b2 = sum_b2 * 1.0 / c2;
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (group[i]) {
            double dr = p[i].r - r1;
            double dg = p[i].g - g1;
            double db = p[i].b - b1;
            res += dr * dr + dg * dg + db * db;
        } else {
            double dr = p[i].r - r2;
            double dg = p[i].g - g2;
            double db = p[i].b - b2;
            res += dr * dr + dg * dg + db * db;
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i].r, &p[i].g, &p[i].b);
    }
    if (k == 1) {
        ans = calc_ans();
    } else if (n < 3) {
        ans = 0;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    int l;
                    if (i > 0) {
                        l = 0;
                    } else if (j > 1) {
                        l = 1;
                    } else if (k > 2) {
                        l = 2;
                    } else {
                        l = 3;
                    }
                    plane pl = get_plane(p[i], p[j], p[k]);
                    for (int m = 0; m < n; m++) {
                        if (m == i || m == j || m == k) {
                            continue;
                        }
                        group[m] = pl.same_side(p[l], p[m]);
                    }
                    group[i] = false;
                    group[j] = false;
                    group[k] = false;
                    ans = min(ans, calc_ans());
                    group[i] = false;
                    group[j] = false;
                    group[k] = true;
                    ans = min(ans, calc_ans());
                    group[i] = false;
                    group[j] = true;
                    group[k] = false;
                    ans = min(ans, calc_ans());
                    group[i] = false;
                    group[j] = true;
                    group[k] = true;
                    ans = min(ans, calc_ans());
                    group[i] = true;
                    group[j] = false;
                    group[k] = false;
                    ans = min(ans, calc_ans());
                    group[i] = true;
                    group[j] = false;
                    group[k] = true;
                    ans = min(ans, calc_ans());
                    group[i] = true;
                    group[j] = true;
                    group[k] = false;
                    ans = min(ans, calc_ans());
                    group[i] = true;
                    group[j] = true;
                    group[k] = true;
                    ans = min(ans, calc_ans());
                }
            }
        }
    }
    printf("%.6lf\n", ans);
}
