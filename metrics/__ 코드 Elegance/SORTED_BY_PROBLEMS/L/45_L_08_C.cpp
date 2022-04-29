#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n;
int s[101];
pair<int,pair<int,int>> a[10001];
int tree[1000001];

void update(int node,int x,int y,int i,int val){
    if(x > i  || y < i)return;
    if(x == y){
        tree[node] = max(tree[node],val);
    }else{
        int mid = (x + y)/2;
        update(node *2 , x , mid , i , val);
        update(node *2 +1, mid + 1 , y ,i , val);
        tree[node] =max(tree[node * 2 ] , tree[node * 2 + 1] );
    }
}

bool comp(pair<int,pair<int,int>> x,pair<int,pair<int,int>> y){
    return x.first < y.first;
}

int go(int node, int x,int y , int i,int j){
    if(x > j || y < i)return 0;
    if(i <= x && y <= j)return tree[node];
    int mid = (x + y) /2;
    return max(go(node * 2, x , mid , i ,j), go(node*2+1,mid+1,y,i,j));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
        a[i].second.second = (a[i].second.first - a[i].first) * s[a[i].second.second];
    }

    sort(a,a+n,comp);
    update(1,0,15000,a[0].second.first,a[0].second.second);

    int ans = a[0].second.second;

    for(int i=1;i<n;i++){
        int tmp = go(1,0,15000,0,a[i].first) + a[i].second.second;
        update(1,0,15000,a[i].second.first,tmp);
        ans = max(ans,tmp);
    }

    cout<<ans<<'\n';



}
