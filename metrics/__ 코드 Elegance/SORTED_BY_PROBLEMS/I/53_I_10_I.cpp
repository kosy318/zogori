#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
struct abc
{
int s;
int l;
};
abc A[100050];
int sortf(abc x, abc y)
{
    return(x.s<y.s);
}


int check(int x)
{
    int k=-1;// last
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(k==-1 || k+x<=A[i].s)
        {
            k=A[i].s;
        }
        else if(k+x<=A[i].s+A[i].l)
        {
            k=k+x;
        }
        else
        {
            //bullganung
            flag=1;
            break;
        }
    }
    return flag;
}
int half(int f,int b)
{
    int middle= (f+b)/2;
    if(f==b)
    {
        return f;
    }
    if(f+1==b)
    {
        if(check(b))return f;
        else return b;
    }
    if(check(middle)) // middle bullganung
    {
        half(f,middle-1);
    }
    else
    {
        half(middle,b);
    }
}
int main()
{
    long long int startp=2000000000;
    long long int endp=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&A[i].s,&A[i].l);
        if(A[i].s < startp)
        {
            startp=A[i].s;
        }
        if(A[i].s+A[i].l > endp)
        {
            endp=A[i].s+A[i].l;
        }
    }
    sort(A,A+n,sortf);
    int length = (endp-startp)/(n-1) +1;
    printf("%d",half(0,length));
    return 0;
}
