#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

struct info {
    int x, y, val;
};

struct node1 {
    int min = 10001, max = -10001, val = INT_MIN / 2;
    node1(int min = 10001, int max = -10001, int val = INT_MIN / 2) : min(min), max(max), val(val) {}
};

std::vector<int> Y;
int lazy[1048576 * 2 + 1], a[3010];
node1 tree[1048576 * 2 + 1];
info input[2010];

void init(int node, int start, int end) {
    lazy[node] = 0;
    if(start == end)
        tree[node].val = tree[node].max = tree[node].min = a[start];
    else {
        init(node << 1, start, (start + end) >> 1);
        init((node << 1) | 1, ((start + end) >> 1) + 1, end);
        tree[node].val = std::max(tree[node * 2].val, tree[node * 2 + 1].val);
        tree[node].val = std::max(tree[node].val, tree[node * 2 + 1].max - tree[node * 2].min);
        tree[node].max = std::max(tree[node * 2].max, tree[node * 2 + 1].max);
        tree[node].min = std::min(tree[node * 2].min, tree[node * 2 + 1].min);
    }
}

void lazy_propagation(int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node].max += lazy[node];
        tree[node].min += lazy[node];
        if(start != end) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int i, int j, int val) {
    lazy_propagation(node, start, end);
    if(i > end || j < start)
        return;
    if(i <= start && end <= j) {
        tree[node].max += val;
        tree[node].min += val;
        if(start != end) {
            lazy[node << 1] += val;
            lazy[(node << 1) | 1] += val;
        }
        return;
    }
    else {
        update(node << 1, start, (start + end) / 2, i , j, val);
        update((node << 1) | 1, (start + end) / 2 + 1, end, i, j, val);
        tree[node].val = std::max(tree[node * 2].val, tree[node * 2 + 1].val);
        tree[node].val = std::max(tree[node].val, tree[node * 2 + 1].max - tree[node * 2].min);
        tree[node].max = std::max(tree[node * 2].max, tree[node * 2 + 1].max);
        tree[node].min = std::min(tree[node * 2].min, tree[node * 2 + 1].min);
    }
}

node1 query(int node, int start, int end, int i, int j) {
    lazy_propagation(node, start, end);
    if(i > end || j < start) {
        return node1(10001, -10001, INT_MIN / 2);
    }
    if(i <= start && end <= j)
        return tree[node];
    node1 left = query(node * 2, start, (start + end) / 2, i, j);
    node1 right = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
    node1 result;
    result.min = std::min(left.min, right.min);
    result.max = std::max(left.max, right.max);
    result.val = std::max(left.val, right.val);
    result.val = std::max(result.val, right.max - left.min);

    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &input[i].x, &input[i].y);
        input[i].val = 1;
        Y.push_back(input[i].y);
    }

    int tmp;
    scanf("%d", &tmp);
    for(int i = n + 1; i <= tmp + n; i++) {
        scanf("%d %d", &input[i].x, &input[i].y);
        input[i].val = -1;
        Y.push_back(input[i].y);
    }

    n += tmp;
    int a1, b, r = 0;
    scanf("%d %d", &a1, &b);
    for(int i = 1; i <= n; i++) {
        if(input[i].val == 1) {
            input[i].val = a1;
            r = std::max(r, a1);
        }
        else
            input[i].val = -1 * b;
    }

    std::sort(input + 1, input + 1 + n, [](info a, info b) {
       return a.x < b.x;
    });

    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    for(int i = 1; i <= n; i++)
        input[i].y = std::lower_bound(Y.begin(), Y.end(),input[i].y) - Y.begin() + 1;

    for(int i = 1; i < n; i++) {
        memset(a, 0, sizeof(a));
        a[input[1].y] = input[1].val;
       for(int j = 2; j <= 1 + i; j++) {
            a[input[j].y] = input[j].val;
       }

       for(int j = 1; j <= Y.size(); j++)
           a[j] += a[j - 1];

       init(1, 1, Y.size());
       r = std::max(r, query(1, 1, Y.size(), 1, Y.size()).val);

       for(int j = i + 2; j <= n; j++) {
            update(1, 1, Y.size(), input[j - i - 1].y, Y.size(), -1 * input[j - i - 1].val);
            update(1, 1, Y.size(), input[j].y, Y.size(), input[j].val);
            r = std::max(r, query(1, 1, Y.size(), 1, Y.size()).val);
       }
    }

    printf("%d\n", r);
}