#include <iostream>

using namespace std;

int A[1001];

int main(){
    int n;
    scanf("%d", &n);
    A[0] = 1;
    A[1] = 1;
    for(int j = 2; j <= n; j++){
        for(int i = 1; ; i++){
            int flag = 0;
            for(int k = 1; k <= j/2; k++){
                if(i - A[j-k] == A[j-k] - A[j-2*k]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                A[j] = i;
                break;
            }
        }
    }
    printf("%d\n", A[n]);
    return 0;
}
