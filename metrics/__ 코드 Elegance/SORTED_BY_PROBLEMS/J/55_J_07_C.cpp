#include <stdio.h>

int main()
{
    int n, i, x;

    scanf("%d", &n);

    x = 2;
    for(i=0;true;i++){
        x += 1<<(i/2);
        if(n <= x) break;
    }

    printf("%d", i);

    return 0;
}
