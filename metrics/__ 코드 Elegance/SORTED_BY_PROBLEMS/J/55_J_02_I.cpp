#include<stdio.h>
typedef long long int ll;
#define N 100000
ll d[N*3];
ll max(ll a, ll b){
    return a>b?a:b;
}
int main(){
    ll n;
    int i;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&n);
    d[0]=3;
    d[1]=4;
    d[2]=6;
    d[3]=7;
    for(i=0;i<=N;i++){
        d[i+1]=max(d[i+1], d[i]+1);
        d[2*i+2]=max(d[i*2+2], d[i]*3-3);
        d[2*i+3]=max(d[2*i+3], d[i]*2+d[i+1]-3);
    }
    for(i=0;i<=N;i++){
        if(n<=d[i]){
            printf("%d",i);
            break;
        }
    }
}
