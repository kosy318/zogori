#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node
{
    ll sum[2];
    ll ssum[2];
    ll e[2];
    ll s[2];
    int c = 0;

    ll getval()
    {
        return (sum[0]+e[0]*s[0]) * (sum[1]+e[1]*s[1])*2 + (ssum[0] + 2*sum[0]*e[0] + e[0]*e[0]*s[0]) * s[1] + (ssum[1] + 2*sum[1]*e[1] + e[1]*e[1]*s[1]) * s[0];
    }

    ll getssum()
    {
        return (ssum[0] + 2*sum[0]*e[0] + e[0]*e[0]*s[0]) + (ssum[1] + 2*sum[1]*e[1] + e[1]*e[1]*s[1]);
    }
    ll getsum()
    {
        return sum[0] + sum[1] + e[0] * s[0] + e[1] * s[1];
    }
    ll getsize()
    {
        return s[0] + s[1];
    }
};

struct edge
{
    int v;
    ll c;

    edge(int vv, ll cc)
    {
        v = vv, c = cc;
    }
};

vector<edge> edges[100000];
node ns[100000];
queue<int> leaf;
ll ans = 0;

void visit(int i)
{
    if(edges[i].size() == 0)
    {
        ns[i].s[1] = 1;

        ans += ns[i].getval();
        return;
    }
    ans += ns[i].getval();

    int par = edges[i][0].v;
    int cn = ns[par].c;

    ns[par].sum[cn] = ns[i].getsum();
    ns[par].ssum[cn] = ns[i].getssum();
    ns[par].s[cn] = ns[i].getsize();
    ns[par].e[cn] = edges[i][0].c;
    int j;
    for(j = 0; j < edges[par].size(); ++j)
    {
        if(edges[par][j].v == i)
            break;
    }
    edges[par].erase(edges[par].begin() + j);

    if(++ns[par].c == 2)
    {
        visit(par);
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(edge(b, c));
        edges[b].push_back(edge(a, c));
    }
    for(int i = 0; i < n; ++i)
    {
        if(edges[i].size() == 1)
        {
            ns[i].s[0] = 1;
            leaf.push(i);
        }
    }
    while(!leaf.empty())
    {
        int i = leaf.front();
        leaf.pop();
        visit(i);
    }
    cout << ans;
    return 0;
}
