#include <bits/stdc++.h>

using namespace std;

struct node{
    int l,r,req;
}tree[4*150001];
int tn=1;
void init(int a){
    if(a>=tn) return;
    init(2*a); init(2*a+1);
    tree[a].l=tree[2*a].l; tree[a].r=tree[2*a+1].r; tree[a].req=0;
}
void update(int a,int s, int d){ //d to s
    if(s<tree[a].l || tree[a].r<s) return;
    else if(tree[a].l>=s && s>=tree[a].r) tree[a].req = max(tree[a].req,d);
    else{
        update(2*a,s,d); update(2*a+1,s,d);
        tree[a].req = max(tree[2*a].req, tree[2*a+1].req);
    }
}
int query(int a,int s,int d){
    if(d<tree[a].l||tree[a].r<s) return 0;
    else if(s<=tree[a].l && tree[a].r<=d) return tree[a].req;
    else{
        return max(query(2*a,s,d),query(2*a+1,s,d));
    }
}
int m,n; int val[101];
struct st{
    int s,e,t;
}ipt[10001];
bool cmp(st a, st b){
    return a.e<=b.e;
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        cin>>val[i];
    for(int i=1;i<=n;i++){
        cin>>ipt[i].s>>ipt[i].e>>ipt[i].t;
    }

    while(tn<=15000) tn*=2;
    for(int i=tn;i<2*tn;i++) tree[i].l=i-tn+1, tree[i].r=i-tn+1;
    init(1);

    sort(ipt+1,ipt+1+n,cmp);
    for(int i=1;i<=n;i++){
        update(1,ipt[i].e, query(1, 1,ipt[i].s) + val[ipt[i].t]*(ipt[i].e-ipt[i].s)   ); // check
    }
    cout<<query(1,1,15000);
    return 0;
}