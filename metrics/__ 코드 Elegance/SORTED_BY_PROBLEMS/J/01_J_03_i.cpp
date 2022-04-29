#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int answer = (n-3)%2 == 0 ? (n-3)/2 : (n-2)/2;
    cout << answer << endl;
    return 0;
}
