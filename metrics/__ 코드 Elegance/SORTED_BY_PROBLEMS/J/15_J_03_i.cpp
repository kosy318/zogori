#include <bits/stdc++.h>
using namespace std;

int arr[1001000]={0};
int main() {
    int t=1;
    int n;
    int v=2;
    scanf("%d", &n);
    int cnt=4;
    for (;cnt<=n;){
        for(int j=0;j<t;j++){
            arr[cnt++]=v;
        }
        v++;
        for(int j=0;j<4*2;j++){
            arr[cnt++]=v;
        }
        v++;
    }
    printf("%d\n",arr[n]-1);
    return 0;
}