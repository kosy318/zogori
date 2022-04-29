#include <bits/stdc++.h>
#include <cstring>
#define endl '\n'

using namespace std;
int A[1010];
int ar[1010];
int main(){

    int n;
    cin>>n;
    A[0]=1;
    A[1]=1;
    A[2]=2;

    for(int i = 3; i <= n ; ++i){
        memset(ar,0,sizeof(ar));
        for(int k = 1 ; i -2*k >= 0 ; ++k){

            int num = 2* A[i-k] - A[i-2*k];
            ar[num]= 1;
        }
        for(int idx = 1 ; idx <=n ; ++idx){
            if(ar[idx] == 0){
                A[i] = idx;
                break;
            }
        }
    }
    cout<<A[n];
    return 0;
}
