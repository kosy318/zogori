#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class SegmentTree{
public:
    int n;
    vector<int> segtree;
    vector<int> lazy;

    SegmentTree(int n){
        segtree.resize(1<<((int)ceil(log2(n)+1)));
        lazy.resize(segtree.size());
    }

    void lazypropagation(int ns, int ne, int pos){
        segtree[pos]=max(segtree[pos],lazy[pos]);
        if(ns!=ne){
            lazy[pos*2]=max(lazy[pos*2],lazy[pos]);
            lazy[pos*2+1]=max(lazy[pos*2+1],lazy[pos]);
        }
        lazy[pos]=0;
    }

    void update(int s, int e, int ns, int ne, int pos, int value){
        lazypropagation(ns, ne, pos);
        if(ne<s || e<ns) return;
        if(s<=ns && ne<=e){
            lazy[pos]=value;
            lazypropagation(ns,ne,pos);
            return;
        }
        int mid=(ns+ne)>>1;
        update(s,e,ns,mid,pos*2,value);
        update(s,e,mid+1,ne,pos*2+1,value);
        segtree[pos]=max(segtree[pos*2],segtree[pos*2+1]);
    }

    int query(int s, int e, int ns, int ne, int pos){
        lazypropagation(ns, ne, pos);
        if(ne<s || e<ns) return 0;
        if(s<=ns && ne<=e) return segtree[pos];
        int mid=(ns+ne)>>1;
        return max(query(s,e,ns,mid,pos*2),query(s,e,mid+1,ne,pos*2+1));
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<int> cost(m);
    for(int i=0; i<m; i++) cin>>cost[i];
    vector<pair<pair<int,int>,int>> ore(n);
    for(int i=0; i<n; i++){
        int s,e,t;
        cin>>s>>e>>t;
        ore[i].first={s-1,e-1};
        ore[i].second=(e-s)*cost[t-1];
    }
    sort(ore.begin(),ore.end(),[](const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2){
       return p1.first.second<p2.first.second;
    });

    SegmentTree st=SegmentTree(15000);
    for(int i=0; i<n; i++){
        int mx=st.query(0,ore[i].first.first,0,14999,1)+ore[i].second;
        st.update(ore[i].first.second,14999,0,14999,1,mx);
    }
    int answer=st.query(0,14999,0,14999,1);
    cout<<st.query(0,14999,0,14999,1);

    return 0;
}