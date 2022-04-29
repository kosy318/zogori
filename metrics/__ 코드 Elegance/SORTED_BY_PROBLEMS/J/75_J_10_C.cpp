#include <bits/stdc++.h>
using namespace std;

int N, Q[1000005];

int main(){
    scanf("%d",&N);
    for(int i=0;;i++){
        int cmp;
        if(i%2) cmp=(1<<(i/2+2));
        else cmp=(1<<(i/2))*3;
        if(N<=cmp){
            printf("%d\n", i);
            return 0;
        }
    }

}

/*
int N, D[1000005];


int main() {
    scanf("%d", &N);
    if(N == 4) return !printf("%d\n", 1);
    if(N == 3) return !printf("%d\n", 0);
    D[4] = 1;
    for(int i=7; i<=N; i++) {
        int a = (i - 3) / 2 + 2;
        int b = i - a + 1;
        D[i] = max(D[a], D[b]) + 1;
    }
    int a = (N + 3) / 3;
    int b = (N + 3 - a) / 2;
    int c = (N + 3 - a - b);
    int A = D[a];
    int B = D[b];
    int C = D[c];

    printf("%d\n", A + B + C - min({A, B, C}) + 2);
}
*/
