#include <bits/stdc++.h>
using namespace std;
long long d[1000001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    d[3] = 0;
    d[4] = 1;
    d[5] = 1;
    for(int i=6;i<=n;i++){
        d[i] = min(d[i-1],d[i-2]) + 1;
    }
    cout<<d[n]<<'\n';
}
