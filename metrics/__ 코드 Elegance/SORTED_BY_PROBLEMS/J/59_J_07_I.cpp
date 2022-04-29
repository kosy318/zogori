#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;

int n;
int a[MAX+5];
int b[MAX+5];
int main(){
    a[4]=1;
    a[5]=2;
    b[4]=1;
    b[5]=1;
    cin>>n;
    for(int i=6; i<=n; ++i){
        a[i]=b[(i+1)/3+1]+b[(i+2)/3+1]+2;
        b[i]=a[i];
        if((i+1)%3==0) b[i]--;
    }
    cout<<a[n];
    return 0;
}
