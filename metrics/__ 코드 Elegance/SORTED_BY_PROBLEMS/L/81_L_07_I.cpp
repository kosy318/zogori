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

long long cur_point[25];
long long table[101];
long long dp[25][25];
vector<item> items;

void update(item cur, long long index) {
//    long long point[25];
    for(int q = cur.e; q < 25; q++) {
//        for(int i = 0; i < 25; i++)
//            point[i] = cur_point[i];
//        set<long long> item_set;
//        for(long long i = cur.s; i <= cur.e; i++) {
//            if(dp[q][i] != -1 && item_set.count(dp[q][i]) == 0) {
//                point[q] -= items[dp[q][i]].v;
//                item_set.insert(dp[q][i]);
//            }
//        }
        if(cur_point[q] < cur.v + cur_point[cur.s]) {
//            for(long long i = 0; i < 25; i++)
//                dp[q][i] = -1;
//            for(long long i = 0; i <= cur.s - 1; i++)
//                dp[q][i] = dp[cur.s - 1][i];
//            for(long long i = cur.s; i <= cur.e; i++)
//                dp[q][i] = index;
            cur_point[q] = cur.v + cur_point[cur.s];
        }
    }
}

int main () {
    for(int q = 0; q < 25; q++)
        for(int i = 0; i < 25; i++)
            dp[q][i] = -1;
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

    for (long long i = 0; i < items.size(); i++) {
        update(items[i], i);
//        cout << items[i].e << " " << endl;
//        for(int q = 0; q < 25; q++)
//            cout << cur_point[q] << " ";
//        cout << endl;
//        for(int k = 0; k < 25; k++){
//            for(int q = 0; q < 25; q++)
//                cout << dp[k][q] << " ";
//            cout << endl;
//        }
//        cout << endl;
//        cout << endl;
    }

    cout << cur_point[24];

    return 0;
}