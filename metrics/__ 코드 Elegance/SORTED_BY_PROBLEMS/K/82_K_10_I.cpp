#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

int n, k;
double x[N];
double y[N];
double z[N];

double ax[2];
double ay[2];
double az[2];
int sz[2];

int color[N];

double price;
void relax() {

    ax[0] = ax[1] = 0;
    ay[0] = ay[1] = 0;
    az[0] = az[1] = 0;
    sz[0] = sz[1] = 0;

    for (int i = 1; i <= n; i++) {
        ax[color[i]] += x[i];
        ay[color[i]] += y[i];
        az[color[i]] += z[i];
        sz[color[i]]++;
    }
    for (int c = 0; c < 2; c++) {
        ax[c] /= double(sz[c]);
        ay[c] /= double(sz[c]);
        az[c] /= double(sz[c]);
    }

    double cost = 0;
    for (int i = 1; i <= n; i++) {
        cost += (x[i] - ax[color[i]]) * (x[i] - ax[color[i]])
        + (y[i] - ay[color[i]]) * (y[i] - ay[color[i]])
        + (z[i] - az[color[i]]) * (z[i] - az[color[i]]);
    }
    price = min(price, cost);
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    {
        double ax = 0, ay = 0, az = 0;
        for (int i = 1; i <= n; i++) {
            ax += x[i];
            ay += y[i];
            az += z[i];
        }
        ax /= double(n);
        ay /= double(n);
        az /= double(n);
        for (int i = 1; i <= n; i++) {
            price += (x[i] - ax) * (x[i] - ax) + (y[i] - ay) * (y[i] - ay) + (z[i] - az) * (z[i] - az);
        }
    }

    if (k == 1) {
        cout << fixed << setprecision(6) << price;
        return 0;
    }

    for (int st = 1; st <= n; st++) {

        for (int i = 1; i <= n; i++) color[i] = 0;
        color[st] = 1;

        relax();
        while (sz[1] < n) {

            int nearest = -1;
            double our_dist;
            for (int i = 1; i <= n; i++) {
                if (!color[i]) {
                    double dist = (x[i] - ax[1]) * (x[i] - ax[1]) + (y[i] - ay[1]) * (y[i] - ay[1]) + (z[i] - az[1]) * (z[i] - az[1]);
                    if (nearest == -1) nearest = i, our_dist = dist;
                    else {
                        if (dist <= our_dist) nearest = i, our_dist = dist;
                    }
                }
            }
            assert(nearest != -1);

            color[nearest] = 1;
            relax();
        }

    }
    cout << fixed << setprecision(6) << price;

    return 0;
}

