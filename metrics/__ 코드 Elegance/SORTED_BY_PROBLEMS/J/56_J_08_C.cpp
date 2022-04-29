#include<bits/stdc++.h>
using namespace std;
long long arr[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    arr[4]= 1;
    int n;
    cin>>n;
    for(int i = 5; i<=n;i++){
        arr[i] = arr[i-i/2]+2;
    }
    cout<<arr[n];
}
