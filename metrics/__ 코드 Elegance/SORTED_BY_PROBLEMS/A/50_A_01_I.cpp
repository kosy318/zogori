#include <iostream>
#include <cstdio>
using namespace std;

int A[1005], n, V[1005];

int main(){
    scanf("%d",&n);

    A[0] = 1;
    A[1] = 1;

    for(int i=2;i<=1000;i++){
        for(int k=1;k<=i/2;k++){
            V[(2*A[i-k])-A[i-(2 * k)]] = 1;
        }

        bool flag = 0;
        for(int j=1;j<=1000;j++){
            if(V[j]==0 && flag==0) {
                flag = 1;
                A[i] = j;
            }
            V[j] = 0;
        }
    }

    printf("%d",A[n]);

    return 0;
}
