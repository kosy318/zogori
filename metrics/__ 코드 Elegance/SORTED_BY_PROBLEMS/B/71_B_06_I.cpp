#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long


using namespace std;


vector<vector<pair<int,int>>> t;
vector<int> leaf;
bool visited[100001] = {0};

int dfs(int pre, int idx, int dst)
{
    int result = 0;
    int size = t[idx].size();

    for (int i=0 ; i<size ; i++) {
        if (t[idx][i].first == pre)
            continue;

        if (t[idx][i].first == dst)
            return t[idx][i].second;
        else {
            int ret = dfs(idx, t[idx][i].first, dst);
            if (ret != 0)
                return ret + t[idx][i].second;
        }
    }
    return result;
}


int main() {
    int n;

    //freopen("../input", "rb", stdin);
    scanf("%d", &n);
    t.resize(n+1);

    for (int i=0 ; i<n-1 ; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        t[a].push_back(make_pair(b, l));
        t[b].push_back(make_pair(a, l));
    }

    for (int i=1 ; i<=n ; i++) {
        if (t[i].size() == 1)
            leaf.push_back(i);
    }

    int leafsize = leaf.size();
    /*
    for (int i=0 ; i<leafsize ; i++)
        printf(" %d", leaf[i]);*/
    long long int total = 0;
    for (int i=0 ; i<leafsize ; i++) {
        for (int j=i+1 ; j<leafsize ; j++) {
            int ret = dfs(0, leaf[i], leaf[j]);
            //printf("%d %d %d\n", leaf[i], leaf[j], ret);
            total += ret*ret;
        }
    }

    printf("%d", total);

    return 0;
}