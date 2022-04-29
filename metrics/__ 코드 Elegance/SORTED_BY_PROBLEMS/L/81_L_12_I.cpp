#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

typedef struct {
    long s;
    long long e;
    long long v;
}item;

long long table[104];
long long dp[10002][15003];
vector<item> items;

int main () {
    long long m, n, a, b, c;
    cin >> m >> n;

    for(long long i = 0; i < m; i++) {
        cin >> a;
        table[i] = a;
    }
    for(long long i = 0; i < n; i++) {
        cin >> a >> b >> c;
        item temp;
        temp.s = a;
        temp.e = b;
        temp.v = (b - a) * table[c - 1];
        items.push_back(temp);
    }
    struct {
        bool operator()(item a, item b) {
            if (a.e < b.e) {
                return true;
            }
            return false;
        }
    } cmp;
    sort(items.begin(), items.end(), cmp);

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < 15000; j++)
            dp[i][j] = 0;

    for (long long i = 1; i <= n; i++) {
        for(int j = 0; j < 15001; j++) {
            if(j >= items[i - 1].e) {
                if(dp[i - 1][j] > dp[i - 1][items[i - 1].s] + items[i - 1].v)
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][items[i - 1].s] + items[i - 1].v;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
//    for(int i = 0; i <= items.size(); i++) {
//        for(int j = 0; j < 25; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//
//    }
    cout << dp[n][15000];

    return 0;
}