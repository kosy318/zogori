#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Node {
    ll cnt, sum, sqsum;
};

ll res;
int N, S;
vector<pair<int, int> > g[100101];
int deg[100101];

Node DFS(int n, int prev)
{
    if (deg[n] == 1)
    {
        Node ret;
        ret.cnt = 1;
        ret.sum = 0;
        ret.sqsum = 0;
        return ret;
    }
    vector<Node> sub;
    ll val = 0;
    ll pcnt = 0, psum = 0, psqsum = 0;
    for(int i=0; i<g[n].size(); i++) {
        int next = g[n][i].first, cost = g[n][i].second;
        if (next == prev) continue;
        Node x = DFS(next, n);
        x.sqsum += 2LL * x.sum * cost + x.cnt * cost * cost;
        x.sum += x.cnt * cost;
        sub.push_back(x);
    }
    for(int i=0; i<sub.size(); i++)
    {
        ll cnt = sub[i].cnt, sum = sub[i].sum, sqsum = sub[i].sqsum;
        val += cnt*psqsum + 2LL*psum*sum + pcnt*sqsum;

        pcnt += cnt; psum += sum; psqsum += sqsum;
    }
    val *= 2;
    res += val;

    Node ret;
    ret.cnt = pcnt;
    ret.sum = psum;
    ret.sqsum = psqsum;
    return ret;
}

int main()
{
    scanf("%d", &N);
    // N >= 4

    for(int i=0; i<N-1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=N; i++) {
        if (deg[i] != 1)
            S = i;
    }
    DFS(S, 0);
    printf("%lld", res/2);
    return 0;
}
/*
10
 1 2 10
 10 2 7
 3 2 8
 3 9 3
 9 8 2
 7 9 1
 6 4 3
 4 5 2
 3 4 4
 */