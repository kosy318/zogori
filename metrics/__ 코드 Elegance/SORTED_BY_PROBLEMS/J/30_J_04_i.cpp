#include<cstdio>
#include<algorithm>
using namespace std;

int D[10];

int Cal( int x )
{
    if( x==3 || x==4 || x==5 ) return 2;
    if( x%2 ) return 1 + max( Cal(x/2), Cal((x+1)/2) );
    return 1 + Cal(x/2);
}

int Tri( int x )
{
    int t1 = x/3, t2 = x/3;
    if( x%3 ) t2++;
    if( x%3 == 2 ) t1++;

    return Cal(t1)+Cal(t2);

}
int main()
{
    int N;
    scanf("%d",&N);
    D[3] = 0, D[4] = 1, D[5] = 2, D[6] = 2, D[7] = 3;
    for( int i=8; i<=12; i++ ) D[i] = 4;
    for( int i=13; i<=14; i++ ) D[i] = 5;
    for( int i=15; i<=18; i++ ) D[i] = 6;
    if( N<19 ){ printf("%d",D[N]); return 0; }

    int Answer = Tri(N);


    printf("%d",Answer);
    return 0;
}