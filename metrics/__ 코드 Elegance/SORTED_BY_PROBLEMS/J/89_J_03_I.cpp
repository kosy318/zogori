#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n==3) printf("0");
    else if(n==4) printf("1");
    else printf("%lld", 1LL*(n-3)*(n-2)/2-n+2);

    return 0;
}
