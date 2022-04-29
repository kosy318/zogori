#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 3) cout << 0;
    else if(n == 4) cout << 1;
    else
    {
        int cnt = 1;
        while(n>4)
        {
            cnt++;
            n -= 2;
        }
        cout << cnt;
    }
    return 0;
}
