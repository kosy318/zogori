#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int x = 2;
    int cnt = 0;
    while(x < N){
        cnt++;
        x *= 2;
    }
    cnt = cnt*2-1;
    if(x*3/4 >= N) cnt--;
    printf("%d\n", cnt);
    return 0;
}
