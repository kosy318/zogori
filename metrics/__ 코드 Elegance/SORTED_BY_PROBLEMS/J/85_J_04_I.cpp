#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d", &n);

    if(n==3)
        printf("0");
    else
    {
        if(n%2 == 0)
            n-=2;
        else
            n-=1;
        n/=2;
        printf("%d\n",n);
    }
    return 0;
}
