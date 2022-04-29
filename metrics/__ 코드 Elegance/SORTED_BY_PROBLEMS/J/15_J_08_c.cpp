#include <bits/stdc++.h>
using namespace std;

int arr[1001000]={0};
int main() {
    int t=1;
    int n;
    int v=2;
    cin>>n;
    arr[3]=1;
    int cnt=4;

    for (;cnt<=n;){

        for(int j=0;j<t && cnt <= n;j++){
            arr[cnt++]=v;
        }
        v++;
        for(int j=0;j<t*2 && cnt <= n;j++){
            arr[cnt++]=v;
        }
        v++;

        if(t<=1000000)
            t*=2;
    }
    cout<<arr[n]-1;
    return 0;
}