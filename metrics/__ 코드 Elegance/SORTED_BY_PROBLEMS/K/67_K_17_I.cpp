#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n, K;

struct point {
    ld x, y, z;
    point() : x(0), y(0), z(0) {};
    point(ld x, ld y, ld z) : x(x), y(y), z(z) {};
    point operator+(const point& rhs) const {
        return point(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    point operator+=(const point& rhs) {
        this-> x += rhs.x;
        this-> y += rhs.y;
        this-> z += rhs.z;
    }
    point operator-(const point& rhs) const {
        return point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    point operator-=(const point& rhs) {
        this-> x -= rhs.x;
        this-> y -= rhs.y;
        this-> z -= rhs.z;
    }

    point operator*(const ld& rhs) const {
        return point(x * rhs, y * rhs, z * rhs);
    }
    point operator*=(const ld& rhs) {
        this->x *= rhs;
        this->y *= rhs;
        this->z *= rhs;
    }
    point operator/(const ld& rhs) const {
        return (*this) * (1 / rhs);
    }
    point operator/=(const ld& rhs) {
        this->x /= rhs;
        this->y /= rhs;
        this->z /= rhs;
    }
    inline ld sizesq() const {
        return x * x + y * y + z * z;
    }
};

point a[100];

void solve1() {
    point average = point();
    for (int i = 0; i< n; i++) {
        average += a[i];
    }
    average /= n;

    ld sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - average).sizesq();
    }

    cout << sum;
}

void solve2() {
    ld xsum = 0;
    for (int i = 0; i < n; i++) {
        xsum += a[i].sizesq();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << fixed << setprecision(15);

    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    if (K == 1) {
        solve1();
    } else {
        if(n<=2) {printf("0");return 0;}
        ld mm = INFINITY;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < j; ++k) {


                    auto q = a[i] - a[j];
                    auto r = a[k] - a[j];
                    point b = {q.y * r.z - q.z * r.y, q.z * r.x - q.x * r.z, q.x * r.y - q.y * r.x};

                    ld d = b.x * a[j].x + b.y * a[j].y + b.z * a[j].z;

                    for (int t = 0; t < 8; ++t) {
                        vector<point> v1, v2;

                        for (int l = 0; l < n; ++l) {
                            if (i == l) {
                                if (t %2==1) v1.push_back(a[l]);
                                else v2.push_back(a[l]);
                                continue;
                            }
                            if (j == l) {
                                if (t <4) v1.push_back(a[l]);
                                else v2.push_back(a[l]);
                                continue;
                            }
                            if (k == l) {
                                if (t/2%2) v1.push_back(a[l]);
                                else v2.push_back(a[l]);
                                continue;
                            }
                            if (b.x * a[l].x + b.y * a[l].y + b.z * a[l].z - d < 0) {
                                v1.push_back(a[l]);
                            } else {
                                v2.push_back(a[l]);
                            }
                        }

                        point average1 = point();
                        for (point p1 : v1) {
                            average1 += p1;
                        }
                        average1 /= v1.size();

                        point average2 = point();
                        for (point p2 : v2) {
                            average2 += p2;
                        }
                        average2 /= v2.size();

                        ld sum = 0;
                        for (point p1 : v1) {
                            sum += (p1 - average1).sizesq();
                        }
                        for (point p2 : v2) {
                            sum += (p2 - average2).sizesq();
                        }

                        mm = min(sum, mm);
                    }
                }
            }
        }

        cout << mm << "\n";

    }

    return 0;
}