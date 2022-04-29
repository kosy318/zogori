#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int check(int x, int now){
    for(int k=1; ; k++){
        if(x-2*k < 0) break;

        int l = arr[x-2*k];
        int m = arr[x-k];
        int r = now;

//        printf("x : %d / now : %d / %d %d %d\n", x, now, l, m, r);
        if(m-l == r-m) return 0;
    }
    return 1;
}
void build(int n){
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<=n; i++){
        for(int now=1; now<=1000; now++){
                if(check(i, now)){
                    arr[i] = now;
                    break;
                }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    build(n);
    printf("%d\n", arr[n]);
    return 0;
}
