#include <bits/stdc++.h>

using namespace std;

const int MX = 100010;

struct SuperInt{
    vector <int> v;

    SuperInt(){
    }

    SuperInt(int a){
        if(a == 0){
            v.push_back(0);
            return;
        }
        while(a != 0){
            v.push_back(a % 10);
            a /= 10;
        }
    }

    void Update(){
        for(int i = 0; i < v.size(); i++){
            if(v[i] >= 10){
                if(v.size() - 1 == i) v.push_back(0);
                v[i + 1] += v[i] / 10;
                v[i] %= 10;
            }
        }
    }

    void Print(){
        for(int i = v.size() - 1; i >= 0; i--) printf("%d", v[i]);
    }
};

SuperInt operator + (SuperInt a, SuperInt b){
    SuperInt re;
    int sz = max((int)a.v.size(), (int)b.v.size());
    for(int i = 0 ;i < sz; i++){
        int tmp = 0;
        if(i < a.v.size()) tmp += a.v[i];
        if(i < b.v.size()) tmp += b.v[i];
        re.v.push_back(tmp);
    }
    re.Update();
    return re;
}

SuperInt operator - (SuperInt a, SuperInt b){
    for(int i = 0; i < b.v.size(); i++){
        if(b.v[i] > a.v[i]){
            a.v[i] += 10;
            a.v[i + 1]--;
        }
        a.v[i] -= b.v[i];
    }

    while(a.v.size() > 0 && a.v[a.v.size() - 1] == 0){
        a.v.pop_back();
    }

    return a;
}

SuperInt operator * (SuperInt a, SuperInt b){
    SuperInt re;
    for(int i = 0; i < (int)a.v.size() + (int)b.v.size() - 1; i++){
        re.v.push_back(0);
    }
    for(int i = 0; i < a.v.size(); i++){
        for(int j = 0; j < b.v.size(); j++){
            re.v[i + j] += a.v[i] * b.v[j];
        }
    }
    re.Update();
    return re;
}

SuperInt div2(SuperInt a){
    SuperInt re;
    for(int i = 0; i < a.v.size(); i++) re.v.push_back(0);
    for(int i = a.v.size() - 1; i >= 0; i--){
        re.v[i] = a.v[i] / 2;
        if(i >= 1 && a.v[i] % 2 == 1) a.v[i - 1] += 10;
    }
    if(re.v.size() && re.v[re.v.size() - 1] == 0){
        re.v.pop_back();
    }
    return re;
}

int n, l, a, b;
vector <SuperInt> d1_tmp, d2_tmp;

struct Graph{

    int leafNum[MX] = {};
    int root;
    SuperInt d1[MX] = {};
    SuperInt d2[MX] = {};
    SuperInt ans[MX] = {};

    vector <pair<int, int> > child[MX];//child node

    vector <pair<int, int> > adj[MX];

    void AddEdge(int a, int b, int c){
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    void makeTree(){
        root = 0;
        for(int i = 1; i <= n; i++){
            if(adj[i].size() >= 2){
                root = i;
                break;
            }
        }

        queue <int> q;
        bool visited[MX] = {};
        q.push(root);
        visited[root] = true;

        while(!q.empty()){
            int pos = q.front();
            q.pop();

            for(int i = 0; i < adj[pos].size(); i++){
                int next = adj[pos][i].first;
                int cost = adj[pos][i].second;
                if(visited[next]) continue;
                child[pos].push_back(make_pair(next, cost));
                q.push(next);
                visited[next] = true;
            }
        }

        for(int i = 1; i <= n; i++){
            if(adj[i].size() == 1) leafNum[i] = 1;
        }
    }

    void calc(int n){
        for(int i = 0; i < child[n].size(); i++) calc(child[n][i].first);
        for(int i = 0; i < child[n].size(); i++) leafNum[n] += leafNum[child[n][i].first];
        for(int i = 0; i < child[n].size(); i++){
            int next = child[n][i].first;
            int cost = child[n][i].second;
            d1[n] = d1[n] + d1[next] + leafNum[next] * cost;
            d2[n] = d2[n] + leafNum[next] * cost * cost + 2 * cost * d1[next] + d2[next];
        }
    }

    void calAns(int n){
        for(int i = 0; i < child[n].size(); i++) calAns(child[n][i].first);
        for(int i = 0; i < child[n].size(); i++) ans[n] = ans[n] + ans[child[n][i].first];
        d1_tmp.clear();
        d2_tmp.clear();
        for(int i = 0; i < child[n].size(); i++){
            int next = child[n][i].first;
            int cost = child[n][i].second;
            d1_tmp.push_back(d1[next] + leafNum[next] * cost);
            d2_tmp.push_back(leafNum[next] * cost * cost + 2 * cost * d1[next] + d2[next]);
        }
        SuperInt d1_sum = SuperInt(0);
        for(int i = 0; i < d1_tmp.size(); i++) d1_sum = d1_sum + d1_tmp[i];
        for(int i = 0; i < d1_tmp.size(); i++){
            ans[n] = ans[n] + (leafNum[n] - leafNum[child[n][i].first]) * d2_tmp[i] + (d1_tmp[i] * (d1_sum - d1_tmp[i])); //
        }
    }
}graph;

int main(){
    int aads = d1_tmp.size();
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d %d", &a, &b, &l);
        graph.AddEdge(a, b, l);
    }

    graph.makeTree();
    graph.calc(graph.root);
    graph.calAns(graph.root);
    graph.ans[graph.root].Print();
}
