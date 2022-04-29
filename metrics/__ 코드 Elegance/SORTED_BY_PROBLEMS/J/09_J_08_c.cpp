#include <iostream>
using namespace std;

int calc(int n){
    if(n<3){
        return -1;
    }
    if(n<4){
        return 0;
    }
    return calc((n+1)>>1)+2;
}

int main(){
    int n;
    cin>>n;
    cout<<calc(n)<<endl;
}
