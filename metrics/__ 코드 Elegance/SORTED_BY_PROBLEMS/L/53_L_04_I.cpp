#include <stdio.h>
#include <algorithm>
using namespace std;
struct abc
{
int s;
int e;
int t;
};
int sortf(abc x,abc y)
{
    return (x.s<y.s ||(x.s==y.s && x.e < y.e));
}
int table[10050]={0,};
int main()
{
    int m,n;
    int M[150];
    abc N[10050];
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&M[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&N[i].s,&N[i].e,&N[i].t);
    }
    sort(N,N+n,sortf);
    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(N[j].e<=N[i].s && table[i]<table[j])
            {
                table[i]=table[j];
            }
        }
        table[i]+=(N[i].e-N[i].s)*M[N[i].t];
        if(table[i]>answer)answer=table[i];

    printf("%d\n",table[i]);
    }
    printf("%d",answer);
    return 0;
}
/*
2 5
2
3
2 5 1
4 5 2
4 6 1
7 11 2
6 10 1
*/
