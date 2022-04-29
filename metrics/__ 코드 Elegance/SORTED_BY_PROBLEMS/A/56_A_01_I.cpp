#include <iostream>

using namespace std;
int arr[1005];
bool check[1005];
int main()
{
    int n;
    int ans=2000000000;
    arr[0]=arr[1]=1;
    arr[2]=2;
    cin>>n;
    for(int i=3;i<=n;i++){
        for(int j=0;j<1005;j++){
            check[j]=true;
        }
        for(int k= 1;2*k<=i;k++){
            check[arr[i-k]*2-arr[i-2*k]]=false;
        }
        for(int j=1;j<1005;j++){
            if(check[j]){
                arr[i]=j;
                break;
            }
        }
    }
    cout<<arr[n]<<"\n";
    return 0;
}
