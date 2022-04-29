#include<bits/stdc++.h>
using namespace std;

int a[1005];
int n;

int main(){
    cin>>n;
    a[0]=a[1]=1;

    for(int i=2;i<=n;i++){
        for(int num=1;;num++){
            a[i]=num;
            int flag=0;
            for(int k=1;i-2*k>=0;k++){
                if(a[i]-a[i-k]==a[i-k]-a[i-2*k]){
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            else break;
        }
        //printf("%d\n",a[i]);
    }

    cout<<a[n];

    return 0;
}
