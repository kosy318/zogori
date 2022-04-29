#include <bits/stdc++.h>

using namespace std;


double cx, cy, cz;

double x[100];
double y[100];
double z[100];

int check[100];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> z[i];
        cx += x[i];
        cy += y[i];
        cz += z[i];
    }
    cx /= n;
    cy /= n;
    cz /= n;
    cout << fixed;
    cout.precision(6);
    double aa = 0;
    for(int i = 0; i < n; ++i)
        aa += pow(cx - x[i], 2) + pow(cy - y[i], 2) + pow(cz - z[i], 2);
    if(k == 1 || n == 1)
    {
        cout << aa;
        return 0;
    }

    double a, b, c;
    double ans = aa;
    for(int u = 0; u < n; ++u)
    {
       for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == j || j == u || u == i)
                    continue;
                a = (y[i] - y[u]) * (z[j] - z[u]) - (y[j] - y[u]) * (z[i] - z[u]);
                b = (z[i] - z[u]) * (x[j] - x[u]) - (z[j] - z[u]) * (x[i] - x[u]);
                c = (x[i] - x[u]) * (y[j] - y[u]) - (x[j] - x[u]) * (y[i] - y[u]);
                double ccx[2] = {0,}, ccy[2] = {0,}, ccz[2] = {0,};
                int cnt[2] = {0,};
                for(int k = 0; k < n; ++k)
                {
                    if(k == i || k == j)
                        continue;
                    check[k] = a * pow(x[k] - x[u], 2) + b * pow(y[k] - y[u], 2) + c * pow(z[k] - z[u], 2) > 0;
                    ccx[check[k]] += x[k];
                    ccy[check[k]] += y[k];
                    ccz[check[k]] += z[k];
                    cnt[check[k]]++;
                }
                double cccx[2], cccy[2], cccz[2];
                for(check[i] = 0; check[i] < 2; ++check[i])
                {
                    for(check[j] = 0; check[j] < 2; ++check[j])
                    {
                        cccx[0] = (ccx[0] + !check[i] * x[i] + !check[j] * x[j]) / (!check[i] + !check[j]  + cnt[0]);
                        cccx[1] = (ccx[1] + check[i] * x[i] + check[j] * x[j]) / (check[i] + check[j] + cnt[1]);
                        cccy[0] = (ccy[0] + !check[i] * y[i] + !check[j] * y[j]) / (!check[i] + !check[j]  + cnt[0]);
                        cccy[1] = (ccy[1] + check[i] * y[i] + check[j] * y[j]) / (check[i] + check[j] + cnt[1]);
                        cccz[0] = (ccz[0] + !check[i] * z[i] + !check[j] * z[j]) / (!check[i] + !check[j]  + cnt[0]);
                        cccz[1] = (ccz[1] + check[i] * z[i] + check[j] * z[j]) / (check[i] + check[j] + cnt[1]);
                        double val = 0;
                        for(int k = 0; k < n; ++k)
                        {
                            val += pow(cccx[check[k]] - x[k], 2) + pow(cccy[check[k]] - y[k], 2) + pow(cccz[check[k]] - z[k], 2);
                        }
                        if(val < ans)
                            ans = val;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
