#include <iostream>

using namespace std;

int dp[10000004];

int main()
{
    int n;
    cin >> n;

    dp[3] = 0;
    dp[4] = 1;
    if(n > 4)
    {
        int two[22];
        int t = 1;
        for(int i = 0 ; i < 21 ; i++)
        {
            two[i] = t;
            t *= 2;
        }

        int i = 4;
        int cnt = 2;
        while(1)
        {
            for(int j = 0 ; j < two[cnt/2] ; j++)
            {
                i++;
                dp[i] = cnt;
            }
            cnt++;
            for(int j = 0 ; j < two[cnt/2] ; j++)
            {
                i++;
                dp[i] = cnt;
            }
            cnt++;
            if(i >= n) break;
        }
    }
    cout << dp[n];
    return 0;
}
