#include<cstdio>
using namespace std;
int i,j,k,l,m,n;
int f(int x){
    if(x==3) return 0;
    if(x==4) return 1;
    if(x%2==1) return 2+f((x+1)/2);
    return 2+f(x/2);
}
int main(){
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
