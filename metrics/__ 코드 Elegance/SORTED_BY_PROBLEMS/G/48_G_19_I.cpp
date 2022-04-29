#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;

int x[100005], clr[100005], gmin[100005], gTN[100005];
vector<int> g[100005], d[100005];
vector<vector<int>> dtree;

int range_min(vector<int> &tree, int ql, int qr, int idx, int l, int r){
    if(r < ql || qr < l) return inf;
//    if(ql <= l && r <= qr) printf("%d %d %d %d: %d\n", ql, qr, l, r, tree[idx]);
    if(ql <= l && r <= qr) return tree[idx];
    return min(range_min(tree, ql, qr, idx * 2, l, (l + r) / 2),
               range_min(tree, ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void update(vector<int> &tree, int idx, int val){
    tree[idx] = val;
    for(idx >>= 1; idx; idx >>= 1)
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
    memset(gmin, 0x3f, sizeof(gmin));

    int K, N; scanf("%d %d", &K, &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &x[i]);
    for(int i = 1; i <= N; i++)
        scanf("%d", &clr[i]);

    x[0] = -inf; x[N + 1] = inf;
    clr[0] = 0; clr[N + 1] = K + 1;
    g[0].push_back(x[0]);
    int G = 1, idx = 1;
    while(idx <= N){
        g[G].push_back(x[idx++]);
        while(idx <= N && clr[idx] == clr[idx - 1]) g[G].push_back(x[idx++]);
        G++;
    }
    g[G].push_back(x[N + 1]);

    d[0].push_back(0); gmin[0] = 0;
    gTN[0] = 1; dtree.push_back(vector<int>(2, inf));
    update(dtree[0], gTN[0] + 1 - 1, 0);
    for(int gi = 1; gi <= G; gi++){
        for(gTN[gi] = 1; gTN[gi] < g[gi].size(); gTN[gi] <<= 1);
        dtree.push_back(vector<int>(2 * gTN[gi], inf));

        int pN = g[gi - 1].size(), l = 0, r = pN - 1;
        int curx = g[gi][0], S = g[gi][0], E = g[gi - 1][(int)g[gi - 1].size() - 1];
        while(r >= 0 && curx - S > S - g[gi - 1][r]) r--;
        while(l < pN && curx - E < E - g[gi - 1][l]) l++;
//        printf("%d\n", dtree[gi - 1].size());
//        printf("%d\n", range_min(dtree[gi - 1], 0, gTN[gi - 1] - 1, 1, 0, gTN[gi - 1] - 1));
        d[gi].push_back(range_min(dtree[gi - 1], l, r, 1, 0, gTN[gi - 1] - 1) + 1);
        gmin[gi] = min(gmin[gi], d[gi][0]);
        update(dtree[gi], gTN[gi], d[gi][0]);
//        printf("%d - %d %d %d %d\n", dtree[gi - 1][1], dtree[gi - 1][4], dtree[gi - 1][5], dtree[gi - 1][6], dtree[gi - 1][7]);
//        printf("%d %d\n", l, r);
//        printf("d[%d][%d]: %d\n", gi, 0, d[gi][0]);
        for(int j = 1; j < (int)g[gi].size(); j++){
            d[gi].push_back(inf);
            int &curd = d[gi][j];
            curx = g[gi][j];
            curd = min(curd, gmin[gi]);
            while(r >= 0 && curx - S > S - g[gi - 1][r]) r--;
            while(l < pN && curx - E < E - g[gi - 1][l]) l++;
            curd = min(curd, range_min(dtree[gi - 1], l, r, 1, 0, gTN[gi - 1] - 1) + 1);
            update(dtree[gi], gTN[gi] + j, curd);
            gmin[gi] = min(gmin[gi], curd);
//            printf("%d %d\n", l, r);
//            printf("d[%d][%d]: %d\n", gi, j, d[gi][j]);
        }
    }
    printf("%d\n", d[G][0] - 1);

    return 0;
}