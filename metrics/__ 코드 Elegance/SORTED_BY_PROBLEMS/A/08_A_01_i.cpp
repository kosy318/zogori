#include<bits/stdc++.h>
using namespace std;


int a,b,c,d,e;
int o[1111];
int l[1111];


int main()
{
    scanf("%d",&a);
    o[1]=o[0]=1;
    for(int t=2;t<=a;t++)
    {
        memset(l,0,sizeof(l));
        for(int i=t-1,j=t-2;j>=0;j-=2,i--)
        {
            l[o[i]+(o[i]-o[j])]=1;
        }
        for(int i=1;;i++)
        if(l[i]==0)
        {
            o[t]=i;
            break;
        }
    }//for(int t=1;t<=a;t++)

        printf("%d",o[a]);
}
