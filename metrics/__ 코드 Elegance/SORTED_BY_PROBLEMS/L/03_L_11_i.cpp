#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visit[10001];
int m, n;
int result = 0;
int num = 0;
int type[101];
int price[10001];
vector<pair<pair<int, int>, int> > v;

int DFS(int s, int e, int w, int t)
{
    int r = w;
    for(int i=t; i<n; ++i){
        if(v[i].first.first >= e){
            visit[i] = true;
            r = max(r, DFS(v[i].first.first, v[i].first.second, w + v[i].second, i));
        }
    }

    return r;
}

int main(int argc, char *argv[])
{

    scanf("%d", &m);
    scanf("%d", &n);

    for(int i=1; i<=m; ++i){
        scanf("%d", &type[i]);
    }

    for(int i=0; i<n; ++i){
        int a, b, c;

        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        v.push_back(make_pair(make_pair(a, b),(b-a) * type[c]));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i<n; ++i){
        if(!visit[i]){
            result = max(result, DFS(v[i].first.first, v[i].first.second, v[i].second, i));
        }
    }

    printf("%d\n", result);

    return 0;
}
