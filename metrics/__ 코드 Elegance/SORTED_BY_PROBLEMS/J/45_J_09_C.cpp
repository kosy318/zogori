#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long d[1000001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    d[3]=0;
    d[4]=1;
    d[5]=2;
    d[6]=2;
    int n;
    cin>>n;
    for(int i=7;i<=n;i++){
        int i2=i/2;
        d[i]=d[i-i2]+2;
    }
    cout<<d[n]<<'\n';



}
