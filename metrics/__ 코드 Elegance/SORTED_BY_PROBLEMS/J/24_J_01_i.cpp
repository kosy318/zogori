#include <iostream>

using namespace std;
int n, ans = 1;
int main()
{
    scanf("%d", &n);
    if (n == 3) puts("0");
    else if (n == 4) puts("1");
    else {
        for (int i = 5; i <= n; i++)
            if (i & 1) ans++;
        printf("%d", ans);
    }
    return 0;
}

