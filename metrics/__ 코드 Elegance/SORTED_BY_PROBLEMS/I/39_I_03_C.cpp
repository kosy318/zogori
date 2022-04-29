#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef pair<int,int> pii;
const int N = 100005;
const long long inf = 1e18;

int n;

pii a[N];

bool can (long long V) {
    long long C = -1e18;
    for(int i=1;i<=n;i++) {
        C = max(C, 1ll*a[i].X);
        if(C > a[i].X + a[i].Y) return false;
        C += V;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i].X,&a[i].Y);
    }
    sort(a+1, a+1+n);
    long long S = 0, E = inf;
    while(S<E) {
        long long M = (S+E)/2+1;
        can(M) ? S = M : E = M-1;
    }
    printf("%lld\n",S);
}
