#include<bits/stdc++.h>
using namespace std;
int a,i,j,ch;
long long p,q,h,m;

struct A{
    long long x,l;
}dat[100003];
bool cmp(A aa,A bb){return aa.x<bb.x;}

int main()
{
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%lld%lld",&dat[i].x,&dat[i].l);
    }
    sort(dat,dat+a,cmp);

    p=0;
    q=1e9;q*=2;q++;
    while(p!=q-1)
    {
        h=(p+q)/2;

        ch=0;
        m=dat[0].x+h;
        for(i=1;i<a;i++)
        {
           if(m>dat[i].x+dat[i].l)
           {
            ch=1;
                break;
           }
           else
           {
                m=max(m,dat[i].x);
                m+=h;
           }
        }
        if(ch)q=h;
        else p=h;
    }
    printf("%lld",p);
}
/*
6
0 40
10 55
45 28
90 40
83 30
120 30

3
0 20
40 10
100 20
*/

