#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 123;

struct Edge {
    int to, weight;
    Edge() {}
    Edge(int x, int y) {
        to = x;
        weight = y;
    }
};

int n;
int sz[N];
bool dead[N];
bool is_leaf[N];

vector<Edge> g[N];

void calc_sizes(int v, int parent = 0) {
    sz[v] = 1;
    for (auto edge : g[v]) {
        int to = edge.to;
        int w = edge.weight;
        if (dead[to] || to == parent) continue;
        calc_sizes(to, v);
        sz[v] += sz[to];
    }
}

int find_centre(int v) {
    int centre = v;
    int parent = 0;
    while (true) {
        bool found = false;
        for (auto edge : g[centre]) {
            int to = edge.to;
            int w = edge.weight;
            if (dead[to] || to == parent) continue;
            if (sz[to] >= sz[v] / 2) {
                parent = centre;
                centre = to;
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    return centre;
}

vector<int> vertices;

long long dist[N];

void dfs(int v, int parent, int root) {
    if (is_leaf[v]) vertices.push_back(v);
    for (auto edge : g[v]) {
        int to = edge.to;
        int w = edge.weight;
        if (to == parent || dead[to]) continue;
        dist[to] = dist[v] + w;
        dfs(to, v, root);
    }
}

long long ans = 0;

void centroid(int v) {
    calc_sizes(v);
    int centre = find_centre(v);

    dead[centre] = true;

    long long sum = 0;
    long long sum_sq = 0;
    long long cnt = is_leaf[centre];
    for (auto edge : g[centre]) {
        vertices.clear();
        int to = edge.to;
        int w = edge.weight;
        if (dead[to]) continue;
        dist[to] = w;
        dfs(to, centre, centre);

        for (auto v : vertices) {
            long long now = sum_sq + 2ll * sum * (dist[v]) + dist[v] * dist[v] * cnt;
            ans += now;
        }
        for (auto v : vertices) {
             sum_sq += (dist[v] * dist[v]);
            sum += dist[v];
            cnt++;

        }
    }

    for (auto edge : g[centre]) {
        int to = edge.to;
        int w = edge.weight;
        if (dead[to]) continue;
        centroid(to);
    }
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }

    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            is_leaf[i] = true;
        }


    centroid(1);
    cout << ans;

    return 0;
}
