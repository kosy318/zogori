#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    if(n <= 3) printf("%d\n", 0);
    else printf("%d\n", (n - 1) / 2);
    return 0;
}