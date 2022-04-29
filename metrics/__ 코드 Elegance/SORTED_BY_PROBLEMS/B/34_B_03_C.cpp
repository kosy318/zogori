#include <bits/stdc++.h>
using namespace std;


const int N_ = int(1.1e5);

using lint = long long;

int N;
vector<pair<int, int>> gph[N_];

struct State {
    lint sum_sq, sum_li; // sum (leaf -> root)
    lint ans; // sum leaf^2
    lint n; // num leaves
};

State go(int u, int p) {
    if(gph[u].size() == 1) {
        return State{0, 0, 0,1};
    }
    State ret{0, 0, 0, 0};
    for(auto it : gph[u]) {
        int v, c; tie(v, c) = it;
        if(v == p) continue;

        auto ch0 = go(v, u);
        State ch = ch0;
        ch.sum_sq = ch0.sum_sq + 2ll * c * ch0.sum_li + (lint)c * c * ch0.n;
        ch.sum_li = ch0.sum_li + 1ll * c * ch0.n;

        ret.ans = ret.ans + ch.ans
                + ret.sum_sq * ch.n + ch.sum_sq * ret.n
                + 2ll * ret.sum_li * ch.sum_li;
        ret.sum_sq += ch.sum_sq;
        ret.sum_li += ch.sum_li;
        ret.n += ch.n;
        //printf("%d %d: %lld %lld %lld %lld\n", u, v, ret.sum_sq, ret.sum_li, ret.ans, ret.n);
    }
    return ret;
}

/*/home/team034/CLionProjects/b/cmake-build-debug/b
6
1 5 1
5 2 1
5 6 1
6 4 3
6 3 2
5 1: 1 1 0 1
5 2: 2 2 4 2
6 4: 9 3 0 1
6 3: 13 5 25 2
5 6: 40 14 157 4
157*/

/*2 1: 100 10 0 1
2 10: 149 17 289 2
9 8: 4 2 0 1
9 7: 5 3 9 2
3 9: 46 12 9 2
4 6: 9 3 0 1
4 5: 13 5 25 2
3 4: 144 30 754 4
2 3: 1173 109 6815 6
6815
*/

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        gph[u].emplace_back(v, c);
        gph[v].emplace_back(u, c);
    }

    for(int u = 1; u <= N; u++) {
        if(gph[u].size() > 1) {
            printf("%lld\n", go(u, -1).ans);
            break;
        }
    }
    return 0;
}