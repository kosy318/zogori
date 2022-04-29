#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1001];
bool c[1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    for (int i=3; i<=n; i++)
    {
        for (int j=0; j<=i; j++) c[j] = 0;

        for (int k=1; k*2<=i; k++)
        {
            d[i] = 2 * d[i-k] - d[i - 2*k];
            if (d[i] > 0) c[d[i]] = true;
        }

        for (int j=1; j<=i; j++)
            if (!c[j])
            {
                d[i] = j;
                break;
            }
    }

    cout << d[n];

    return 0;
}
