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
        if(cur + size > a[idx].second.first + a[idx].second.second) return false;
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
        a.push_back({x+y, {x, y}});
    }
    sort(a.begin(), a.end());

    int left = 0, right = 1000000000;

    int MAX = 0;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(isTrue(mid)) {
            left = mid + 1;
            MAX = max(MAX, mid);
        } else {
            right = mid - 1;
        }
        if(left == mid && mid == right) break;
    }
    printf("%d", MAX);

    return 0;
}
