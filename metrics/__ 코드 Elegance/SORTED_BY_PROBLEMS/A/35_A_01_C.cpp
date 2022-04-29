#include<cstdio>
int ary[1005] = {1, 1};
int func(int t){
    for(int num = 1; num < 1000; num++){
        bool chk = true;
        for(int k = 1; k*2 <= t; k++){
            if(num - ary[t-k] == ary[t-k]-ary[t-2*k]){
                chk = false;
                break;
            }
        }
        if(chk) return num;
    }
    return -1;
}
int main(){
    int n; scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        int rv = func(i);
        ary[i] = rv;
    }
    printf("%d", ary[n]);
    return 0;
}
