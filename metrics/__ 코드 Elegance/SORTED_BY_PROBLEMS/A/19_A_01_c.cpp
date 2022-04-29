#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, arr[1005];
int main()
{
    cin >> N;
    arr[0]=1;
    arr[1]=1;
    for (int i=2;i<=N;i++){
        ll a=987654321, chk[1005]={0};
        for (int j=1;j*2<=i;j++){
            chk[arr[i-j]*2-arr[i-j*2]]++;

        }
        for (int j=1;j<=1000;j++){
            if (chk[j]==0){
                arr[i]=j;
                break;
            }
        }

    }
    cout << arr[N];
    return 0;
}
