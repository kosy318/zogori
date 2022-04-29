#include <bits/stdc++.h>
using namespace std;
int n;
int find_dim(int p){
    if(p==3){
        return 0;
    }else if(p==4){
        return 1;
    }else{
        if(p%2==0){
            return find_dim(p/2)+2;
        }else{
            return find_dim((p+1)/2)+2;
        }
    }

    return 0;
}
int main() {
    cin>>n;
    cout<<find_dim(n);
    return 0;
}

