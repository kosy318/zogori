#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A[1001]={1,1,2,1,1,2,2,4,4,};
    int n;
    cin >> n;

    for(int i = 9; i <= n; i++){
        bool check[50001] = {};
        for(int j = 1; i - 2 * j >= 0; j++){
            int temp = 2 * A[i - j] - A[i - 2*j];
            if(temp > 0)
            check[temp] = true;
        }
        for (int j = 1; j <= 50000; j++){
            if(check[j] == false){
                A[i] = j;
                break;
            }
        }
    }
    cout << A[n];
}