#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ans;
int V;
set<int> degree;
vector<vector< pair<int,ll > > >adj;
vector<bool> visited;
void dfs(int here, int parent, ll curcost){
   // cout << here<<" "<<parent<<" " <<curcost<<" "<<degree.count(here)<<endl;
   //cout<<degree.count(here)<<endl;
    if(degree.count(here) ==1  ) {//degree is 1
        ans += curcost*curcost;
        //cout<<parent <<" is calculated "<< here<< endl;
    }
    visited[here]=true;

    for(int i = 0 ; i < adj[here].size() ; ++i){
        int next_node = adj[here][i].first;
        if(visited[next_node]) continue;

        ll edge_cost = adj[here][i].second;
        //cout<<edge_cost<< " is edge_cost"<<endl;
        dfs(next_node,here,curcost + edge_cost);
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>V;
    adj = vector<vector< pair<int,ll > > > ( V + 1);
    for(int i = 1 ; i < V ; ++i){
        int src,dest;
        ll cost;
        cin>>src>>dest>>cost;
        adj[src].push_back({dest,cost});
        adj[dest].push_back({src,cost});
    }

    for(int i = 1; i<=V ; ++i){
        if(adj[i].size() ==1 ){
            degree.insert(i);
            //cout<<i<<" is degree 1 "<<endl;
        }

    }


    for(auto it = degree.begin () ; it != degree.end(); ++it){
        visited = vector<bool>(V+1,false);
        int leaf = *it;

        dfs(leaf,leaf,0);
        //cout<<leaf<<" is leaf "<<endl;
    }
    cout<<ans/2;
}
