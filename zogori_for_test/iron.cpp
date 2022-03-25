#include <bits/stdc++.h>
using namespace std;

int visit[26] = {0,};
int graph[26][26] = {0,};
int max_ans = 0;
string ans = "";
string path = "";
vector<int> vec = {};

void dfs(int cur, int cost) {
    if(graph[cur][0] > 0 && cost + graph[cur][0] > max_ans) {
        max_ans = cost + graph[cur][0];
        path.push_back('a' + cur);
        ans = path;
        path.pop_back();
    }
    else if(graph[cur][0] > 0 && cost + graph[cur][0] == max_ans) {
        path.push_back('a' + cur);
        string temp = path;
        if(ans.length() < temp.length()) {
            ans = temp;
        }
        else if(ans.length() == temp.length() && ans.compare(temp) > 0) {
            ans = temp;
        }
        path.pop_back();
    }
    path.push_back('a' + cur);
    for(int i=0; i<26; i++) {
        if(graph[cur][i] > 0 && visit[i] == 0) {
            visit[i] = 1;
            dfs(i,cost+graph[cur][i]);
            visit[i] = 0;
        }
    }
    path.pop_back();
}
int main() {
    int N,M;
    ifstream in("iron.inp");    // iorn.inp
    ofstream out("iron.out");
    in >> N >> M;
    
    for(int i=0; i<M; i++) {
        char u,v;
        int w;
        in >> u >> v >> w;
        u -= 'a';
        v -= 'a';
        graph[u][v] = w;
        graph[v][u] = w;
    }

    /*
        testing comment
    */




    visit[0] = 1;
    dfs(0, 0);
    
    out << max_ans << "\n";
    for(auto v : ans) {
        out << v << " ";
    }
    
    in.close();
    out.close();
    
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// a b c d e f g h i j  k  l  m  n