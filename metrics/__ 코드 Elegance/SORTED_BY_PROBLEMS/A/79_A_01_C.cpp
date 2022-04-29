#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main(){
    int n;

    cin>>n;

    arr[0]=1;
    arr[1]=1;
    int chk[10005];

    for(int i=2;i<=n;i++){
        memset(chk,0,sizeof(chk));
        for(int j=1;j*2<=i;j++){
            if(arr[i-j]+(arr[i-j]-arr[i-2*j])<=0) continue;
            chk[arr[i-j]+(arr[i-j]-arr[i-2*j])]=1;
            //cout << i << " " << j << " " << arr[i-j]+(arr[i-j]-arr[i-2*j]) << endl;
        }

        for(int j=1;j<10000;j++){
            if(chk[j]) continue;
            arr[i]=j;
            break;
        }

        //cout << i << ":" << arr[i] << endl;
    }

    cout << arr[n];

    return 0;
}