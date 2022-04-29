#include <cstdio>
#include <vector>
using namespace std;
struct E {
    int s, ps;
};
int N, M;
long long dp[15000];
int p[101];
vector<E> byend[15000];
int main() {
    int i, j;
    scanf("%d %d", &M, &N);
    for(i=1; i<=M; ++i) {
        scanf("%d", &p[i]);
    }
    int bige = 0;
    for(i=0; i<N; ++i) {
        int s,e,t;
        scanf("%d%d%d", &s,&e,&t);
        byend[e].push_back({ s, (e-s)*p[t]});
        if(bige < e) bige = e;
    }
    for(i=1; i<=bige; ++i) {
        long long ff = 0;
        for(E elem : byend[i]) {
            int s = elem.s;
            int ps = elem.ps;
            long long v = elem.ps + dp[s];
            if(ff < v) ff = v;
        }
        dp[i] = dp[i-1];
        if(dp[i] < ff) dp[i] = ff;
    }
    printf("%d", dp[bige]);
    return 0;
}