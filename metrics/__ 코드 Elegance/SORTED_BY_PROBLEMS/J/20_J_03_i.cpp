#include<bits/stdc++.h>
int n;
int f(int t){
    int cnt=0;
    while(t!=1){
        cnt++;
        t=(t+1)/2;
    }
    return cnt;
}
int main(){
    scanf("%d",&n);
    printf("%d",f((n+2)/3)+f(n/3));
    return 0;
}
