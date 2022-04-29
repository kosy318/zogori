#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[1010]={0};
    int arr2[4]={0};
    arr[0]=1,arr[1]=1,arr[2]=2,arr[3]=1,arr[4]=1,arr[5]=2,arr[6]=2,arr[7]=4,arr[8]=4;
    for(int i=9;i<=1000;i++)
    {
        int ans=0;
        for(int j=0;j<=100;j++){
            bool able=true;
            for(int k=i/2;k>=0;k--)
            {
                if(j-arr[i-k]==arr[i-k]-arr[i-2*k]){
                    able=false;
                    break;
                }
            }
            if(able) {
                arr[i]=j;
                break;
            }
        }
    }
    int n;
    cin>>n;
    cout<<arr[n];
    return 0;
}