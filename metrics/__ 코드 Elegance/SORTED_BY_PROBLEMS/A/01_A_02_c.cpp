#include <iostream>
using namespace std;

int num[1050]={1,1};

int main(){
    int n;
    for(int i=2; i<=1000;i++)
    {
        for(int j=1; ;j++)
        {
            bool flag=true;
            for(int k=1; i-2*k>=0; k++)
            {
                if(j-num[i-k] == num[i-k]-num[i-2*k])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                num[i]=j;
                break;
            }
        }
    }
    cin>>n;
    cout<<num[n];

    return 0;
}
