#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;

    while(n > 3)
    {
        n -= 2;
        cnt++;
    }

    cout << cnt;
    return 0;
}
