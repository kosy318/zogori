#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second
using iii = tuple<int,int,int>;

int n, k, a[123][3];
int pos[123];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        pos[i] = i;
        for(int j=0; j<3; ++j)
            cin >> a[i][j];
    }
    if(k == 1){
        double avg[3] = {};
        for(int i=0; i<n; ++i)
            for(int j=0; j<3; ++j)
                avg[j] += a[i][j];
        for(int j=0; j<3; ++j)
            avg[j] /= n;

        double ans = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<3; ++j)
                ans += (avg[j] - a[i][j])*(avg[j] - a[i][j]);
        cout.precision(6);
        cout << fixed << ans;

        return 0;
    }

    double ans = 123123412341234123.0;
    for(int pivot = 0; pivot<3; ++pivot){
        for(int i=0; i<n; ++i){
            int k = a[i][pivot];

            double avg[3][2] = {};
            int sz[2] = {};
            for(int i=0; i<n; ++i){
                bool flag = (a[i][pivot] <= k);
                ++sz[flag];
                for(int j=0; j<3; ++j)
                    avg[j][flag] += a[i][j];
            }
            for(int j=0; j<3; ++j)
                avg[j][0] /= sz[0], avg[j][1] /= sz[1];

            double ret = 0;
            for(int i=0; i<n; ++i){
                bool flag = (a[i][pivot] <= k);
                for(int j=0; j<3; ++j)
                    ret += (avg[j][flag] - a[i][j])*(avg[j][flag] - a[i][j]);
            }
            ans = min(ans,ret);
        }
    }
    cout.precision(6);\
    cout << fixed << ans;
}
