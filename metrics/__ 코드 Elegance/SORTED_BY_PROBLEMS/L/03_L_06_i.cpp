#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int result = 0;
int type[101];
int price[10001];
vector<pair<int, int> > v;

int DFS(int s, int e, int w)
{
    int r = w;
    for(int i=0; i<n; ++i){
        if(v[i].first >= e){
            r = max(r, DFS(v[i].first, v[i].second, w + price[i]));
        }
    }

    return r;
}

int main(int argc, char *argv[])
{

    cin >> m >> n;

    for(int i=1; i<=m; ++i){
        cin >> type[i];
    }

    for(int i=0; i<n; ++i){
        int a, b, c;

        cin >> a >> b >> c;

        v.push_back(make_pair(a, b));
        price[i] = (b - a) * type[c];
    }

    for(int i = 0; i<n; ++i){
        result = max(result, DFS(v[i].first, v[i].second, price[i]));
    }

    cout << result << endl;

    return 0;
}
