#include <iostream>

using namespace std;

int dp[1000100]={0,0,0,0,1,2,2};

int main()
{
    int n;
    cin>>n;

    for(int i=4;i<=n;i++)
    {
        if(dp[i])
            dp[i*2]=dp[i]+2;
        else
        {
            dp[i]=dp[i+1];
            dp[i*2]=dp[i]+2;
        }
    }
    cout<<dp[n];
    return 0;
}
