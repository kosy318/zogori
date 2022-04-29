#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, A[1001];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    A[0] = A[1] = 1;
    for (int i=2;i<=n;i++) {
        vector<bool> b(1001, 0);
        for (int k=1;k<=i/2;k++) {
            if (2 * A[i - k] - A[i - 2 * k] < 0) continue;
            b[2 * A[i - k] - A[i - 2 * k]] = 1;
        }
        for (int j=1;j<1001;j++)
            if (!b[j]) {
                A[i] = j;
                break;
            }
    }
    printf("%d", A[n]);
    return 0;
}

