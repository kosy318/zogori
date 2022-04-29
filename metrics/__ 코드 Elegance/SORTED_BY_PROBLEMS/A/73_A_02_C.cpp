#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1010] = {0,};
    a[0]=1; a[1]=1;
    for (int i=2;i<=n+1;++i) {
        int c[1001] = {0,};
        for (int k=1;i-2*k>=0;++k) {
            int no = 2*a[i-k] - a[i-2*k];
            c[no] = 1;
        }
        for (int j=1;j<=1000;++j) {
            if (!c[j]) {
                a[i] = j;
                break;
            }
        }
    }

    cout << a[n] << endl;
    //for (int i=0;i<=10;++i) printf("%d ", a[i]);
    return 0;
}