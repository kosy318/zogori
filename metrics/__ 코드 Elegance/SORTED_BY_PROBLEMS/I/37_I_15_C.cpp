#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector <pair<int, pair<int, int>>> a;

int n;
bool isTrue(int size) {
    int idx = 0;
    int cur = a[idx].second.first;

    while(++idx < n) {
        if(cur + size > a[idx].second.first +  a[idx].second.second) return false;
        else if(cur + size < a[idx].second.first) {
            cur = a[idx].second.first;
        } else {
            cur = cur + size;
        }
    }
    return true;
}
int main() {
    scanf("%d", &n);
    int x, y;
    for(int i = 0; i<n; i++) {
        scanf("%d %d", &x, &y);
        a.push_back({x, {x, y}});
    }
    sort(a.begin(), a.end());

    double left = 0, right = 2000000005;

    int MAX = 0;
    while(left <= right) {
        if(right - left < 0.5) break;
        double mid = (left + right) / 2;

        if(isTrue((int)mid)) {
            MAX = max(MAX, (int)mid);
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%d", MAX);

    return 0;
}
