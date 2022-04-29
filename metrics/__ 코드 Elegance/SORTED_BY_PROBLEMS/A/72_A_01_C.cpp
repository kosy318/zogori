#include <bits/stdc++.h>

using namespace std;

const int max_n = 1505;
int a[max_n] = {1,1};
int visited[max_n] = {};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 2; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        for(int j = 1; i - 2 * j >= 0; j++) {
            int ret = a[i - j] - a[i - 2 * j] + a[i - j];
            if(ret >= 0) {
                visited[ret] = 1;
            }
        }
        for(int j = 1; j < max_n; ++j) {
            if(!visited[j]) {
                a[i] = j;
                break;
            }
        }
    }
    cout << a[N];
    return 0;
}
