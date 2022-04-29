#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

const int INF = 0x7f7f7f7f;
int m, n;
int loc[100010];
int col[100010];
int dt[100010];

int tree[262144];
int t_size;

map <int, int> M;

void upd(int x, int v)
{
    if (x == 0) return;
    tree[x] = min(tree[x], v);
    upd(x/2, v);
}

int get(int s, int e)
{
    int ret = INF;
    while (s < e)
    {
        if (s%2 == 1) ret = min(ret, tree[s++]);
        if (e%2 == 0) ret = min(ret, tree[e--]);
        s >>= 1;
        e >>= 1;
    }
    if (s == e) ret = min(ret, tree[s]);
    return ret;
}

int main(void){

    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &loc[i]);
        M[loc[i]] = i;
    }
    loc[0] = -INF;
    M[INF] = n+1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &col[i]);
    for (t_size = 1; t_size < n; t_size <<= 1);
    for (int i = 1; i < t_size*2; i++) tree[i] = INF;

    for (int i = 1; i <= n; i++)
        dt[i] = INF;

    int pv1, pv2, pv11, pv22, ccur, cfir;
    pv1 = pv22 = -1; pv2 = pv11 = loc[1]; ccur = col[1], cfir = 1;
    for (int i = 1; i <= n; i++)
    {
        //printf("<%d>\n", i);
        if (col[i] != ccur)
        {
            ccur = col[i];
            cfir = i;
            pv1 = pv11; pv22 = pv2;
            pv2 = loc[i];
        }
        pv11 = loc[i];

        if (pv1 == -1)
        {
            dt[i] = 1;
            upd(i+t_size, 1);
            continue;
        }

        //printf("%d %d\n", pv1, pv2);

        int s, e;
        s = M.lower_bound(pv1*2-loc[i])->Y;
        e = M.upper_bound(pv2*2-loc[i])->Y;
        e--;
        //printf("%d %d\n", s, e);
        if (pv1 < loc[s] || loc[e] < pv22)
        {
            dt[i] = dt[cfir]+1;
            upd(i+t_size, dt[i]);
            continue;
        }
        s = max(s, M[pv22]); e = min(e, M[pv1]);

        //printf("%d %d\n", s, e);
        int v = get(s+t_size, e+t_size);
        dt[i] = v+1;
        upd(i+t_size, dt[i]);
    }

    //for (int i = 1; i <= n; i++)
      //  printf("%d %d\n", i, dt[i]);

    int ans = INF;
    for (int i = cfir; i <= n; i++)
        ans = min(ans, dt[i]);
    printf("%d\n", ans);
}

/*
4 6
0 1 4 5 8 9
1 2 2 1 3 4
 */