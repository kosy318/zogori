#include <bits/stdc++.h>
using namespace std;

int n;
int table[1000010];

int main(){
    int i;
    scanf("%d", &n);
    table[4] = 1, table[5] = 2, table[6] = 2;
    for(i = 7; i <= n; i++){
        if(i % 2) table[i] = table[i - 1] + 1;
        else table[i] = table[i / 2] + 2;
    }
    printf("%d", table[n]);
    return 0;
}
