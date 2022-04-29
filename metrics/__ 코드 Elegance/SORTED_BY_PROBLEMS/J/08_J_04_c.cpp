#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005],n;
ll solve(ll x){
    if(x == 3){
        return 0;
    }
    else if(x == 4){
        return 1;
    }
    if(x%2 == 0){
        return solve(x/2)+2;
    }
    else{
        return solve((x+1)/2)+2;
    }
}
int main(){
    scanf("%lld",&n);
    printf("%lld",solve(n));
}
