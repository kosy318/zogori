#include <bits/stdc++.h>
using namespace std;
int n;
struct A{
    long long ls,rs,mx,s;
}seg[8000];
int a[2005][2005];
map<int,int> mx;
map<int,int> my;
pair<int,int> b[2005];
pair<int,int> d[2005];
pair<int,int> e[2005];
int c1,c2;
int nn;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n1,n2;
    int i,j;
    cin>>n1;
    set<int> sx;
    for(nn=1 ; nn<2000 ; nn*=2);
    set<int> sy;
    for(i=1 ; i<=n1 ; i++){
        int x,y;
        cin>>x>>y;
        sx.insert(x);
        sy.insert(y);
        b[i].first=x;
        b[i].second=y;

    }
    cin>>n2;
    for(i=1 ; i<=n1 ; i++){
        int x,y;
        cin>>x>>y;
        sx.insert(x);
        sy.insert(y);
        d[i].first=x;
        d[i].second=y;
    }
    int cnt=0;
    for(auto k: sx){
        mx[k]=++cnt;
    }
    cnt=0;
    for(auto k: sy)my[k]=++cnt;
    cin>>c1>>c2;
    for(i=1 ; i<=n1 ; i++){
        a[mx[b[i].first]][my[b[i].second]]+=c1;

        e[my[b[i].second]]={mx[b[i].first],c1};
    }
    for(i=1 ; i<=n2 ; i++){
         a[mx[d[i].first]][my[d[i].second]]-=c2;

        e[my[d[i].second]]={mx[d[i].first],-c2};
    }
    long long ans=0;

    for(i=1 ; i<=2000 ; i++){
        for(j=1 ; j<nn*2 ; j++)seg[j]={0,0,0,0};
        for(j=i ; j<=2000 ; j++){
            int q=e[j].first;
            int w=e[j].second;
            if(q==0)continue;
            seg[nn+q-1].s=w;
            seg[nn+q-1].mx=seg[nn+q-1].ls=seg[nn+q-1].rs=max(0,w);
            for(int k=(nn+q-1)/2 ; k>=1 ; k/=2){
                seg[k].ls=max(seg[k*2].ls,seg[k*2].s+seg[k*2+1].ls);
                seg[k].rs=max(seg[k*2+1].rs,seg[k*2+1].s+seg[k*2].rs);
                seg[k].s=seg[k*2].s+seg[k*2+1].s;
                seg[k].mx=max({seg[k*2].mx,seg[k*2+1].mx,seg[k*2].rs+seg[k*2+1].ls});
            }
            ans=max(ans,seg[1].mx);
        }
    }
    cout<<ans;
    return 0;
}
