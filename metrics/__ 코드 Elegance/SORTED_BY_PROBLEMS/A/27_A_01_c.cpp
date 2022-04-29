#include<stdio.h>
using namespace std;
int a,i,j,k,ch,A[1004];
int main()
{
    scanf("%d",&a);
    A[0]=1;A[1]=1;
    for(i=2;i<=a;i++)
    {
        for(k=1;1;k++)
        {
        ch=0;
            for(j=1;i-2*j>=0;j++)
            {
                if(k-A[i-j]==A[i-j]-A[i-2*j]){ch=1;break;}
            }
            if(ch==0)
            {
            A[i]=k;
                break;
            }
        }

    }
    printf("%d",A[a]);
}
