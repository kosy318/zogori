#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

constexpr int MAXN = 10'0000;

static int N;
static pair<int,int> dat[MAXN];

static bool check(int x) {
    ll last = dat[0].first;

    for (int i = 1; i < N; ++i) {
        const ll clast = last + x;
        if (dat[i].first <= clast && clast <= dat[i].second) {
            last = clast;
            continue;
        }
        if (dat[i].first >= clast) {
            last = dat[i].first;
            continue;
        }
        return false;
    }

    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        dat[i] = {x, x+y};
    }

    sort(dat, dat + N);
    int l = 0, r = 20'0000'0000, ans = 0;
    while (l <= r) {
        const int m = (ll(l) + r) / 2;

        if (check(m)) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << ans << "\n";
}

/*
6
0 40
10 55
45 28
90 40
83 30
120 30

30
*/