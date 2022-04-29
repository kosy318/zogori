#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct DATA{
    long long x_2;
    long long x;
    int cnt;
    DATA(){}
    DATA(long long a, long long b, int c){
        x_2=a;
        x=b;
        cnt=c;
    }
};

int n;
vector<vector<pair<int,long long>>> adj;
vector<int> leaf;
vector<DATA> data;
vector<pair<int,long long>> parent;
vector<int> indegree;

void dfs(int now, int prv)
{
    bool isleaf=true;
    for(auto& nxt : adj[now]){
        if(nxt.first==prv) continue;
        isleaf=false;
        parent[nxt.first]={now,nxt.second};
        indegree[now]+=1;
        dfs(nxt.first,now);
    }
    if(isleaf){
        leaf.push_back(now);
    }
}

int main() {
    cin>>n;
    indegree.resize(n);
    adj.resize(n);
    data.resize(n,DATA(0,0,0));
    parent.resize(n);
    for(int i=0; i<n-1; i++) {
        int a,b;
        long long l;
        cin>>a>>b>>l;
        adj[a-1].push_back({b-1,l});
        adj[b-1].push_back({a-1,l});
    }

    parent[0].first=-1;
    dfs(0,-1);
    queue<int> q;
    for(int l : leaf){
        q.push(l);
        data[l].cnt=1;
    }
    if(indegree[0]==1) data[0].cnt=1;
    long long answer=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();

        if(parent[now].first==-1) continue;

        DATA d=DATA();
        long long e=parent[now].second;
        d.x_2=data[now].x_2+e*e*data[now].cnt+2*data[now].x*e;
        d.x=data[now].x+e*data[now].cnt;
        d.cnt=data[now].cnt;
        data[now]=d;

        answer+=data[parent[now].first].x_2*d.cnt+d.x_2*data[parent[now].first].cnt+2*data[parent[now].first].x*d.x;

        data[parent[now].first].x_2+=d.x_2;
        data[parent[now].first].x+=d.x;
        data[parent[now].first].cnt+=d.cnt;

        indegree[parent[now].first]-=1;
        if(indegree[parent[now].first]==0) q.push(parent[now].first);
    }
    cout<<answer;

    return 0;
}