#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    int n;

    cin >> n;

    if(n < 4){
        cout << "0" << endl;
    }
    else{
        cout << n / 2 - 1<< endl;
    }

    return 0;
}
