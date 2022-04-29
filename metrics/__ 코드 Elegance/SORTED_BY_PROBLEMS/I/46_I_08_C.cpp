#include <bits/stdc++.h>

using namespace std;

vector < pair < long long,long long > > T;
int n;

bool eval(long long t) {
    long long prev = T[0].first;
    for(int i=1; i<n; i++) {
        if(prev + t <= T[i].first) {
            prev = T[i].first;
        }
        else if(prev + t <= T[i].first + T[i].second) {
            prev = prev + t;
        }
        else {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long ans = 1;
    long long lo=1, hi=2e9;

    cin >> n;
    T.resize(n);
    for(int i=0; i<n; i++) {
        cin >> T[i].first >> T[i].second;
    }

    sort(T.begin(),T.end());

    while(lo<=hi) {
        long long mid = (lo + hi)/2;
        bool res = eval(mid);
        if(res) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
