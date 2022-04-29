#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001],ra[100001],rb[100001],n;
bool chk[100010];
inline int prv(int u) {
    return !u ? n-1 : u-1;
}
inline int nxt(int u) {
    return u==n-1 ? 0 : u+1;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d", a+i); a[i]--;
        ra[a[i]]=i;
    }
    for(i=0;i<n;i++) {
        scanf("%d", b+i); b[i]--;
        rb[b[i]]=i;
    }
    for(i=0;i<n;i++) {
        if(chk[i]) continue;
        int l1=ra[i], r1=ra[i];
        int l2=rb[i], r2=rb[i];
        vector<int> v;
        v.push_back(i); chk[i] = true;
        bool flag = true;
        for(int j=0;j<n-1;j++) {
            if(a[prv(l1)]==b[prv(l2)]) {
                chk[a[prv(l1)]] = true;
                v.push_back(a[prv(l1)]);
                l1 = prv(l1);
                l2 = prv(l2);
            } else if(a[prv(l1)]==b[nxt(r2)]) {
                chk[a[prv(l1)]] = true;
                v.push_back(a[prv(l1)]);
                l1 = prv(l1);
                r2 = nxt(r2);
            } else if(a[nxt(r1)]==b[prv(l2)]) {
                chk[a[nxt(r1)]] = true;
                v.push_back(a[nxt(r1)]);
                r1 = nxt(r1);
                l2 = prv(l2);
            } else if(a[nxt(r1)]==b[nxt(r2)]) {
                chk[a[nxt(r1)]] = true;
                v.push_back(a[nxt(r1)]);
                r1 = nxt(r1);
                r2 = nxt(r2);
            } else {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(auto& it : v) {
            printf("%d ",it + 1);
        }
        return 0;
    }
    puts("-1");
    return 0;
}

/*

6
1 5 2 4 6 3
3 4 5 2 6 1
5
1 2 3 4 5
1 3 5 2 4

*/
