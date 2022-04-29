#include <iostream>
#include <cstdio>
using namespace std;

int A[1005], n, V[1005];

int main(){
    scanf("%d",&n);

    A[0] = 1;
    A[1] = 1;

    for(int i=2;i<=n;i++){
        for(int k=1;k<=i/2;k++){
            int c = (2*A[i-k])-A[i-(2 * k)];
            if(c < 0 ) continue;
            V[c] = 1;
        }

        for(int j=1;j<=n;j++){
            if(V[j]==0) {
                A[i] = j;
                break;
            }
        }

        for(int j=1;j<=n;j++){
            V[j] = 0;
        }
    }

    printf("%d",A[n]);

    return 0;
}
