#include <iostream>

using namespace std;


int main()
{
    int n,sum=4,cnt=1;
    cin>>n;
    if(n==3)
        cout<<0;
    else if(n==4)
        cout<<1;
    else{
        for(int i=2;;i*=2)
        {
            for(int j=1;j<3;j++)
            {
               sum+=j*i;
               if(n<=sum)
               {
                cout<<cnt;
                return 0;
               }
               cnt++;
            }
        }
    }

    return 0;
}
