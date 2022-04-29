#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int y;
    int cost;
    const bool operator< (const node &a) const {
        return x < a.x;
    }
};

int ys[2020];

node o[1010], u[1010];

node h[2020];

int main() {
    int yk = 0;
    int k = 0;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &o[i].x, &o[i].y);
        ys[yk++] = o[i].y;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u[i].x, &u[i].y);
        ys[yk++] = u[i].y;
    }

    sort(ys, ys + yk);
    yk = unique(ys, ys + yk) - ys;

    int s, b;
    scanf("%d %d", &s, &b);

    for(int i = 0; i < n; i++) {
        h[k] = o[i];
        h[k++].cost = s;
    }
    for(int i = 0; i < m; i++) {
        h[k] = u[i];
        h[k++].cost = -b;
    }

    sort(h, h + k);

    int ans = -0x7fffffff;
    for(int i = 0; i < yk; i++) {
        for(int j = i; j < yk; j++) {
            int sum = 0, mini = 0;
            for(int l = 0; l < k; l++) {
                int t = 0;
                if(ys[i] <= h[l].y && h[l].y <= ys[j]) t = h[l].cost;

                sum += t;
                if(l + 1 < k && h[l + 1].x == h[l].x) continue;
                if(sum - mini > ans) ans = sum - mini;
                if(mini > sum) {
                    mini = sum;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}