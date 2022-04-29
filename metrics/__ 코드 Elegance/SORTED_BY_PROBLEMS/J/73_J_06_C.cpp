#include <iostream>

using namespace std;

int main(){
    long long n[1000000]={0,};
    n[3] = 0;
    n[4] =1;
    int m;
    cin >> m;
    for(int a=5;a<=m;a++){
        n[a]=n[(a+1)/2] + 2;
    }
    cout << n[m] << endl;
    return 0;
}