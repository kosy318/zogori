#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if(n == 3)
        printf("0\n");
    else if(n == 4)
        printf("1\n");
    else
        printf("%d\n", (n - 1) / 2);
}