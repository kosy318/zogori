#include <cstdio>

int d[1000006];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 3; i <= N; i++){
          d[i + 1] = d[i] + 1;
          for(int j = i + 2; j <= N && j <= 2 * i; j++)
              d[j] = d[i] + 2;
          i = 2 * i - 1;
    }

    printf("%d\n", d[N]);

    return 0;
}