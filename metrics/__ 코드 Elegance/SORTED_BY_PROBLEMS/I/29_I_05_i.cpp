#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAX_N=100001;

int N;
P point[MAX_N];

bool check(int D) {
    int start = point[0].first;
    for (int i=1; i<N; i++) {
        start = max(start+D, point[i].first);
        if (point[i].first + point[i].second - 1 < start) return false;
    }
    return true;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        point[i] = P(a,b);
    }
    sort(point, point+N);

    int left = 0;
    int right = 1e9;

    int ret = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        if (check(mid)) {
            left = mid + 1;
            ret = max(ret, left);
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ret);
    return 0;
}