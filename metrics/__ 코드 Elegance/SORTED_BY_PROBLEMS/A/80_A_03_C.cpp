#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int N, A[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    A[0] = 1;
    A[1] = 1;
    for(int j = 2; j <= N; j++){
        for(int a = 1; ; a++) {
            A[j] = a;
            bool ff = true;
            for (int k = 1; j - 2 * k >= 0; k++) {
                if (A[j] - A[j - k] == A[j - k] - A[j - 2 * k]) {
                    ff = false;
                    break;
                }
            }
            if (ff) {
                break;
            }
        }
    }
    cout << A[N];
    return 0;
}