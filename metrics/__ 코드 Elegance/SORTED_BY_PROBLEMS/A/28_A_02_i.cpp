#include <iostream>
using namespace std;

const int SIZE = 1500;
int dp[SIZE];
bool chk[SIZE];

void init() {
    for(int i=0; i<SIZE; i++) chk[i] = false;
}

void preprocessing()
{
    dp[0] = 1;
    dp[1] = 1;

    int k, val;

    for(int i=2; i<1001; i++) {
        k = 1;
        init();

        while(i - 2 * k >= 0)
        {
            val = 2 * dp[i - k] - dp[i - 2 * k];
            chk[val] = true;
            k++;
        }

        for(int j=1 ;j<1001; j++) {
            if(!chk[j]) {
                dp[i] = j;
                break;
            }
        }
    }
}

int main(void)
{
    preprocessing();

    int n;
    cin >> n;

    cout << dp[n];

    return 0;
}