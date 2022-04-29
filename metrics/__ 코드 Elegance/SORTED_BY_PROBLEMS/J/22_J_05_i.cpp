#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    if(n==3){
        cout<<0;
    }
    else{
        if(n%2==0){
            cout<<(n-2)/2;
        }
        else{
            cout<<(n-2)/2+1;
        }
    }



    return 0;
}
