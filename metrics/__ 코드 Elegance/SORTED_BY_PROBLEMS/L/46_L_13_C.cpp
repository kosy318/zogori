#include <bits/stdc++.h>
using namespace std;

int m,n;
set <int> tl;

int T[15001];
int value[10001];
int cnt[15001];

class mineral {
public:
    int s,e,t;
    mineral(int _s, int _e, int _t) : s(_s), e(_e), t(_t) {}
    bool operator < (const mineral& A) const {
        if(e != A.e) return e < A.e;
        else if(s != A.s) return s < A.s;
    }
};

vector < mineral > events;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for(int i=1; i<=m; i++) cin >> value[i];

    for(int i=0; i<n; i++) {
        int s,e,t;
        cin >> s >> e >> t;
        events.push_back(mineral(s,e,t));
    }

    sort(events.begin(),events.end());

    for(auto event : events) {
        for(int i=1; i<15001; i++) {
            T[i] = max(T[i], T[i-1]);
            if(i == event.e) {
                T[i] = max(T[i], T[event.s] + value[event.t] * (event.e - event.s));
            }
        }
    }

    cout << T[15000];

    return 0;
}
