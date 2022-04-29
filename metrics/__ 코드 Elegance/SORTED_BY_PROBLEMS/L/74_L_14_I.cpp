#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

struct day{
    ll start;
    ll end;
    ll money;

    bool operator < (const day &other) const {
        return money > other.money;
    }
};

int mo[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector <day> a(n);

    for(int i = 1; i <= m; i++) {
        cin >> mo[i];
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> a[i].start >> a[i].end >> x;

        a[i].money = (a[i].end - a[i].start)  * mo[x];
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    int s = a[0].start;
    int e = a[0].end;
    ans += a[0].money;

    for(int i = 1; i < n; i++) {
        if(a[i].end <= s || e <= a[i].start) {
            ans += a[i].money;

            if(a[i].end <= s) {
                s = a[i].start;
            }
            else if(e <= a[i].start) {
                e = a[i].end;
            }
        }
    }

    cout << ans;

    return 0;
}