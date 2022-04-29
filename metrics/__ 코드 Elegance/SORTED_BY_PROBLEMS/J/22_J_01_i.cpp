#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==3){
        cout<<0;
    }
    else{
        cout<<(n-2)/2;
    }
    return 0;
}
