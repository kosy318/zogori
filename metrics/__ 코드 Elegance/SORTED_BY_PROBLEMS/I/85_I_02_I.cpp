#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > line;
int dot[101010];

int solve(int x){
    dot[0] = line[0].first;
    for(int i=1; i<line.size(); i++){
        dot[i] = max(dot[i-1]+x, line[i].first);
        if(line[i].first + line[i].second < dot[i]) return 0;
    }
    return 1;
}
int binary_search(int x, int y){
    int lo = x-1;
    int hi = y+1;
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        if(solve(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x, len;
        scanf("%d %d", &x, &len);
        line.push_back({x, len});
    }
    sort(line.begin(), line.end());
    printf("%d\n", binary_search(0, (int)1e9));
    return 0;
}
