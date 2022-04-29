#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MX = 2000;

ll arr[2020];
ll tree[8080];
ll lsum[8080];
ll rsum[8080];
ll total[8080];

void update(int idx, ll val, int no, int nl, int nr){
    if(idx < nl || nr <= idx) return;
    if(nl+1 == nr && nl == idx){
        arr[idx] += val;
        lsum[no] = max(0LL, arr[idx]);
        rsum[no] = max(0LL, arr[idx]);
        total[no] = arr[idx];
        tree[no] = max(0LL, arr[idx]);
        return;
    }
    int mid = (nl+nr)/2;
    update(idx, val, 2*no, nl, mid);
    update(idx, val, 2*no+1, mid, nr);

    lsum[no] = max(lsum[2*no], total[2*no]+lsum[2*no+1]);
    rsum[no] = max(rsum[2*no+1], total[2*no+1]+rsum[2*no]);
    total[no] = total[2*no] + total[2*no+1];
    tree[no] = max(max(tree[2*no], tree[2*no+1]), rsum[2*no]+lsum[2*no+1]);
}
void update(int idx, ll val, int n){ update(idx, val, 1, 0, n); }



struct Point{
    int x, y, v;
    bool operator < (const Point& rhs) const{
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};

vector<pair<int,int> > p1, p2;
vector<Point> tmp;
vector<vector<Point> > po;
int c1, c2;

void build(){
    vector<int> usex, usey;
    for(int i=0; i<p1.size(); i++){
        usex.push_back(p1[i].first);
        usey.push_back(p1[i].second);
    }
    for(int i=0; i<p2.size(); i++){
        usex.push_back(p2[i].first);
        usey.push_back(p2[i].second);
    }
    sort(usex.begin(), usex.end());
    sort(usey.begin(), usey.end());
    for(int i=0; i<p1.size(); i++){
        p1[i].first = lower_bound(usex.begin(), usex.end(), p1[i].first)-usex.begin();
        p1[i].second = lower_bound(usey.begin(), usey.end(), p1[i].second)-usey.begin();
    }
    for(int i=0; i<p2.size(); i++){
        p2[i].first = lower_bound(usex.begin(), usex.end(), p2[i].first)-usex.begin();
        p2[i].second = lower_bound(usey.begin(), usey.end(), p2[i].second)-usey.begin();
    }
    for(int i=0; i<p1.size(); i++) tmp.push_back({p1[i].first, p1[i].second, c1});
    for(int i=0; i<p2.size(); i++) tmp.push_back({p2[i].first, p2[i].second, -c2});
    sort(tmp.begin(), tmp.end());

    po.resize(1);
    po[0].push_back(tmp[0]);
    int last = 0;
    for(int i=1; i<tmp.size(); i++){
        if(po[last][0].y != tmp[i].y){
            po.push_back(vector<Point>());
            last++;
        }
        po[last].push_back(tmp[i]);
    }
//
//    for(auto it : po){
//        for(auto it2 : it){
//            printf("(%d %d %d) ", it2.x, it2.y, it2.v);
//        }
//        printf("\n");
//    }
}

int main()
{
    int n1, n2;
    int maxv = -INF;
    scanf("%d", &n1);
    for(int i=0; i<n1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        p1.push_back({x, y});
    }
    scanf("%d", &n2);
    for(int i=0; i<n2; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        p2.push_back({x, y});
    }
    scanf("%d %d", &c1, &c2);
    build();

    for(int i=0; i<po.size(); i++){
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        memset(lsum, 0, sizeof(lsum));
        memset(rsum, 0, sizeof(rsum));
        memset(total, 0, sizeof(total));
//        printf("now %d\n", i);
        for(int j=i; j<po.size(); j++){
            for(int k=0; k<po[j].size(); k++){
                update(po[j][k].x, po[j][k].v, MX);
//                printf("update %d %d tree 1 : %lld\n", po[j][k].x, po[j][k].v, tree[1]);
            }
            maxv = max((ll)maxv, tree[1]);
        }
//        printf("\n");
    }
    printf("%lld\n", maxv);
    return 0;
}
