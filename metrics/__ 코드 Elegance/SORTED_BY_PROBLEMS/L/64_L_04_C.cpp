#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
ll dp[20000];
ll N, M;
ll P[105];
vector<l_l> Query[20000];

bool chmax(ll &a, ll b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        cin >> P[i];
    }
    for(int i = 1; i <= N; i++) {
        int e, s, t;
        cin >> s >> e >> t;
        Query[s].push_back({e, t});
    }
    for(int timer = 0; timer <= 15000; timer++) {
        chmax(dp[timer+1], dp[timer]);
        for(auto q : Query[timer]) {
            chmax(dp[q.first], dp[timer] + (q.first - timer) * P[q.second]);
        }
    }
    cout << dp[15001] << endl;
    return 0;
}