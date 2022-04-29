#include <bits/stdc++.h>
using namespace std;

int n;
int table[20000010];

int main(){
    int i, a = 4, s = 5, d = 6, na = 1, ns = 2, nd = 2;
    scanf("%d", &n);
    table[4] = 1, table[5] = 2, table[6] = 2;
    while(a <= n){
        table[a] = na;
        for(i = a + 1; i < s; i++) table[i] = na + 1;
        for(i = s; i <= d; i++) table[i] = ns;
        a *= 2;
        for(i = d + 1; i <= a; i++) table[i] = nd + 1;
        s *= 2;
        d *= 2;
        na += 2, ns += 2, nd += 2;
    }
    printf("%d", table[n]);
    return 0;
}
