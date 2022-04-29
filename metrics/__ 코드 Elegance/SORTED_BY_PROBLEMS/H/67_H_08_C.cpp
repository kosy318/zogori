#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll inf = (1ll << 61);

struct point {
    int x, y, val;
    bool operator<(const point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

struct compy {
    bool operator() (const point& lhs, const point& rhs) const {
        if (lhs.y != rhs.y) return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    }
};
struct dataa{
    int x,y,val;
    inline bool operator<(const dataa &temp)const{
        return x<temp.x || (x==temp.x && val<temp.val);
    }
}b[20000];
int t=1;
struct data{
    int l,r,c,a;
}it[200000];
point raw[2000], a[2000];

ll lazy[4096 * 2];

int n, m, c1, c2;

void zip() {
    sort(raw, raw + n + m);
    a[0].y = raw[0].y;
    a[0].val = raw[0].val;
    for (int i = 1; i < n + m; i++) {
        if (raw[i - 1].x == raw[i].x) {
            a[i].x = a[i - 1].x;
        } else {
            a[i].x = a[i - 1].x + 1;
        }
        a[i].y = raw[i].y;
        a[i].val = raw[i].val;
    }

    sort(raw, raw + n + m, compy{});
    sort(a, a + n + m, compy{});
    a[0].y = 0;
    for (int i = 1; i < n + m; i++) {
        if (raw[i - 1].y == raw[i].y) {
            a[i].y = a[i - 1].y;
        } else {
            a[i].y = a[i - 1].y + 1;
        }
    }

    for (int i = 0; i < n + m; i++) {
        if (a[i].val == 1) {
            a[i].val = c1;
        } else {
            a[i].val = -c2;
        }
    }
}
void uup(int x,int y){
    int i=t-1+x;
    it[i].l+=y;
    if(it[i].l<0) it[i].l=0;
    it[i].r+=y;
    if(it[i].r<0) it[i].r=0;
    it[i].c+=y;
    if(it[i].c<0) it[i].c=0;
    it[i].a+=y;
    while(i!=1){
        i/=2;
        it[i].l=max(it[i*2].l,it[i*2].a+it[i*2+1].l);
        it[i].r=max(it[i*2+1].r,it[i*2+1].a+it[i*2].r);
        it[i].c=max(max(it[i*2].c,it[i*2+1].c),it[i*2].r+it[i*2+1].l);
        it[i].c=max(max(it[i].r,it[i].l),it[i].c);
        it[i].a=it[i*2].a+it[i*2+1].a;
    }
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> raw[i].x >> raw[i].y;
        raw[i].val = 1;
    }
    cin >> m;
    for (int i = n; i < n + m; i++) {
        cin >> raw[i].x >> raw[i].y;
        raw[i].val = -1;
    }

    cin >> c1 >> c2;

    while(t<=2000) t<<=1;
    zip();
    sort(a, a + n + m);
    int i,j;
    for(i=1;i<=n+m;i++){
        b[i].x=a[i-1].x+1;
        b[i].y=a[i-1].y+1;
        b[i].val=a[i-1].val;
    }
    sort(b+1,b+n+m+1);
    int max=0;
    for(i=1;i<=n+m;i++){
        if(b[i].x==b[i-1].x) continue;
        for(j=i;j<=n+m;j++){
            uup(b[j].y,b[j].val);
            if(max<it[1].c) max=it[1].c;
        }
        for(j=1;j<=t*2-1;j++) {
            it[j].l=0;
            it[j].r=0;
            it[j].c=0;
            it[j].a=0;
        }
    }
    printf("%d",max);
    return 0;
}