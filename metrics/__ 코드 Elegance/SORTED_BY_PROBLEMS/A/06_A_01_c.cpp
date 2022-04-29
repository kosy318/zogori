#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    a[0] = 1;
    a[1] = 1;
    for(int i=1;i<=n;i++){
        int check[4005]={0};

        for(int k=1;i-2*k>=0;k++){
            int s=a[i-2*k]+(a[i-k]-a[i-2*k])*2;
            if(s>0)check[s]=1;
        }
        for(int j=1 ;  ; j++){
            if(check[j]==0){
                a[i]=j;
                break;
            }
        }
    }
    cout<<a[n];
    return 0;
}