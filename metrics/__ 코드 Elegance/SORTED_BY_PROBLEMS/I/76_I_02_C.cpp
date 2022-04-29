//
// Created by team076 on 19. 11. 9..
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

struct dfs_ret {
    ll lengths;
    ll sum1, sum2;
    ll size;
};

dfs_ret dfs(const vvpii& adj, ll x, ll par = -1) {
    if(adj[x].size() == 1) {
        return {0, 0, 0, 1};
    }
        vector<dfs_ret> child_ret; vector<ll> child_cost, child_sum1, child_sum2;
        for(const auto& there : adj[x]) {
            if (there.first == par) continue;
            auto ret = dfs(adj, there.first, x);
            child_ret.emplace_back(ret);
            child_sum1.emplace_back(ret.sum1 + there.second * ret.size);
            child_sum2.emplace_back(ret.sum2 + 2 * there.second * ret.sum1 + ret.size * there.second * there.second);
        }

        ll result_length = child_ret[0].lengths + child_ret[1].lengths;
        auto additional_length = child_ret[1].size * child_sum2[0] + child_ret[0].size * child_sum2[1] + 2 * child_sum1[0] * child_sum1[1];
        result_length += additional_length;

        dfs_ret temp = {result_length, child_sum1[0] + child_sum1[1], child_sum2[0] + child_sum2[1], child_ret[0].size + child_ret[1].size};
        //cout << "on " << x << ' ' << temp.lengths << ' ' << temp.sum1 << ' ' << temp.sum2 <<  ' ' << temp.size << endl;
        return temp;
}

int main() {
    int n; cin  >> n;
    vvpii adj(n, vpii());
    for(int i = 0; i < n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    ll root = 0;
    for(; root < n; ++root) {
        if(adj[root].size() > 1){
           // cout << "root " << root << endl;
            adj.emplace_back();
            adj[n].emplace_back(root, 0);
            adj[n].emplace_back(adj[root][0].first, adj[root][0].second);
            for(auto& it : adj[adj[root][0].first]) {
                if(it.first == root) {
                    it.first = n;
                    break;
                }
            }
            adj[root][0].first = n;
            adj[root][0].second = 0;
            cout << dfs(adj, n).lengths;
            return 0;
        }
    }

    return 0;
}