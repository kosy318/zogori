#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[1000];

int main()
{
    cin>>n;
    int k=1;
    for(int i=0; i<=n; i++)
    {
        A[i]=1;
    }
    for(int i=2; i<=n; i++)
    {
        int temp=A[i];
        bool flag=false;
        while(!flag)
        {
            for(k=1; k<=i/2; k++)
            {
                if(temp-A[i-k]==A[i-k]-A[i-2*k])
                {
                    break;
                }

                if(k==i/2)
                {
                    flag=true;
                }
            }
            temp++;
        }
        A[i]=temp-1;

    }
    cout<<A[n]<<endl;
}
