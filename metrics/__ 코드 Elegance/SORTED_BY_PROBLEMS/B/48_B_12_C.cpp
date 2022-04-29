#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

struct Edge {
   int to; ll c;
};

vector<Edge> v[100005];
ll siz[100005];
ll ans;
ll sum[100005];
ll sq[100005];
void dpf(int cur, int p) {
    siz[cur] = 0;
    if (v[cur].size() == 1) siz[cur] = 1;
    ll pp = 0;
    ll psiz = 0;
    for (Edge &nxt : v[cur]) if (nxt.to != p) {
        dpf(nxt.to, cur);
        siz[cur] += siz[nxt.to];
        sq[nxt.to] = sq[nxt.to] + nxt.c * nxt.c * siz[nxt.to]
                     + 2 * nxt.c * sum[nxt.to];
        sum[nxt.to] = sum[nxt.to] + nxt.c * siz[nxt.to];
        sum[cur] += sum[nxt.to];
        sq[cur] += sq[nxt.to];
        psiz += siz[nxt.to];
    }
    pp = sum[cur];
//    for (Edge &nxt : v[cur]) if (nxt.to != p) {
//        printf("[%d %d] : %lld %lld %lld\n", cur, nxt.to, sum[nxt.to], siz[nxt.to], sq[nxt.to]);
//    }
    for (Edge &nxt : v[cur]) if (nxt.to != p) {
        pp -= sum[nxt.to];
        ans += (siz[cur] - siz[nxt.to]) * sq[nxt.to] +
                2 * pp * sum[nxt.to];
    }
//    printf("[%d] %lld\n", cur, ans);
}


int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= N; i++) if (v[i].size() > 1){
        dpf(i, 0);
        break;
    }
//    for (int i = 1; i <= N; i++) {
//        printf("[%d] %lld %lld %lld\n", i, psum[i], [i]);
//    }
    printf("%lld\n", ans);
}