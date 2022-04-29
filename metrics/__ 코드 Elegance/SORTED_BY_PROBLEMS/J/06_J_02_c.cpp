#include <bits/stdc++.h>

using namespace std;

int n;

int get_num(int k){
    if(k<=4) return k-3;
    return 2+get_num(k/2+k%2);
}

int main(){
    cin>>n;
    cout<<get_num(n);
    return 0;
}