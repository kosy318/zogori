#include <cstdio>

int d[3000006];

int main()
{
    int N; scanf("%d", &N);
    int st = 3, r = 1;
    while(st <= N){
        d[st] = d[st - 1];
        for(int i = 1; i <= r; i++)
            d[st + i] = d[st] + 1;
        for(int i = r + 1; i <= st; i++)
            d[st + i] = d[st] + 2;
        st = 2 * st;
        r = r * 2;
    }
    printf("%d\n", d[N]);

    return 0;
}