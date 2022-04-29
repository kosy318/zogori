#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[101];
map<pair<int,int>,int> d;
pair<int,pair<int,int>> b[10001];

bool comp(pair<int,pair<int,int>> x , pair<int,pair<int,int>> y){
    return x.first < y.first;
}

int go(int x,int y){ //
    if(x == n){
        return 0;
    }
    if(d[{x,y}] != 0)return d[{x,y}];

    d[{x,y}] = go(x+1,y);

    if(y <= b[x].first)
        d[{x,y}] = max(d[{x,y}] , go(x+1,b[x].second.first) + (b[x].second.first - b[x].first) * a[b[x].second.second] );

    return d[{x,y}];
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;

    for(int i=1;i<=m;i++){
    cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i].first>>b[i].second.first >> b[i].second.second;
    }

    sort(b,b+n,comp);
    cout<<go(0,0)<<'\n';



}
