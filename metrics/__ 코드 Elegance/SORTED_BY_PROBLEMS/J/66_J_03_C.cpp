#include <iostream>

using namespace std;

int d[1000010], n;

int main()
{
    cin >> n;
    d[3] = 0;
    d[4] = 1;
    for(int i=5;i<=n;i++) {
        if (i % 2) {
            d[i] = d[(i+1)/2] + 2;
        }else
        {
            d[i] = d[i/2] + 2;
        }
    }
    cout << d[n];
}