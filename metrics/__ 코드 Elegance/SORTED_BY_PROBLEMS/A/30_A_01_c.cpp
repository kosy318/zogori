
#include <cstdio>
#include <algorithm>
using namespace std;
int N, A[1005];
int main() {
    A[0] = 1;
    A[1] = 1;
    scanf("%d",&N);
    if( N<2 ){ printf("1"); return 0; }

    for( int i=2; i<=N; i++ ){
        int val = 0;
        while( ++val ) {
            bool can = true;
            for (int j = 1; j; j++) {
                bool nowcan = false;
                if ( i - (j*2) < 0 ) break;
                int x = i - j;
                int dist = val - A[x];
                if( val-A[x] != A[x]-A[x-j] ){
                    nowcan = true;
                }
                if (nowcan == false) {
                    can = false;
                    break;
                }
            }
            if( can ){
                A[i] = val;
                break;
            }
        }
    }

    printf("%d",A[N]);
    return 0;
}