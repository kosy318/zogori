#include <cstdio>
#include <queue>
#include <utility>
#include <vector>

#define fprintf(...)

using namespace std;
vector<std::pair<int, int> > e[100000];
int v[100000];

struct P
{
    int n, pl;
    long long s1, s2;
} u[100000];

long long ca(const P& p1, const P& p2)
{
    long long d = p1.pl + p2.pl;
    return \
    + d * d * p1.n * p2.n \
    + p1.s2 * p2.n + p2.s2 * p1.n \
    + 2 * (p1.s1 * p2.s1 + d * (p1.s1 * p2.n + p2.s1 * p1.n));
}

int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        --a, --b;
        e[a].push_back({b, l});
        e[b].push_back({a, l});
    }
    queue<int> q;
    vector<P*> qq;
    for (int i = 0; i < n; ++i)
    {
        if (e[i].size() == 1) q.push(i), u[i].n = 1, v[i] = 2;
    }
    int t;
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        int l = 0;
        qq.clear();
        for (auto c : e[t])
        {
            if (v[c.first])
            {
                u[c.first].pl = c.second;
                u[t].n += u[c.first].n;
                u[t].s1 += u[c.first].s1 + u[c.first].n * c.second;
                u[t].s2 += u[c.first].s2 + u[c.first].n * c.second * c.second + 2 * c.second * u[c.first].s1;
                qq.push_back(u + c.first);
                fprintf(stderr, "## %d %d %d %d %lld %lld\n", t, c.first, c.second, u[t].n, u[t].s1, u[t].s2);
            }
            ++v[c.first];
            if (v[c.first] == 2) q.push(c.first), v[c.first] = 9999;
        }
        // u[t].s2 = (u[t].s2 + u[t].s1 * u[t].s1) / 2;
        int m = qq.size();
        for (int i = 0; i < m; ++i) for (int j = 0; j < i; ++j)
        {
            ans += ca(*qq[i], *qq[j]);
            fprintf(stderr, "%d %d %lld\n", int(qq[i] - u), int(qq[j] - u), ans);
        }
    }
    printf("%lld", ans);
    return 0;
}
