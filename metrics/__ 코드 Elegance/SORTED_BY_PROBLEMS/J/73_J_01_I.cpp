#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==3)
        cout << 0 << endl;
    else if(n==4)
        cout << 1 << endl;
    else {
        n-=5;
        cout << 2 + (n/2) << endl;
    }
    return 0;
}