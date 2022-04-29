#include <stdio.h>

int A[1001];
bool chk[1001][1001];

int main()
{
    int n, i, j, k;

    scanf("%d", &n);

    A[0] = A[1] = 1;
    chk[2][1] = true;
    for(i=2;i<=n;i++){
        for(j=1;chk[i][j];j++);
        A[i] = j;

        for(k=1;k<=i;k++){
            if(i+k > 1000) break;
            int x = A[i]+(A[i]-A[i-k]);

            if(x <= 0 || x >1000) continue;
            chk[i+k][x] = true;
        }
    }

    printf("%d", A[n]);

    return 0;
}
