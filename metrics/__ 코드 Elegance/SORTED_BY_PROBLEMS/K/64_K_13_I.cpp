#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

using R = long double;
constexpr R pi = acos((R)-1);

void normalize(R& x, R& y, R& z) {
    R c = sqrt(x * x + y * y + z * z);
    x /= c;
    y /= c;
    z /= c;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    V<R> _x(n), _y(n), _z(n);
    R ax = 0, ay = 0, az = 0;
    for (int i = 0; i < n; ++i) {
        cin >> _x[i] >> _y[i] >> _z[i];
        ax += _x[i], ay += _y[i], az += _z[i];
    }
    ax /= n, ay /= n, az /= n;
    R res = 0;
    for (int i = 0; i < n; ++i) {
        res += (_x[i] - ax) * (_x[i] - ax);
        res += (_y[i] - ay) * (_y[i] - ay);
        res += (_z[i] - az) * (_z[i] - az);
    }
    if (k == 1) {
        return cout << fixed << setprecision(6) << res << endl, 0;
    }
    if (n <= 2) {
        return cout << fixed << setprecision(6) << 0.0 << endl, 0;
    }
    V<R> x(n), y(n), z(n);
    for (int p = 0; p < n; ++p) {
        for (int i = 0; i < n; ++i) {
            x[i] = _x[i] - _x[p];
            y[i] = _y[i] - _y[p];
            z[i] = _z[i] - _z[p];
        }
        for (int q = p + 1; q < n; ++q) {
            R x0 = x[q], y0 = y[q], z0 = z[q];
            R x1 = y[q] + z[q], y1 = -x[q], z1 = -x[q];
            R x2 = y0 * z1 - y1 * z0, y2 = z0 * x1 - z1 * x0, z2 = x0 * y1 - x1 * y0;
            normalize(x0, y0, z0);
            normalize(x1, y1, z1);
            normalize(x2, y2, z2);
            V<R> nx(n), ny(n);
            V<> idx;
            for (int i = 0; i < n; ++i) {
                nx[i] = x[i] * x1 + y[i] * y1 + z[i] * z1;
                ny[i] = x[i] * x2 + y[i] * y2 + z[i] * z2;
                if (i != p and i != q) {
                    idx.push_back(i);
                }
            }
            sort(begin(idx), end(idx), [&](int i, int j) { return atan2(ny[i], nx[i]) < atan2(ny[j], nx[j]); });
            V<R> th(n - 2);
            for (int t = 0; t < n - 2; ++t) {
                th[t] = atan2(ny[idx[t]], nx[idx[t]]);
                idx.push_back(idx[t]);
                th.push_back(th[t] + 2 * pi);
            }
            R base = 0, sx = 0, sy = 0, sz = 0;
            for (int i = 0; i < n; ++i) {
                base += x[i] * x[i] + y[i] * y[i] + z[i] * z[i];
                sx += x[i], sy += y[i], sz += z[i];
            }
            int r = 0;
            R sx0 = 0, sy0 = 0, sz0 = 0;
            int n0 = 0;
            for (int l = 0; l < n - 2; ++l) {
                while (th[r] < th[l] + pi) {
                    sx0 += x[idx[r]], sy0 += y[idx[r]], sz0 += z[idx[r]];
                    ++n0;
                    ++r;
                }
                for (int S = 0; S < 8; ++S) {
                    if (S & 1) {
                        sx0 += x[p], sy0 += y[p], sz0 += z[p];
                        ++n0;
                    }
                    if (S & 2) {
                        sx0 += x[q], sy0 += y[q], sz0 += z[q];
                        ++n0;
                    }
//                    if (S & 4) {
//                        sx0 += x[idx[l]], sy0 += y[idx[l]], sz0 += z[idx[l]];
//                        ++n0;
//                    }
                    R sx1 = sx - sx0, sy1 = sy - sy0, sz1 = sz - sz0;
                    int n1 = n - n0;
                    assert(n0 >= 0 and n1 >= 0);
                    if (n0 and n1) {
                        R crr = base;
                        crr -= (sx0 * sx0 + sy0 * sy0 + sz0 * sz0) / n0;
                        crr -= (sx1 * sx1 + sy1 * sy1 + sz1 * sz1) / n1;
                        res = min(res, crr);
                    }
                    if (S & 1) {
                        sx0 -= x[p], sy0 -= y[p], sz0 -= z[p];
                        --n0;
                    }
                    if (S & 2) {
                        sx0 -= x[q], sy0 -= y[q], sz0 -= z[q];
                        --n0;
                    }
//                    if (S & 4) {
//                        sx0 -= x[idx[l]], sy0 -= y[idx[l]], sz0 -= z[idx[l]];
//                        --n0;
//                    }
                }
                sx0 -= x[idx[l]], sy0 -= y[idx[l]], sz0 -= z[idx[l]];
                --n0;
            }
        }
    }
    cout << fixed << setprecision(6) << res << endl;
}