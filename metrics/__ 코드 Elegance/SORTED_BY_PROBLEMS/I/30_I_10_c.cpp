#include<cstdio>
#include<algorithm>
using namespace std;

struct line
{
    long long s, e;
}A[100005];
bool CMP1( line &p1, line &p2 )
{
    if( p1.s < p2.s ) return true;
    return false;
}
bool arrange(int N, long long x)
{
    long long now = A[0].s+x;
    for( int i=1; i<N; i++ ){
        if( A[i].e < now ) return false;
        if( A[i].s > now ){
            now=A[i].s+x;
            continue;
        }
        now+=x;
    }
    return true;
}
int main()
{
    int N;
    long long high=0, Answer = -1, low=-1;
    scanf("%d",&N);
    for( int i=0; i<N; i++ ){
        long long tmp;
        scanf("%lld %lld",&A[i].s, &tmp);
        A[i].e = A[i].s+tmp;
        high = max( high, A[i].e );
        if( low==-1 ) low = A[i].s;
        else low = min(low,A[i].s);
    }
    sort(A, A+N, CMP1);

    high = ((high-low)/(N-1)) + 1;
    low = 0;
    while(1){
        long long mid = (low+high)/2;
        bool can = arrange( N, mid );
        if( can ) Answer = max( Answer, mid );
        if( low>=high ) break;
        if( can ) low = mid+1;
        else high = mid-1;
    }
    printf("%lld",Answer);
    return 0;
}

/*
6
0 40
10 55
45 28
90 40
83 30
120 30
 */

/*
6
0 67
127 36
110 23
50 51
100 12
158 17
*/