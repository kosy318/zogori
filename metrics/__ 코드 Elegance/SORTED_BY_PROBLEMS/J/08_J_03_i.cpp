#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,ans;
int main(){
    scanf("%lld",&a);
    if(a == 3){
        ans = 0;
    }
    else{
        ans = (a-1)/2;
    }
    printf("%lld",ans);
}
