#include <iostream>
#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef tuple<int, int, int> tt;
const int MAX = 100005;


int n, k;
double xs1, ys1, zs1;
double xs2, ys2, zs2;

int cnt1, cnt2;
int group[105];
tt point[105];

double get_energy()
{
    double ret = 0;
    for (int i=1; i<=n; i++)
    {
        int x, y, z;
        tie(x, y, z ) = point[i];
        if (group[i] == 1)
        {
            ret += (xs1 / cnt1 - x) * (xs1 /cnt1 - x) + (ys1 / cnt1 - y) * (ys1 / cnt1 - y) + (zs1 / cnt1 - z) * (zs1 / cnt1 - z);
        }
        else
        {
            ret += (xs2 / cnt2 - x) * (xs2 / cnt2 - x) + (ys2/cnt2 - y) * (ys2 /cnt2- y) + (zs2 / cnt2 - z) * (zs2 / cnt2 - z);
        }
    }
    return ret;
}


double change(int i)
{
    int j = group[i];
    int x, y,z;
    tie(x, y, z) = point[i];

    if ( j == 1 )
    {
        xs1 -= x;
        ys1 -= y;
        zs1 -= z;
        cnt1--;
        xs2 += x;
        ys2 += y;
        zs2 += z;
        cnt2++;

        group[i] = 2;
    }

    if ( j == 2 )
    {
        xs2 -= x;
        ys2 -= y;
        zs2 -= z;
        cnt2--;
        xs1 += x;
        ys1 += y;
        zs1 += z;
        cnt1++;

        group[i] = 1;
    }

}



signed main() {
     srand(7777);
     cin >> n >> k;

    for (int i=1; i<=n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        point[i] = tt(x, y, z);
    }

    if (k == 1)
    {
        double ans = 0;
        double xs = 0, ys = 0, zs = 0;

        for (int i=1; i<=n; i++) {
            xs += get<0>(point[i]);
            ys += get<1>(point[i]);
            zs += get<2>(point[i]);
        }
        xs /= n;
        ys /= n;
        zs /= n;

        for (int i=1; i<=n; i++)
        {
            int x, y, z;
            tie(x, y, z) = point[i];
            ans += (xs - x) * (xs - x) + (ys - y) * (ys - y) + (zs - z) * (zs - z);
        }

        printf("%.6f", ans);
        return 0;
    }

    else
    {
        int x, y, z;
        for (int i=1; i<n/2; i++)
        {
            tie(x, y, z) = point[i];
            xs1 += x;
            ys1 += y;
            zs1 += z;
            cnt1++;
            group[i] = 1;
        }

        for (int i=n/2; i<= n; i++)
        {
            tie(x, y, z) = point[i];
            xs2 += x;
            ys2 += y;
            zs2 += z;
            cnt2++;
            group[i] = 2;
        }
    }

    double ans = 9e18;
    int epoch = 3700000;
    double k = 10;
    double E1 = get_energy();
    while (epoch--)
    {
        ans = min(ans, E1);

        int i = rand() % n + 1;
        change(i);
        double E2 = get_energy();

        if ((exp(E1 - E2) / k ) > (double)(rand() % 100) / 100)
        {
            E1 = E2;
        }
        else{
            change(i);
        }

        k *= 0.9999;
    }

    printf("%.6f", ans);
    return 0;
}