#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;

int n;
int a[MAX+5];

int main(){
    a[4]=1;
    a[5]=2;
    cin>>n;
    for(int i=6; i<=n; ++i){
        a[i]=a[(i+1)/3+1]+a[(i+2)/3+1]+2;
    }
    cout<<a[n];
    return 0;
}
