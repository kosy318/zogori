#include <cstdio>
#include <vector>
using namespace std;
struct E {
    int v, w;
};
int N;
vector<E> alist[100001];
long long Qa[100001], Ra[100001];
int Ca[100001];

long long ffinal;

long long fQ(long long Q, long long R, int C, int w) {
    return Q + 1LL*C*w*w + 2*R*w;
}

long long fQ(int v, int w) {
    return fQ(Qa[v], Ra[v], Ca[v], w);
}

long long fR(long long R, int C, int w) {
    return R + 1LL*C*w;
}

long long fR(int v, int w) {
    return fR(Ra[v], Ca[v], w);
}

void preproc(int p, int u) {
    if(alist[u].size() == 1)  {
        Qa[u] = 0;
        Ra[u] = 0;
        Ca[u] = 1;
        return;
    }

    int i1 = 0, i2 = 1;
    if(alist[u][i1].v == p) {
        i1 = 2;
    }
    else if(alist[u][i2].v == p) {
        i2 = 2;
    }

    int beta1 = alist[u][i1].v, beta2 = alist[u][i2].v;
    preproc(u, beta1);
    preproc(u, beta2);
    long long weight1 = alist[u][i1].w, weight2 = alist[u][i2].w;
    Qa[u] = fQ(beta1, weight1) + fQ(beta2, weight2);
    Ra[u] = fR(beta1, weight1) + fR(beta2, weight2);
    Ca[u] = Ca[beta1] + Ca[beta2];
    return;
}

void go(int p, int u, long long Q, long long R, int C);

inline void go_sub(
        int u,
        int betaTar, int wTar, int betaX, int wX,
        long long Q, long long R, int C
) {
    long long Qp = Q + fQ(betaX, wX);
    long long Rp = R + fR(betaX, wX);
    int Cp = C + Ca[betaX];
    go(u, betaTar, fQ(Qp, Rp, Cp, wTar), fR(Rp, Cp, wTar), Cp);
}

void go(int p, int u, long long Q, long long R, int C) {
    if(alist[u].size() == 1) {
        // if u is leaf
        // int w= alist[u][0].w;
        // ffinal += fQ(Q, R, C, w);
        ffinal += Q;
        return ;
    }

    int i1 = 0, i2 = 1, ip = 2;
    if(alist[u][0].v == p) {
        i1 = 2;
        ip = 0;
    }
    else if(alist[u][1].v == p) {
        i2 = 2;
        ip = 1;
    }

    int beta1, beta2;
    int weight1, weight2;

    beta1 = alist[u][i1].v;
    weight1 = alist[u][i1].w;

    beta2 = alist[u][i2].v;
    weight2 = alist[u][i2].w;

    go_sub(u, beta1, weight1, beta2, weight2, Q, R, C);
    go_sub(u, beta2, weight2, beta1, weight1, Q, R, C);

}

int main() {
    int i;
    scanf("%d", &N);
    for(i=1; i<N; ++i) {
        int u, v,w;
        scanf("%d%d%d",&u,&v,&w);
        alist[u].push_back({v, w});
        alist[v].push_back({u, w});
    }
    // find an leaf node
    for(i=1; ; ++i) {
        if(alist[i].size() == 1) break;
    }
    int root = i; // this is technically leaf
    int bajiroot = alist[root][0].v;
    int bajiw = alist[root][0].w;
    preproc(root, bajiroot);

    ffinal = fQ(bajiroot, bajiw);

    go(root, bajiroot, bajiw*bajiw, bajiw, 1);

    printf("%lld", ffinal/2);

    return 0;
}