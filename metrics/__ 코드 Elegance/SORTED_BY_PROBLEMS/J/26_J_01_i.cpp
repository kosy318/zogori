#include <stdio.h>
using namespace std;

int arr[1000005];
int main()
{
    arr[3] = 0;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 2;

    for(register int i = 6; i <= 1000000; i +=4) {
        arr[i+1] = arr[i] + 1;
        arr[i+2] = arr[i] + 2;
        arr[i+3] = arr[i] + 3;
        arr[i+4] = arr[i] + 3;
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", arr[n]);
    return 0;
}
