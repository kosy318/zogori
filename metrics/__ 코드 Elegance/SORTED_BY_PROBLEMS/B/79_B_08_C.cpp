#include <iostream>
#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef tuple<ll, ll, int> tt;
const int MAX = 100005;

vector<pii> adj[MAX];
int degree[MAX];
bool visit[MAX];
int n;

ll ans;

tuple<ll, ll, int> dfs(int s)
{
    bool leaf = true;
    ll msum = 0, sum = 0;
    int cnt = 0;

    vector<tt> temp;
    for (auto & edge : adj[s])
    {
        int e = edge.first, cost = edge.second;

        if (!visit[e])
        {
            //cout << s << " -> " << e << endl;
            leaf = false;
            visit[e] = true;
            ll msum2, sum2, cnt2;
            tie(msum2, sum2, cnt2) = dfs(e);

            msum2 = (msum2 + cost*cost*cnt2) + 2*sum2*cost;
            sum2 = sum2 + cnt2*cost;

            temp.push_back(tt(msum2, sum2, cnt2));

            //cout << msum2 << " " << sum2 << " " << cnt2 << endl;

            msum += msum2;
            sum += sum2;
            cnt += cnt2;

        }
    }

    if (leaf)
    {
        return {0, 0, 1};
    }
    else
    {
        //cout << "tot " << msum << " " << sum << " " << cnt << endl;
        for (auto & i : temp)
        {
            ll msum2, sum2, cnt2;
            tie(msum2, sum2, cnt2) = i;
            ans += (cnt - cnt2) * msum2 + sum2*(sum - sum2);
        }

        return tt(msum, sum, cnt);
    }

}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        degree[u]++;
        degree[v]++;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s = -1;
    for (int i=1; i<=n; i++)
    {
        if (degree[i] >= 2)
        {
            s = i;
            break;
        }
    }

    visit[s] = true;
    dfs(s);

    cout << ans;
    return 0;
}