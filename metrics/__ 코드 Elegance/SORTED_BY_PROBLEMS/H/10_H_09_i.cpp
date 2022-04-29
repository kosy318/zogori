#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int lazy[8000];
int lazy1[8000];
int seg[8000];
int seg1[8000];
pair<int,int> a[1010];
pair<int,int> b[1010];
void lazy_update(int node,int x,int y){
    if(!lazy[node])return;
    seg[node]+=lazy[node];
    if(x!=y){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
}
int update(int lo,int hi,int val,int node,int x,int y){
    lazy_update(node,x,y);
    if(hi<x||y<lo)return seg[node];
    if(lo<=x&&y<=hi){
        lazy[node]+=val;
        lazy_update(node,x,y);
        return seg[node];
    }
    int mid=(x+y)/2;
    return seg[node]=min(update(lo,hi,val,node*2,x,mid),update(lo,hi,val,node*2+1,mid+1,y));
}
int query(int lo,int hi,int node,int x,int y){
    lazy_update(node,x,y);
    if(hi<x||y<lo)return 1234567890;
    if(lo<=x&&y<=hi)return seg[node];
    int mid=(x+y)/2;
    return min(query(lo,hi,node*2,x,mid),query(lo,hi,node*2+1,mid+1,y));
}
void lazy_update1(int node,int x,int y){
    if(!lazy1[node])return;
    seg1[node]+=lazy1[node];
    if(x!=y){
        lazy1[2*node]+=lazy1[node];
        lazy1[2*node+1]+=lazy1[node];
    }
    lazy1[node]=0;
}
int update1(int lo,int hi,int val,int node,int x,int y){
    lazy_update1(node,x,y);
    if(hi<x||y<lo)return seg1[node];
    if(lo<=x&&y<=hi){
        lazy1[node]+=val;
        lazy_update1(node,x,y);
        return seg1[node];
    }
    int mid=(x+y)/2;
    return seg1[node]=max(update1(lo,hi,val,node*2,x,mid),update1(lo,hi,val,node*2+1,mid+1,y));
}
int query1(int lo,int hi,int node,int x,int y){
    lazy_update1(node,x,y);
    if(hi<x||y<lo)return -1234567890;
    if(lo<=x&&y<=hi)return seg1[node];
    int mid=(x+y)/2;
    return max(query1(lo,hi,node*2,x,mid),query1(lo,hi,node*2+1,mid+1,y));
}
int c1,c2;
vector<int> xx;
vector<int> yy;
vector<pair<pair<int,int>,int>> vt;
int getidx(int x) {
    return lower_bound(xx.begin(),xx.end(),x)-xx.begin();
}
int getidy(int x){
    return lower_bound(yy.begin(),yy.end(),x)-yy.begin();
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int q,w;
        scanf("%d %d",&q,&w);
        a[i]={q,w};
        xx.push_back(q);
        yy.push_back(w);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int q,w;
        scanf("%d %d",&q,&w);
        xx.push_back(q);
        yy.push_back(w);
        b[i]={q,w};
    }
    sort(xx.begin(),xx.end());
    xx.erase(unique(xx.begin(),xx.end()),xx.end());
    sort(yy.begin(),yy.end());
    yy.erase(unique(yy.begin(),yy.end()),yy.end());
    for(int i=0;i<n;i++){
        vt.push_back({{getidx(a[i].first),getidy(a[i].second)},1});
    }
    for(int i=0;i<m;i++){
        vt.push_back({{getidx(b[i].first),getidy(b[i].second)},0});
    }
    scanf("%d %d",&c1,&c2);
    sort(vt.begin(),vt.end());
    int dap=0;
    for(int i=0;i<xx.size();i++){
        memset(seg,0,sizeof(seg));
        memset(lazy1,0,sizeof(lazy1));
        memset(seg1,0,sizeof(seg1));
        memset(lazy,0,sizeof(lazy));
        for(int y=0;y<vt.size();y++){
            if(vt[y].first.first<=i-1){
                continue;
            }
            if(!vt[y].second){
                update(vt[y].first.second,yy.size()-1,-c2,1,0,yy.size());
                update1(vt[y].first.second,yy.size()-1,-c2,1,0,yy.size());
            }
            else{
                update(vt[y].first.second,yy.size()-1,c1,1,0,yy.size());
                update1(vt[y].first.second,yy.size()-1,c1,1,0,yy.size());
                int cc=max(query1(vt[y].first.second,yy.size(),1,0,yy.size()),query1(vt[y].first.second,yy.size(),1,0,yy.size())-query(0,vt[y].first.second,1,0,yy.size()));
            // printf("%d %d %d\n",vt[y].first.first,vt[y].first.second,cc);
                dap=max(dap,cc);
            }
        }
    }
    printf("%d\n",dap);
}
