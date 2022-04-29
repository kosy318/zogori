#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
#define double long double

#define eps 1e-9

struct Point {
    lint x, y, z;
    Point(lint x, lint y, lint z) : x(x), y(y), z(z) {}
    Point(Point a, Point b) {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
    }

    Point outer(Point p) {
        Point ret(y * p.z - z * p.y,
                  x * p.z - z * p.x,
                  x * p.y - y * p.x);
        return ret;
    }

    lint inner(Point p) {
        lint ret = x * p.x;
        ret += y * p.y;
        ret += z * p.z;
        return ret;
    }
};

lint ccw(Point a, Point b, Point c) {
    Point o = a.outer(b);
    return o.inner(c);
}

struct Plane {
    double a, b, c;
    Plane(double a, double b, double c) : a(a), b(b), c(c) {}
    Plane(Point A, Point B, Point C) {

    }

};

int N, K;
vector<Point> v;
bool chk[100];


int main()
{
    double res = 0;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v.push_back({x, y, z});
    }
    if (N == 1) return !printf("0.000000");
    if (1)
    {
        double avgR[2], avgG[2], avgB[2];
        int sz[2];
        double cur_res = 0;

        avgR[0] = avgR[1] = 0;
        avgG[0] = avgG[1] = 0;
        avgB[0] = avgB[1] = 0;
        sz[0] = sz[1] = 0;

        for (int d = 0; d < N; d ++) {
            avgR[chk[d]] += v[d].x;
            avgG[chk[d]] += v[d].y;
            avgB[chk[d]] += v[d].z;
            sz[chk[d]] ++;
        }

        for (int z = 0; z < 2; z ++) {
            avgR[z] /= sz[z];
            avgG[z] /= sz[z];
            avgB[z] /= sz[z];
        }

        for (int d = 0; d < N; d ++) {
            cur_res += (v[d].x - avgR[chk[d]]) * (v[d].x - avgR[chk[d]]);
            cur_res += (v[d].y - avgG[chk[d]]) * (v[d].y - avgG[chk[d]]);
            cur_res += (v[d].z - avgB[chk[d]]) * (v[d].z - avgB[chk[d]]);
        }
        res = cur_res;
    }
    if (K == 1)
        return !printf("%.6Lf", res+eps);

    if (N <= 10) {
        for (int b = 0; b < (1 << N); b ++ ){
            for (int mask = 1, k = 0; k < N; k ++, mask <<= 1) {
                if (b & mask) {
                    chk[k] = true;
                } else
                    chk[k] = false;
            }

            double avgR[2], avgG[2], avgB[2];
            int sz[2];
            double cur_res = 0;

            avgR[0] = avgR[1] = 0;
            avgG[0] = avgG[1] = 0;
            avgB[0] = avgB[1] = 0;
            sz[0] = sz[1] = 0;

            for (int d = 0; d < N; d ++) {
                avgR[chk[d]] += v[d].x;
                avgG[chk[d]] += v[d].y;
                avgB[chk[d]] += v[d].z;
                sz[chk[d]] ++;
            }

            for (int z = 0; z < 2; z ++) {
                avgR[z] /= sz[z];
                avgG[z] /= sz[z];
                avgB[z] /= sz[z];
            }

            for (int d = 0; d < N; d ++) {
                cur_res += (v[d].x - avgR[chk[d]]) * (v[d].x - avgR[chk[d]]);
                cur_res += (v[d].y - avgG[chk[d]]) * (v[d].y - avgG[chk[d]]);
                cur_res += (v[d].z - avgB[chk[d]]) * (v[d].z - avgB[chk[d]]);
            }
            res = min(res, cur_res);
        }
        printf("%.6Lf\n", res+eps);
        return 0;
    }


    int re[100];
    for (int i = 0; i < N; i ++) {
        for (int j = i+1; j < N; j ++) {
            for (int k = j+1; k < N; k ++) {
                Point v1 (v[i], v[j]);
                Point v2 (v[i], v[k]);

                for (int d = 0; d < N; d ++) {
                    if (d == i || d == j || d == k)
                        continue;
                    if (ccw(v1, v2, v[d]) > 0)
                        chk[d] = true;
                    else
                        chk[d] = false;
                }
                chk[i]=chk[j]=chk[k]=false;

                double avgR[2], avgG[2], avgB[2];
                int sz[2];
                double cur_res = 0;

                avgR[0] = avgR[1] = 0;
                avgG[0] = avgG[1] = 0;
                avgB[0] = avgB[1] = 0;
                sz[0] = sz[1] = 0;

                for (int d = 0; d < N; d ++) {
                    avgR[chk[d]] += v[d].x;
                    avgG[chk[d]] += v[d].y;
                    avgB[chk[d]] += v[d].z;
                    sz[chk[d]] ++;
                }

                for (int z = 0; z < 2; z ++) {
                    avgR[z] /= sz[z];
                    avgG[z] /= sz[z];
                    avgB[z] /= sz[z];
                }

                for (int d = 0; d < N; d ++) {
                    cur_res += (v[d].x - avgR[chk[d]]) * (v[d].x - avgR[chk[d]]);
                    cur_res += (v[d].y - avgG[chk[d]]) * (v[d].y - avgG[chk[d]]);
                    cur_res += (v[d].z - avgB[chk[d]]) * (v[d].z - avgB[chk[d]]);
                }

                /*
                if (res > cur_res)
                {
                    for(int d=0; d<100; d++)
                        re[d]=chk[d];
                }*/
                res = min(res, cur_res);



                chk[i]=chk[j]=chk[k]=true;

                avgR[0] = avgR[1] = 0;
                avgG[0] = avgG[1] = 0;
                avgB[0] = avgB[1] = 0;
                sz[0] = sz[1] = 0;
                cur_res = 0;

                for (int d = 0; d < N; d ++) {
                    avgR[chk[d]] += v[d].x;
                    avgG[chk[d]] += v[d].y;
                    avgB[chk[d]] += v[d].z;
                    sz[chk[d]] ++;
                }

                for (int z = 0; z < 2; z ++) {
                    avgR[z] /= sz[z];
                    avgG[z] /= sz[z];
                    avgB[z] /= sz[z];
                }

                for (int d = 0; d < N; d ++) {
                    cur_res += (v[d].x - avgR[chk[d]]) * (v[d].x - avgR[chk[d]]);
                    cur_res += (v[d].y - avgG[chk[d]]) * (v[d].y - avgG[chk[d]]);
                    cur_res += (v[d].z - avgB[chk[d]]) * (v[d].z - avgB[chk[d]]);
                }

                if (res > cur_res)
                {
                    for(int d=0; d<100; d++)
                        re[d]=chk[d];
                }
                res = min(res, cur_res);

            }
        }
    }

    for(int i=0; i<N; i++)
        printf("%d ", re[i]);
    printf("\n");

    printf("%.6Lf\n", res+eps);
    return 0;
}

/*
3 2
 93 50 26
 40 0 77
 99 10 29

 6 2
 0 0 0
 0 1 0
 0 0 1
 100 100 100
  100 100 101
   100 101 100


 6 2
 1 1 0
 1 2 0
 2 1 0
 11 11 0
  11 12 0
   12 11 0

    7 2
 1 0 0
 -1 0 0
 0 1 0
 0 -1 0
 0 0 1
 0 0 -1
 0 0 0

 */