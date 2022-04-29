#include <bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

struct MSP {
    ll s, lm, rm, m;
};

struct Point {
    int y, x, val;
};

int P1, P2, C1, C2;
vector<Point> v1, v2, com, v;
MSP seg[4100];

MSP Update(int idx, int val, int n, int l, int r)
{
    if (r < idx || idx < l) return seg[n];
    if (l == r)
    {
        seg[n].s += val;
        seg[n].lm = seg[n].s;
        seg[n].rm = seg[n].s;
        seg[n].m = seg[n].s;
        return seg[n];
    }
    int mid = l+r>>1;
    MSP L = Update(idx, val, n*2, l, mid);
    MSP R = Update(idx, val, n*2+1, mid+1, r);
    seg[n].s = L.s + R.s;
    seg[n].lm = max(L.lm, L.s + R.lm);
    seg[n].rm = max(R.rm, R.s + L.rm);
    seg[n].m = max({L.m, R.m, L.rm + R.lm});
    return seg[n];
}

bool cmpy(Point a, Point b)
{
    return a.y < b.y;
}

bool cmp(Point a, Point b)
{
    return a.x < b.x;
}

int main() {
    scanf("%d", &P1);
    for (int i = 0; i < P1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v1.push_back({a, b, 0});
        com.push_back({a, b, i});
    }
    scanf("%d", &P2);
    for (int i = 0; i < P2; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v2.push_back({a, b, 0});
        com.push_back({a, b, P1 + i});
    }
    scanf("%d %d", &C1, &C2);

    sort(com.begin(), com.end(), cmp);
    int P = 1;
    for(int i=0; i<com.size(); i++)
    {
        if (i && com[i-1].x != com[i].x) P++;
        if (com[i].val < P1) v1[com[i].val].x = P;
        else v2[com[i].val-P1].x = P;
    }

    for(int i=0; i<P1; i++) {
        v.push_back(v1[i]);
        v.back().val = C1;
    }
    for(int i=0; i<P2; i++) {
        v.push_back(v2[i]);
        v.back().val = -C2;
    }

    sort(v.begin(), v.end(), cmpy);
    ll res = 0;
    for(int i=0; i<v.size(); i++)
    {
        if (i == 0 || v[i-1].y != v[i].y) {
            for(int j=0; j<4100; j++)
                seg[j] = {0,-INF,-INF,-INF};
            for (int j = i; j < v.size(); j++) {
                Update(v[j].x, v[j].val, 1, 1, 2000);
                if (j + 1 == v.size() || v[j].y != v[j+1].y)
                {
                    res = max(res, seg[1].m);
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}