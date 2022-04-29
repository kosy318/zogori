#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 3)
    {
        cout << 0;
    }
    else if(n==4)
    {
        cout<<1;
    }
    else if(n%2)
    {
        cout << n/2;
    }
    else{
        cout<<(n-1)/2;
    }

    return 0;
}
