#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, P>; // n , a(sum), b(square sum)

const int MAX_N=100001;

int N;
vector<P> adj[MAX_N];
ll ret = 0;



PP makeTree(int here, int parent=-1) {
    if (adj[here].size() == 1) return PP(1, P(0, 0));
    vector<PP> seq;
    ll total_n = 0;
    ll total_a = 0;
    ll total_b = 0;
    for (P &p: adj[here]) {
        ll nx = p.first;
        ll w = p.second;
        if (nx != parent) {
            PP ans = makeTree(nx, here);
            ll n = ans.first;
            ll a = ans.second.first;
            ll b = ans.second.second;
            b += n*w*w + w*2*a;
            a += w*n;
            seq.push_back(PP(n, P(a,b)));
            total_n += n;
            total_a += a;
            total_b += b;
        }
    }
    ll tmp = 0;
    for (PP &pp: seq) {
        ll n = pp.first;
        ll a = pp.second.first;
        ll b = pp.second.second;
        tmp += (total_n-n)*b + 2*a*(total_a-a) + n*(total_b-b);
    }
    ret += tmp/2;
    return PP(total_n, P(total_a, total_b));
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        adj[u].push_back(P(v,w));
        adj[v].push_back(P(u,w));
    }

    for (int i=0; i<N; i++) {
        if (adj[i].size() > 1) {
            makeTree(i);
            break;
        }
    }
    printf("%lld\n", ret);
    return 0;
}