#include <iostream>

using namespace std;

int main ()
{
    int n, res = 0;

    cin >> n;

    while (true)
    {
        if (n == 3) {
            printf("%d", res);
            break;
        }
        else if (n == 4) {
            printf("%d", res + 1);
            break;
        }

        if (n % 2 == 0)
        {
            n = n / 2;
            res = res + 2;
        }
        else if (n % 2 == 1)
        {
            n++;
            n = n / 2;
            res = res + 2;
        }
    }

    return 0;
}