#include <iostream>

using namespace std;

int a[1001];
int table[1001][501];
bool bary[100000001];

int main() {
    int n;
    cin >> n;

    a[0] = 1;
    a[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int q = 0; q < 1001; q++)
            bary[q] = false;

        for(int j = 1; 2 * j <= i; j++) {
                table[i][j] = 2 * a[i - j] - a[i - 2 * j];
        }

        for(int q = 1; 2 * q <= i; q++) {
            if(table[i][q] > 0) {
                bary[table[i][q]] = true;
            }
        }
        for(int amin = 1; amin <= 1001; amin++) {
            if(bary[amin] == false) {
                a[i] = amin;
                break;
            }
        }
    }
    cout << a[n];
}