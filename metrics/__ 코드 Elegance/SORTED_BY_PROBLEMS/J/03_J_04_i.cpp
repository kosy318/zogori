#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    int n;
    int prev;
    int now;
    int value;

    cin >> n;

    int pre1 = 1;
    int pre2 = 1;

    for(int i=2; i<=n-4; ++i){
        value = pre1 + pre2;
        pre1 = pre2;
        pre2 = value;
    }
    if(n==3){
        cout<<"0"<<endl;
    }
    else if(n==4 || n==5){
        cout<<"1"<<endl;
    }
    else
        cout<<value<<endl;

    return 0;
}
