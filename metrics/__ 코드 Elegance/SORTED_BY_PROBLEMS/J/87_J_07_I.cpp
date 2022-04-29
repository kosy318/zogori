#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    int re[1000010]={0,};

    if (n == 3){
        re[3] = 0;
    }
    else if (n == 4) {
        re[4] = 1;
    } else if (n==5 || n==6){
        re[n] = 2;
    }
    else {
        //re[5]=2;
        int multi2 = 12;
        int nowre = 3;
        int cnt =0;
        for(int i=7; i<=n; i++){
            if(cnt==2){
                nowre+=1;
            }
            re[i]=nowre;
            cnt+=1;
            if(i==multi2){
                multi2*=2;
                nowre+=1;
                cnt=0;
            }
        }
    }
    printf("%d\n", re[n]);
    return 0;
}