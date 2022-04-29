#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int N = 1005;
const long long inf = 9e18;

int n, ord[N], inv[N];

long long ans;

long long mn = inf, c1, c2;

pii a[N];

vector<pii> v;

long long ccw (pii &A, pii &B) {
    long long V = 1ll * A.X * B.Y - 1ll * A.Y * B.X;
    return V;
}

long long ccw (pii &A, pii &B, pii &C) {
    long long V = (1ll*A.X*B.Y+1ll*B.X*C.Y+1ll*C.X*A.Y) - (1ll*A.Y*B.X+1ll*B.Y*C.X+1ll*C.Y*A.X);
    return V;
}

void solve (pii &A, pii &B, pii &C, pii &D) {
    long long area = abs(ccw(A, B, C)) + abs(ccw(A, B, D));
    if(mn > area) {
        mn = area;
        c1 = 0;
        c2 = 0;
    }
    if(mn == area) {
        if((ccw(C, D, A) < 0 ? -1 : 1) * (ccw(C, D, B) < 0 ? -1 : 1) < 0) c1++;
        else c2++;
    }
}

void Swap (int A, int B) {
    swap(inv[A], inv[B]);
    ord[inv[A]] = A;
    ord[inv[B]] = B;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i].X,&a[i].Y);
    }
    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            v.push_back({i, j});
        }
    }
    sort(v.begin(), v.end(), [&] (pii A, pii B) {
        pii vA = {a[A.Y].X - a[A.X].X, a[A.Y].Y - a[A.X].Y};
        pii vB = {a[B.Y].X - a[B.X].X, a[B.Y].Y - a[B.X].Y};
        return ccw(vA, vB) < 0;
    });
    for(int i=1;i<=n;i++) {
        ord[i] = i;
        inv[i] = i;
    }
    for(auto &T : v) {
        int A, B;
        tie(A, B) = T;
        int iA = inv[A], iB = inv[B];
        assert(abs(iA - iB) == 1);
        if(iA > iB) swap(iA, iB);
        ans += (iA-1) * (n-iB);
        for(int i=max(1, iA-2); i<iA; i++) {
            for(int j=iB+1; j<=min(n,iB+2); j++) {
                solve(a[ord[iA]], a[ord[iB]], a[ord[i]], a[ord[j]]);
            }
        }
        Swap(A, B);
    }
    ans += c1 + 2*c2;
    printf("%lld\n", ans);
}
