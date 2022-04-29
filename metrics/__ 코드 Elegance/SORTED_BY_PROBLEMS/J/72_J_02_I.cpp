#include <bits/stdc++.h>

using namespace std;

long long arr[2222222];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    int c = 3, cnt = 0;
    cin >> n;

    for(int i = 4; i <= n; i++){
        if(cnt >= c/2)arr[i] = arr[c] + 2;
        else arr[i] = arr[c] + 1;
        cnt++;
        if(cnt == c){
            c = c * 2;
            cnt = 0;
        }
    }
    cout << arr[n];
    return 0;
}
