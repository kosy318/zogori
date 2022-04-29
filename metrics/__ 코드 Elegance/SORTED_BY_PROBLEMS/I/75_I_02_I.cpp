#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;

int N;
pr A[100005];

bool f(int x) {
    int l = A[1].first, r = A[1].second;
    for(int i=2; i<=N; i++) {
        int _l = l + x, _r = r + x;
        if(_l > A[i].second) return 0;
        _l = min(_l, A[i].second), _r = min(_r, A[i].second);
        _l = max(_l, A[i].first), _r = max(_r, A[i].first);
        l = _l, r = _r;
    }
    return l <= r;
}

int main()
{
    scanf("%d", &N);
    for(int i=1, x, y; i<=N; i++) {
        scanf("%d %d", &x, &y);
        A[i] = pr(x, x + y);
    }
    sort(A + 1, A + N + 1);
    int s = 1, e = 1e9;
    while(s <= e) {
        int mid = s + e >> 1;
        f(mid) ? s = mid + 1 : e = mid - 1;
    }
    printf("%d\n", e);
}
