#include <stdio.h>

int x[10010],check[10010];
int main()
{
    int a;
    scanf("%d",&a);
    x[0] = 1;

    for(int i=1;i<=a;i++)
    {
        for(int j=0;j<=2000;j++) check[j] = 1;
        for(int k=1;2*k<=i;k++)
        {
            if(2*x[i-k]-x[i-2*k]>=0) check[2*x[i-k]-x[i-2*k]] = 0;
        }
        for(int j=1;j<=2000;j++)
        {
            if(check[j]==1)
            {
                x[i] = j;
                break;
            }
        }
    }
    printf("%d",x[a]);
}
