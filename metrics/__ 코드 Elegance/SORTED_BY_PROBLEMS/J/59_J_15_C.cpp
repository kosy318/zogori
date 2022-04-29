#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000005];

int main()
{
    scanf("%d",&n);
    a[3]=0, a[4]=1;
    int idx=4, nxt, val=2, cnt=2;
    while(idx<=n){
        nxt=idx+val;
        for(int i=idx+1 ; i<=min(n,nxt) ; i++) a[i]=cnt;
        cnt++;
        if(cnt%2==0) val*=2;
        idx=nxt;
    }
    printf("%d",a[n]);
    return 0;
}
