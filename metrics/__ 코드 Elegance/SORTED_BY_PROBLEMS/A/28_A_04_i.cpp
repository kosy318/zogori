#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>


using namespace std;

const int SIZE = 1001;
int dp[SIZE + 100];
bool chk[100];

void init() {
    for(int i=0; i<SIZE; i++) chk[i] = false;
}

void preprocessing()
{
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<SIZE; i++) {
        int k = 1;
        init();
        while(i - 2 * k >= 0)
        {
            chk[2 * dp[i - k] - dp[i - 2 * k]] = true;
            k++;
        }

        for(int j=1; j<100; j++) {
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
    scanf("%d", &n);

    printf("%d", dp[n]);

    return 0;
}