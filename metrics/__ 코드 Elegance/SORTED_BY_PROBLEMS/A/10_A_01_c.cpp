#include <iostream>
#include <cstdio>
using namespace std;

int ans[1001];
int main() {


    int n; scanf("%d",&n);
    ans[0] = 1, ans[1] = 1;
    for(int i=2;i<=n;i++) {
       // printf("i:%d\n", i);
        for (int j = 1;; j++) {
            bool flag = true;
            for (int k = 1; k < i; k++) {
                if (i - 2 * k < 0) break;
                int d1 = j - ans[i - k];
                int d2 = ans[i-k] - ans[i - 2 * k];

                if (d1 == d2) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans[i] = j;
                break;
            }
        }
    }
    printf("%d",ans[n]);
}