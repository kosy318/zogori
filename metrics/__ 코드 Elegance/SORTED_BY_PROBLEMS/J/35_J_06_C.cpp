#include <stdio.h>

int main(void){
    int n=0;
    scanf("%d", &n);
    int t = 0;
    if(n==3){
     printf("0");
     return 0;
    }
    if(n==4){
     printf("1");
     return 0;
    }
    while(n != 3 || n != 4){
        if(n%2 == 1) n++;
        n/=2;
        t+=2;
        if(n==3) break;
        if(n==4) {t+=1; break;}
    }
    printf("%d", t);

}


/*#include <stdio.h>
#define SIZE 1000
#define OSIZE 10000000
int tary[1000] = { 1,0};
int tary2[1000] = { 1,0};

int pivo(int n, int k, int* a1, int *a2);

int main(void)
{
    int n;
    int re;
    scanf("%d", &n);
    if( n == 3) {printf("0"); return 0;}
    pivo(n, 4, tary, tary2);
}
int pivo(int n, int k, int* a1, int *a2){
    int ary[SIZE] = {0};
    if(n == k){
        for(int i = SIZE - 1; i >= 0; i--){
            if(a1[i]) printf("%d", a1[i]);
        }
        return 0;
    }
    for(int i = 0; i < SIZE; i++){
        if(a1[i] == 0 && a2[i] == 0){
            break;
        }
        else{
            ary[i] += a1[i] + a2[i];
            ary[i + 1] += ary[i]/OSIZE;
            ary[i] %=  OSIZE;
        }
    }
    pivo(n, k + 1, a2, ary);
    return 0;
}
//here
*/


/*

    int ary[SIZE] = {0};
    if(n == k){
        for(int i = SIZE - 1; i >= 0; i--){
            if(a1[i]) printf("%d", a1[i]);
        }
    }
    for(int i = 0; i < SIZE; i++){
        if(a1[i] == 0 && a2[i] == 0){
            break;
        }
        else{
            ary[i] += a1[i] + a2[i];
            ary[i] %=  OSIZE;
            ary[i + 1] += ary[i]/OSIZE;
        }
    }
    pivo(n, k + 1, a2, ary);
*/
