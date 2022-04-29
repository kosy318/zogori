#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

int ans(int n)
{
    if (n == 3) return 0;
    if (n == 4) return 1;
    if (n == 5) return 2;

    return ans((n+1)/2)+2;
}


int main(void){

    int n;
    scanf("%d", &n);

    printf("%d\n", ans(n));

}