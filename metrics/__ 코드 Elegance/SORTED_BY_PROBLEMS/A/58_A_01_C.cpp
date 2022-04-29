#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main(){
    int n;
    scanf("%d", &n);
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int val = 1; val <= 1000; val++){
            bool flag = true;
            for(int k = 1; i - 2*k >= 0; k++){
                if(val - a[i - k] == a[i - k] - a[i - 2*k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                a[i] = val;
                break;
            }
        }
    }
    printf("%d", a[n]);
    return 0;
}
