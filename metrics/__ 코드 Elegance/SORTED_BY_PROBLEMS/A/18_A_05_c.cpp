#include <stdio.h>


int A[1001];
int main() {


    int n;
    bool bEnd = false;

    scanf("%d", &n);
    A[0] = 1;
    A[1] = 1;


    for(int i = 2; i < n+1; i++) {
    bEnd = false;
        for(int j = 1; !bEnd; j++) {
            A[i] = j;
            for(int k = 1; i - 2*k >= 0; k++) {
                if(A[i] - A[i-k] == A[i-k] - A[i-2*k]) {
                    bEnd = false;
                    break;
                }

            bEnd = true;

            }
        }


    }
    for(int i = 0; i < n+1; i++) {


    }
    printf("%d", A[n]);
    return 0;
}
