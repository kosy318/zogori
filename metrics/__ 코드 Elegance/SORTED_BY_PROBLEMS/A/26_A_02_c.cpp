#include <stdio.h>

int arr[1005];

int main()
{
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 1;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 2;
    arr[7] = 4;
    arr[8] = 4;

    int n;
    scanf("%d", &n);
    if(n <= 8) printf("%d\n", arr[n]);
    else {
        for(register int i = 9; i <= n; i++) {
            while(1)
            {
                bool flag = true;
                arr[i]++;
                for(register int j = 1; i - (2*j) >= 0; j++) {
                    if((arr[i] - arr[i-j]) == (arr[i-j] - arr[i - (2*j)])) {
                        flag = false;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        printf("%d\n", arr[n]);
    }
    return 0;
}
