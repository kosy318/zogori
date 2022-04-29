#include <stdio.h>
int a[1010][1010];
int b[1010];
int n;
int main(void)
{
    scanf("%d",&n);
    if(n<2)printf("1\n");
    else
    {
        b[0]=b[1]=1;
        a[2][1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;;j++)
            {
                if(a[i][j]==0)
                {
                    b[i]=j;
                    break;
                }
            }
            for(int j=0;j<i;j++)
            {
                if(2*i-j<0||2*i-j>n)continue;
                if(2*b[i]-b[j]<0||2*b[i]-b[j]>1000)continue;
                a[2*i-j][2*b[i]-b[j]]=1;
            }
        }
        printf("%d\n",b[n]);
    }
}
