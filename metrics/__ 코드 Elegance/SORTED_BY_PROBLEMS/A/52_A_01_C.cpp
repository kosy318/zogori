#include <bits/stdc++.h>

using namespace std;
int n, a[1010];
int main()
{
    scanf("%d",&n);
    a[0]=1; a[1]=1;
    int i,j,k;
    for(i=2;i<=n;i++) {
        set<int> st;
        for(k=1;i-2*k>=0;k++) {
        if(2*a[i-k]-a[i-2*k]<=0) continue;
            st.insert(2*a[i-k]-a[i-2*k]);

        }
        int cur=1;
        for(auto it=st.begin();it!=st.end();it++) {
            if(*it!=cur) break;
            cur++;
        }
        a[i]=cur;
        //printf("a[%d]:%d\n",i,a[i]);
    }
    printf("%d",a[n]);
    return 0;
}
