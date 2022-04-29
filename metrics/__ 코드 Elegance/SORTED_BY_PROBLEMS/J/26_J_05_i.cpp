#include <stdio.h>
using namespace std;

long long arr[1000005];
int main()
{
    arr[3] = 0;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 2;
    int n;
    scanf("%d", &n);
    if(n <= 6) printf("%lld\n", arr[n]);
    else {
        for(register int i = 7; i <= n; i++) {
            if((i&1) == 1) arr[i] = arr[i-1] + 1;
            else {
                arr[i] = arr[(i)/2] + 2;
            }
        }
    }
    printf("%lld\n", arr[n]);
    return 0;
}
