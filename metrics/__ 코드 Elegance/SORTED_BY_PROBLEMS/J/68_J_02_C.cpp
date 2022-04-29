#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n1 = 3;
    int n2 = 4;
    int a = 0;

    int n;
    cin>>n;

    int ni;

    for(ni=3;ni<=n;ni++){
        if(ni == n){
            cout << a;
            return 0;
        }
        if(n1 == ni){
            a++;
            n1 *=2;
        }
        if(n2 == ni){
            a++;
            n2*=2;
        }
    }



}
