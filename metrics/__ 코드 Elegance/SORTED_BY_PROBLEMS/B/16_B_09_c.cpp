#include <stdio.h>
#include <algorithm>
#include <vector>

struct info {
    int next;
    long long weight;
    info(int next, long long weight) : next(next), weight(weight) {}
};

struct node {
    long long squre, hap;
    int cnt;
};

std::vector<info> graph[100010];
long long r;

node getHapWeight(node cur, long long weight) {
    cur.squre += (weight * weight) * cur.cnt + 2 * weight * cur.hap;
    cur.hap += cur.cnt * weight;
    return cur;
}

node dfs(int start, int p) {
    if(graph[start].size() == 1) {
        node result;
        result.squre = 0;
        result.hap = 0;
        result.cnt = 1;
        return result;
    }

    node left, right, result;

    if(graph[start][0].next == p) {
        left = getHapWeight(dfs(graph[start][1].next, start), graph[start][1].weight);
        right = getHapWeight(dfs(graph[start][2].next, start), graph[start][2].weight);
    }
    else if(graph[start][1].next == p) {
        left = getHapWeight(dfs(graph[start][0].next, start), graph[start][0].weight);
        right = getHapWeight(dfs(graph[start][2].next, start), graph[start][2].weight);
    }
    else {
        left = getHapWeight(dfs(graph[start][1].next, start), graph[start][1].weight);
        right = getHapWeight(dfs(graph[start][0].next, start), graph[start][0].weight);
    }

    r += right.cnt* left.squre + left.cnt*right.squre + 2 * left.hap * right.hap;
    result.squre = left.squre + right.squre;
    result.hap = left.hap + right.hap;
    result.cnt = left.cnt + right.cnt;
    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        int a, b;
        long long weight;
        scanf("%d %d %lld", &a, &b, &weight);
        graph[a].push_back(info(b, weight));
        graph[b].push_back(info(a, weight));
    }

    int start;
    for(int i = 1; i <= n; i++) {
        if(graph[i].size() == 1)
            start = i;
    }
    node tmp = getHapWeight(dfs(graph[start][0].next, start), graph[start][0].weight);
    r += tmp.squre;

    printf("%lld\n", r);
}