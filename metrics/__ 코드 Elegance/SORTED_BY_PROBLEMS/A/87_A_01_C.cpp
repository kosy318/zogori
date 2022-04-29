#include <iostream>
#include <algorithm>

int a[1005];

int main() {
    a[0] = 1;
    a[1] = 1;

    for (int i = 2; i <= 1000; ++i) {
        bool poss[500];
        for (int l = 0; l < 500; ++l) {
            poss[l] = true;
        }

        for (int k = 1; i -2*k >= 0 ; ++k) {
            if ((2*a[i-k] - a[i - 2*k]) >= 0)
                poss[2*a[i-k] - a[i - 2*k]] = false;
        }

        for (int k = 1; k < 500; ++k) {
            if(poss[k]) {
                a[i] = k;
                break;
            }
        }
    }

    int in;
    scanf("%d", &in);
    printf("%d\n", a[in]);

    return 0;
}