#include<cstdio>
#include<algorithm>
using namespace std;

struct coord
{
    int x, y;
}S[1005],B[1005];
bool CMP1( coord &p1, coord &p2 )
{
    if( p1.x < p2.x ) return true;
    if( p1.x > p2.x ) return false;
    return p1.y < p2.y;
}
int main()
{
    int N, M, Answer, c1, c2;
    scanf("%d",&N);
    for( int i=0; i<N; i++ ) scanf("%d%d",&S[i].x,&S[i].y);
    scanf("%d",&M);
    for( int i=0; i<M; i++ ) scanf("%d%d",&B[i].x,&B[i].y);
    scanf("%d%d",&c1,&c2);
    Answer = c1;

    sort( S, S+N, CMP1 );
    sort( B, B+M, CMP1 );

    for( int i=0; i<N; i++ ){
        for( int j=i+1; j<N; j++ ){
            int cnt1=2, cnt2=0, tmp;
            if( S[i].y > S[j].y ){
                for( int k=0; k<N; k++ ){
                    if( k==i || k==j ) continue;
                    if( S[k].x > S[j].x || S[k].x < S[i].x ) continue;
                    if( S[k].y < S[j].y || S[k].y > S[i].y ) continue;
                    cnt1++;
                }
                for( int k=0; k<M; k++ ) {
                    if (B[k].x > S[j].x || B[k].x < S[i].x) continue;
                    if (B[k].y < S[j].y || B[k].y > S[i].y) continue;
                    cnt2++;
                }
                tmp = c1*cnt1 - c2*cnt2;
            }
            if( S[i].y <= S[j].y ){
                for( int k=0; k<N; k++ ){
                    if( k==i || k==j ) continue;
                    if( S[k].x > S[j].x || S[k].x < S[i].x ) continue;
                    if( S[k].y < S[i].y || S[k].y > S[j].y ) continue;
                    cnt1++;
                }
                for( int k=0; k<M; k++ ) {
                    if (B[k].x > S[j].x || B[k].x < S[i].x) continue;
                    if (B[k].y < S[i].y || B[k].y > S[j].y) continue;
                    cnt2++;
                }
                tmp = c1*cnt1 - c2*cnt2;
            }
            Answer = max( Answer, tmp );
        }
    }
    printf("%d",Answer);
    return 0;
}

/*
3
0 5
3 3
8 -1
3
1 4
6 0
7 1
3 2
 */




/*
2
-1 -1
4 4
2
0 0
2 2
5 2
 */