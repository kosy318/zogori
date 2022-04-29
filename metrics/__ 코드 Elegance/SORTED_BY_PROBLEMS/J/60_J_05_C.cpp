#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0, tmp, Vnum, VoutNum;
    scanf("%d", &n);
    if(n == 3){
        printf("0");
        return 0;
    }else if(n == 4){
        printf("1");
        return 0;
    }else if(n <= 6){
        printf("2");
        return 0;
    }
    Vnum = 4;
    VoutNum = 3;
    tmp = 2;
    ans = 2;
    n -= 2;
    while(n > Vnum){
        Vnum += tmp, ans++;
        if(n <= Vnum) break;
        Vnum += (VoutNum * 2 - tmp), ans++;
        VoutNum *= 2;
        tmp *= 2;
    }
    printf("%d", ans);
}
