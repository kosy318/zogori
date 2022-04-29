#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A[2002];
int chk[2002];
int main()
{
    int n;
    scanf("%d", &n);
    A[0] = A[1] = 1;
    for(int i=2;i<=n;i++) {
	memset(chk, 0, sizeof(chk));
        for(int k=1;i-2*k>=0;k++) {
            int add = (A[i-k]-A[i-2*k]);
            int nxt = A[i-k]+add;

            if(nxt>2000) continue;
            chk[nxt] = true;
        }

        for(int j=1;j<=2000;j++){
            if(!chk[j]) {
                A[i] = j;break;
            }
        }
    }
    printf("%lld", A[n]);

    return 0;
}
