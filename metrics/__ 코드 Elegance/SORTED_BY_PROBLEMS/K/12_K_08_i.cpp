#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Pt {
    double x, y, z;
};

double C(vector<Pt> &pts) {
    double sx = 0, sy = 0, sz = 0;
    int n = pts.size();
    for(int i=0; i<n; i++) {
        sx += pts[i].x;
        sy += pts[i].y;
        sz += pts[i].z;
    }

    sx /= n;
    sy /= n;
    sz /= n;

    double ret = 0;
    for(int i=0; i<n; i++) {
        ret += pow(pts[i].x - sx, 2);
        ret += pow(pts[i].y - sy, 2);
        ret += pow(pts[i].z - sz, 2);
    }

    return ret;
}

struct Plane {
    double a, b, c, d;

    Plane(Pt u, Pt v, Pt w) {
        Pt uv = {v.x - u.x, v.y - u.y, v.z - u.z};
        Pt uw = {w.x - u.x, w.y - u.y, w.z - u.z};

        a = uv.y*uw.z - uv.z*uw.y;
        b = -(uv.x*uw.z - uv.z*uw.x);
        c = uv.x*uw.y - uv.y*uw.x;
        d = -(a*u.x + b*u.y + c*u.z);
    }

    bool eval(Pt p) {
        return (a*p.x + b*p.y + c*p.z + d) > 0;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed;
    cout.precision(6);

    int n, k; cin >> n >> k;
    vector<Pt> pts(n);
    for(int i=0; i<n; i++) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
    }

    if(k == 1) {
        cout << C(pts) << endl;
        return 0;
    }

    if(n <= 2) {
        cout << 0.0000 << endl;
        return 0;
    }

    auto calc = [&](int i, int j, int k) {
        Plane P(pts[i], pts[j], pts[k]);
        vector<Pt> S1, S2;
        for(int t=0; t<n; t++) {
            if(t == i || t == j || t == k) continue;
            if(P.eval(pts[t])) S1.push_back(pts[t]);
            else S2.push_back(pts[t]);
        }

        double ret = 1e18;
        for(int t=0; t<8; t++) {
            if((1<<0)&t) S1.push_back(pts[i]); else S2.push_back(pts[i]);
            if((1<<1)&t) S1.push_back(pts[j]); else S2.push_back(pts[j]);
            if((1<<2)&t) S1.push_back(pts[k]); else S2.push_back(pts[k]);

            ret = min(ret, C(S1) + C(S2));

            if((1<<2)&t) S1.pop_back(); else S2.pop_back();
            if((1<<1)&t) S1.pop_back(); else S2.pop_back();
            if((1<<0)&t) S1.pop_back(); else S2.pop_back();
        }

        return ret;
    };

    double res = 1e18;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                res = min(res, calc(i, j, k));
            }
        }
    }

    cout << res << endl;

    return 0;
}
