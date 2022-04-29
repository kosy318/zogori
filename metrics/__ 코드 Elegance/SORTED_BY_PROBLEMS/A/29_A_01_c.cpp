#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, A[MAX_N];
bool visited[MAX_N*2];

int main() {
    scanf("%d", &N);
    A[0]=A[1]=1;
    for (int i=2; i<=N; i++) {
        for (int j=1; j<MAX_N; j++) {
            bool flag = false;
            for (int k=1; i-2*k>=0; k++) {
                if (j-A[i-k] == A[i-k]-A[i-2*k]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                A[i]=j;
                break;
            }
        }
    }
    printf("%d\n", A[N]);

    return 0;
}