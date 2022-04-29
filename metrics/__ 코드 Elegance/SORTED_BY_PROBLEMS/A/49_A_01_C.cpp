#include <cstdio>
using namespace std;
int N, arr[1001];
bool chk[1001];
int main() {
    int i, j, k;
    scanf("%d", &N);
    arr[0] = arr[1] = 1;
    for(i=2; i<=N; ++i) {
        for(j=1; j<=N; ++j) {
            chk[j] = false;
        }
        for(k=1; i-2*k>=0; ++k) {
            int delta = arr[i-k] - arr[i-2*k];
            int next = arr[i-k] + delta;
            if(next > 0) {
                chk[next] = true;
            }
        }
        for(j=1; chk[j]; ++j);
        arr[i] = j;
    }
    printf("%d", arr[N]);
    return 0;
}