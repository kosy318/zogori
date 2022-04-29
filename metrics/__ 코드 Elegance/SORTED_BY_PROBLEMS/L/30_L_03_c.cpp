#include<cstdio>
#include<algorithm>
using namespace std;

int cost[105];
int D[15005][2];

struct product{
    int s, e, k, w;
}P[10005];
bool CMP1( product &p1, product &p2 )
{
    if( p1.s < p2.s ) return true;
    if( p1.s > p2.s ) return false;
    return p1.e<=p2.e;
}

int main()
{
    int N, M, Answer = 0;
    scanf("%d%d",&N,&M);
    for( int i=1; i<=N; i++ ) scanf("%d",&cost[i]);
    for( int i=1; i<=M; i++ ){
        scanf("%d%d%d",&P[i].s, &P[i].e, &P[i].k);
        P[i].w = (P[i].e-P[i].s)*cost[P[i].k];
    }
    sort( P+1, P+M+1, CMP1 );

    for( int i=1; i<=M; i++ ){
        D[i][0] = P[i].w;
        D[i][1] = P[i].e;

        for( int j=1; j<i; j++ ){
            if( D[j][1] <= P[i].s ) D[i][0] = max( D[i][0], D[j][0]+P[i].w );

        }

        Answer = max( Answer, D[i][0] );
    }
    printf("%d",Answer);
    return 0;
}