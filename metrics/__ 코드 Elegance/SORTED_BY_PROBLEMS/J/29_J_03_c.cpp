#include <bits/stdc++.h>
using namespace std;
int D[1000000],N;
int main(){
    cin>>N;
    D[0] = D[1] = D[2] = D[3] = 0;
    D[4] = 1;
    for(int i = 5; i <= N; i++){
        if(i%2) D[i] = D[i/2+1]+2;
        else D[i] = D[i/2]+2;
    }
    cout<<D[N];
}