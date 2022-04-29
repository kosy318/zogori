#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

pair<int, int> sum[2010];
int main() {
    int n, m, x, y;
    scanf("%d", &n);
    vector <pair<int, pair<int, pair<int, int>>>> point, rpoint;
    for(int i = 0; i<n; i++) {
        scanf("%d %d", &x, &y);
        point.push_back({x, {y, {i, 1}}});
        rpoint.push_back({y, {x, {i, 1}}});
    }
    scanf("%d", &m);
    for(int i = 0; i<m; i++) {
        scanf("%d %d", &x, &y);
        point.push_back({x, {y, {i, -1}}});
        rpoint.push_back({y, {x, {i, -1}}});
    }

    sort(point.begin(), point.end());
    sort(rpoint.begin(), rpoint.end());
    int c1, c2, MAX = 0;
    scanf("%d %d", &c1, &c2);
    for(int i = 0; i<n+m; i++) {
        if(point[i].second.second.second == 1) {
            if(i == 0) {
                sum[i].first = 1;
            } else {
                sum[i].first = sum[i-1].first + 1;
                sum[i].second = sum[i-1].second;
            }
        } else {
            if(i == 0) {
                sum[i].second = 1;
            } else {
                sum[i].first = sum[i-1].first;
                sum[i].second = sum[i-1].second + 1;
            }
        }
        MAX = max(MAX, sum[i].first * c1 - sum[i].second * c2);
    }

    int top = 0, bottom = n + m - 1;
    int topMinus = 0, topPlus = 0, boMinus= 0 , boPlus = 0;
    bool flag = false;
    while(top <= bottom) {
        while(rpoint[top].second.second.second == -1) {
            top++;
            topMinus++;
        }
        while(rpoint[bottom].second.second.second == -1) {
            bottom++;
            boMinus++;
        }
        for(int j = rpoint[top].second.second.first; j <= rpoint[bottom].second.second.first; j++) {
            int pl = sum[j].first - topPlus - boPlus;
            int ml = sum[j].second - topMinus - boMinus;
            MAX = max(MAX, pl * c1 - ml * c2);
            if(!flag) {
                top++;
                topPlus++;
                flag = !flag;
            }  else {
                bottom++;
                boPlus++;
                flag = !flag;
            }
        }
    }
    printf("%d", MAX);
    return 0;
}
