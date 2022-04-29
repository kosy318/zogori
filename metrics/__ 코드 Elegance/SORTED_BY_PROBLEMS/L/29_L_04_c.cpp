#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<int, P>;
using ll = long long;

const int MAX_M=101;
const int MAX_T=15001;
const int MAX_N=10001;
const int SIZE=MAX_T*4;

int M, N;
int cost[MAX_M];
PP mine[MAX_N];

struct SegTree{
    int size, start;
    ll arr[SIZE];
    SegTree(int n): size(n) {
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }
    void add(int a, ll b) {
        a += start;
        b = max(b, arr[a]);
        while (a > 0) {
            arr[a] = max(arr[a], b);
            a /=2;
        }
    }
    ll sum(int a, int b) { return sum(a, b, 1, 0, start); } // [a, b)
    ll sum(int a, int b, int node, int na, int nb) {
        if (b <= na || nb<=a) return 0;
        if (a <= na && nb<=b) return arr[node];
        int mid = (na+nb)/2;
        return max(sum(a, b, node*2, na, mid), sum(a, b, node*2+1, mid, nb));
    }
};

SegTree seg(MAX_T);

int main() {
    scanf("%d%d", &M, &N);
    for (int i=0; i<M; i++)
        scanf("%d", &cost[i]);

    for (int i=0; i<N; i++) {
        int s, e, t;
        scanf("%d%d%d", &s, &e, &t);
        mine[i] = PP(s, P(e,t-1));
    }
    sort(mine, mine+N);
    for (int i=0; i<N; i++) {
        int s, e, t;
        s = mine[i].first;
        e = mine[i].second.first;
        t = mine[i].second.second;
        seg.add(e, seg.sum(0, s+1)+ (e-s)*cost[t]);
    }
    printf("%lld\n", seg.sum(0, MAX_T));
    return 0;
}