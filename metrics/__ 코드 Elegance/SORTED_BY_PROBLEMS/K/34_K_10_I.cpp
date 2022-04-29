#include <bits/stdc++.h>

using namespace std;

const int N_ = 105;
using lint = long long;

int N, K;

struct point {
    lint x, y, z;
    point operator- (const point &p) const {
        return point{x - p.x, y - p.y, z - p.z};
    }
};

point cross(point a, point b) {
    return point{a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x, a.x * b.y - a.y * b.x};
}

lint dot (point a, point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#define pow(x, y) ((x) * (x))
#define double long double


point points[N_];

double sol() {

    double ans = 1e18;

    if(K >= 1) {
        double r, g, b;
        r = g = b = 0;
        for(int i = 0; i < N; i++) {
            point &p = points[i];

            r += p.x;
            g += p.y;
            b += p.z;
        }
        r /= N;
        g /= N;
        b /= N;
        double tot = 0;
        for(int i = 0; i < N; i++) {
            point &p = points[i];
            tot += pow(p.x - r, 2) + pow(p.y - g, 2) + pow(p.z - b, 2);
        }
        ans = tot;
    }
    //printf(" %.20lf\n", ans);

    if(K >= 2) {
        for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) for(int k = 0; k < j; k++) {
                    point v = cross(points[i] - points[j], points[i] - points[k]);
                    lint d = dot(points[i], v);
                    assert(d == dot(points[j], v));
                    assert(d == dot(points[k], v));
                    vector<int> pos[3];
                    for(int t = 0; t < N; t++) {
                        lint w = dot(points[t], v) - d;
                        if(w > 0) pos[0].push_back(t);
                        else if(w < 0) pos[1].push_back(t);
                        else pos[2].push_back(t);
                    }

                    for(int mask = 0; mask < (1<<int(pos[2].size())); mask++) {
                        for(int q = 0; q < pos[2].size(); q++) ((mask >> q) % 2 ? pos[0] : pos[1]).push_back(pos[2][q]);
                        double tot = 0;
                        for(auto vec : {pos[0], pos[1]}) {
                            if(vec.empty()) continue;

                            double r, g, b;
                            r = g = b = 0;
                            for(int &i : vec) {
                                auto &p = points[i];
                                r += p.x;
                                g += p.y;
                                b += p.z;
                            }
                            r /= vec.size();
                            g /= vec.size();
                            b /= vec.size();
                            for(int &i : vec) {
                                auto &p = points[i];
                                tot += pow(p.x - r, 2) + pow(p.y - g, 2) + pow(p.z - b, 2);
                            }
                        }
                        ans = min(ans, tot);
                        for(int q = 0; q < pos[2].size(); q++) ((mask >> q) % 2 ? pos[0] : pos[1]).pop_back();
                    }
                }
    }
    return ans;
}

double brute() {
    double ans2 = 1e18;
    for(int mask = 1; mask < (1<<N); mask += 2) {
        vector<point> A, B;
        for(int i = 0; i < N; i++) ((mask >> i) % 2 ? A : B).push_back(points[i]);

        double tot = 0;
        for(auto vec : {A, B}) {
            if(vec.empty()) continue;

            double r, g, b;
            r = g = b = 0;
            for(point &p : vec) {
                r += p.x;
                g += p.y;
                b += p.z;
            }
            r /= vec.size();
            g /= vec.size();
            b /= vec.size();
            for(point &p : vec) {
                tot += pow(p.x - r, 2) + pow(p.y - g, 2) + pow(p.z - b, 2);
            }
        }
        ans2 = min(ans2, tot);
    }
    return ans2;
}

mt19937 rng;
uniform_int_distribution<int> gen(995, 1000);

int main() {
    /*N = 10; K = 2;
    int rep = 0;
    while(true) {
        for(int i = 0; i < N; i++) {
            point &p = points[i];
            p.x = i;
            p.y = i*i;//gen(rng);
            p.z = i+i*i;gen(rng);
        }
        double ans1 = sol();
        double ans2 = brute();
        if(fabs(ans1 - ans2) > 1e-6) {
            for(int i = 0; i < N; i++) {
                printf("%lld %lld %lld\n", points[i].x, points[i].y, points[i].z);
            }
            printf("%lf %lf\n", ans1, ans2);
            break;
        }
        if(++rep % 100 == 0) {
            printf("repeated %d times\n", rep);
        }
    }
    return 0;*/

    scanf("%d%d",&N, &K);
    for(int i = 0; i < N; i++) {
        point &p = points[i];
        scanf("%lld%lld%lld", &p.x, &p.y, &p.z);
    }
    printf("%.6Lf\n", sol());

    return 0;
}