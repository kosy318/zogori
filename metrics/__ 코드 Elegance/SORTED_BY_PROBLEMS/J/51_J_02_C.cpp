#include <iostream>

using namespace std;

#define max 1000000
long long A[1000001]={0,0,0,0,1,2,2,3,3,4,4,4,4,5,5,5,5,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;


    long long k = 8, m = 6;
    long long i = 17,j;
    while(i <= n){
        for(j = 0; j < k; j++){
            if(i + j <= max)
                A[i + j] = m;
            else
                break;
        }
        for(j = k; j < 2 * k; j++){
            if(i + j <= max)
                A[i + j] = m + 1;
            else
                break;
        }
        i += 2 * k;
        m += 2;
        k *= 2;
    }

    cout << A[n];
}