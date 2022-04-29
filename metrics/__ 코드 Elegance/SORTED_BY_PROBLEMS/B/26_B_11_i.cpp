#include <stdio.h>
#include <vector>
#include <queue>
#define MAX_COUNT 100005
using namespace std;

typedef struct {
    int from;
    int to;
    int wei;
}Node;

typedef struct {
    int to;
    int wei;
}Edge;

vector<Edge> graph[MAX_COUNT];
int parent[30][MAX_COUNT], cnt[MAX_COUNT], depth[MAX_COUNT], len[30][MAX_COUNT];
int n;

void prepare_lca(int root)
{
    queue<int> q;
    q.push(root);
    depth[root] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(Edge e : graph[cur])
        {
            if(e.to != root && depth[e.to] == 0) {
                depth[e.to] = depth[cur] + 1;
                q.push(e.to);
            }
        }
    }

    for(register int i = 1; i< 30; i++) {
        for(register int j =0; j <= n; j++) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            len[i][j] = len[i-1][parent[i-1][j]] + len[i-1][j];

        }
    }
}

long long lca(int u, int v)
{
    if(depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }
    long long res = 0;
    if(depth[u] > depth[v]) {
        for(register int i = 29; i>=0; i--) {
            if(depth[u] - (1<<i) >= depth[v]) {
                res += len[i][u];
                u = parent[i][u];
            }
        }
    }

    if(u == v) return res;
    for(register int i = 29; i >=0; i--) {
        if(parent[i][u] != parent[i][v]) {
            res += len[i][u];
            res += len[i][v];
            u = parent[i][u];
            v = parent[i][v];
        }

    }

    return res + len[0][u] + len[0][v];
}
/*
int findLCA(int u, int v)
{
    if(depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    int res = 0;
    while(depth[u] != depth[v]) {
        res = res + len[u];
        u = parent[u];
    }
    if(u == v) return res;

    while(u != v)
    {
        res += len[u];
        res += len[v];
        u = parent[u];
        v = parent[v];
    }

    return res;
}
*/

int leaf[MAX_COUNT], leafCnt;

int main()
{
    scanf("%d", &n);
    int a, b, w;


    for(register int i = 0 ; i < n-1; i++) {
        scanf("%d %d %d", &a, &b, &w);
        cnt[a]++;
        cnt[b]++;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    int root = 0;
    for(register int i = 1; i <= n; i++) {
        if(cnt[i] == 3) {
            if(root == 0) {
                root = i;
                parent[0][root] = root;
            }
            for(Edge e : graph[i]) {
                if(parent[0][e.to] == 0) {
                    parent[0][e.to] = i;
                    len[0][e.to] = e.wei;
                }
            }
        }
        else {
            leaf[leafCnt++] = i;
        }
    }

    prepare_lca(root);
    long long res = 0;
    for(register int i = 0 ; i < leafCnt; i++)
    {
        for(register int j = i+1; j < leafCnt; j++) {
            long long val = lca(leaf[i], leaf[j]);
            res += (val*val);
        }
    }

    printf("%lld\n", res);
    return 0;
}
