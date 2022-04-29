#include<bits/stdc++.h>
using namespace std;

int n;
int a[1005]={1,1};

int main(){
    cin>>n;
    for(int i=2; i<=n; ++i){
        for(int j=1;; ++j){
            bool flag=true;
            for(int k=1; 2*k<=i; ++k){
                if(j-a[i-k]==a[i-k]-a[i-2*k]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                a[i]=j;
                break;
            }
        }
    }
    cout<<a[n];
    return 0;
}
