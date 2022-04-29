#include <stdio.h>
#include <algorithm>
#define SIZE 131072

struct info {
    long long s, e, val;
};

long long tree[SIZE * 2 + 1];
long long A[110];
info input[10010];

void update(int num, long long val) {
    num |= SIZE;
    tree[num] = std::max(tree[num], val);

    while(num >>= 1)
        tree[num] = std::max(tree[num << 1], tree[num << 1 | 1]);
}

long long query(int s, int e) {
    s |= SIZE, e |= SIZE;
    long long r = 0;

    while(s <= e) {
        if(s % 2 == 1) r = std::max(r, tree[s]);
        if(e % 2 == 0) r = std::max(r, tree[e]);

        s = (s + 1) >> 1;
        e = (e - 1) >> 1;
    }
    return r;
}

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    for(int i = 1; i <= m; i++)
        scanf("%lld", A + i);

    for(int i = 1; i <= n; i++) {
        int tmp;
        scanf("%lld %lld %d", &input[i].s, &input[i].e, &tmp);
        input[i].val = A[tmp] * (input[i].e - input[i].s);
    }

    std::sort(input + 1, input + 1 + n, [](info a, info b) {
       return a.s > b.s;
    });

    long long r = 0;
    for(int i = 1; i <= n; i++) {
        long long tmp = query(input[i].e, 15000) + input[i].val;
        update(input[i].s, tmp);
    }
    printf("%lld\n", query(0, 15000));
}