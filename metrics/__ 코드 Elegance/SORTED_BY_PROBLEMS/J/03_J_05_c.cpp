#include <iostream>
#include <vector>
using namespace std;

int DP[1000010];

int main(int argc, char *argv[])
{
    int n;

    cin >> n;

    DP[3] = 0;
    DP[4] = 1;
    DP[5] = 2;

    for(int i=6; i<=n; ++i){
        DP[i] = DP[(i + 1) / 2] + 2;
    }

    cout << DP[n] << endl;

    return 0;
}
