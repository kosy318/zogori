#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ans = 0, Vnum, VoutNum;
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
    ans = 2;
    n -= 2;
    while(n > Vnum){
        Vnum += 2, ans++;
        if(n <= Vnum) break;
        Vnum += (VoutNum * 2 - 2), ans++;
        VoutNum *= 3;
    }
    printf("%d", ans);
}
