#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

typedef struct {
    int s;
    int e;
    int v;
}item;

int cur_point = 0;
int table[101];
int full[25];
vector<item> items;

void update(item cur, int index) {
    int point = cur_point;
    set<int> item_set;
    for(int i = cur.s; i <= cur.e; i++) {
        if(full[i] != 0 && item_set.count(full[i]) == 0) {
            point -= items[full[i]].v;
            item_set.insert(full[i]);
        }
    }
    if(cur_point < point + cur.v) {
        for(int i = 0; i < 25; i++)
            if(full[i] != 0 && item_set.count(full[i]) > 0) {
                full[i] = 0;
            }

        for(int i = cur.s; i <= cur.e; i++)
            full[i] = index;
        cur_point = point + cur.v;
    }
}

int main () {
    int m, n, a, b, c;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        cin >> a;
        table[i] = a;
    }
    for(int i = 0; i < n; i++) {
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

    for (int i = 0; i < items.size(); i++) {
        update(items[i], i);
    }

    cout << cur_point;

    return 0;
}