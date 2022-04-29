#include <stdio.h>
using namespace std;

int arr[1000005];
int main()
{
    arr[3] = 0;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 2;
    arr[7] = 3;

    int n;
    scanf("%d", &n);
    if(n <= 7) printf("%d\n", arr[n]);
    else {
        for(register int i = 8; i <= n; i++) {
            if((i&1) == 1) arr[i] = arr[i-1] + 1;
            else {
                arr[i] = 2*arr[(i+2)/2];
            }
        }
    }
    printf("%d\n", arr[n]);
    return 0;
}
