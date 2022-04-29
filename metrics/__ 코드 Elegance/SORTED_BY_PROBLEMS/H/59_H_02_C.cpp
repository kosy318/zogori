#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;

struct SegTree{
    vector<int> lval, rval, sum, maxv;
    int base;
    SegTree(int a){
        base=1;
        while(base<a) base<<=1;
        lval.resize(base*2+2);
        rval.resize(base*2+2);
        sum.resize(base*2+2);
        maxv.resize(base*2+2);
        base--;
    }
    void update(int idx, int val){
        idx+=base;
        lval[idx]=rval[idx]=sum[idx]=maxv[idx]=val;
        idx>>=1;
        while(idx!=0){
            lval[idx]=max(lval[idx*2],lval[idx*2+1]+sum[idx*2]);
            rval[idx]=max(rval[idx*2+1],rval[idx*2]+sum[idx*2+1]);
            sum[idx]=sum[idx*2]+sum[idx*2+1];
            maxv[idx]=max(maxv[idx],maxv[idx*2]);
            maxv[idx]=max(maxv[idx],maxv[idx*2+1]);
            maxv[idx]=max(maxv[idx],lval[idx]);
            maxv[idx]=max(maxv[idx],rval[idx]);
            maxv[idx]=max(maxv[idx],lval[idx*2+1]+rval[idx*2]);
            idx>>=1;
        }
    }
    int get_max(){ return maxv[1]; }
};

int n1, n2;
int p1[1005][2], p2[1005][2];
int c1, c2;
vector<P> plst[2005];

int main()
{
    scanf("%d",&n1);
    vector<int> xidx, yidx;
    for(int i=1 ; i<=n1 ; i++){
        scanf("%d %d",&p1[i][0],&p1[i][1]);
        xidx.push_back(p1[i][0]);
        yidx.push_back(p1[i][1]);
    }
    scanf("%d",&n2);
    for(int i=1 ; i<=n2 ; i++){
        scanf("%d %d",&p2[i][0],&p2[i][1]);
        xidx.push_back(p2[i][0]);
        yidx.push_back(p2[i][1]);
    }
    scanf("%d %d",&c1,&c2);
    sort(xidx.begin(),xidx.end());
    xidx.erase(unique(xidx.begin(),xidx.end()),xidx.end());
    sort(yidx.begin(),yidx.end());
    yidx.erase(unique(yidx.begin(),yidx.end()),yidx.end());
    for(int i=1 ; i<=n1 ; i++){
        p1[i][0]=lower_bound(xidx.begin(),xidx.end(),p1[i][0])-xidx.begin()+1;
        p1[i][1]=lower_bound(yidx.begin(),yidx.end(),p1[i][1])-yidx.begin()+1;
        plst[p1[i][1]].push_back(P(p1[i][0],1));
    }
    for(int i=1 ; i<=n2 ; i++){
        p2[i][0]=lower_bound(xidx.begin(),xidx.end(),p2[i][0])-xidx.begin()+1;
        p2[i][1]=lower_bound(yidx.begin(),yidx.end(),p2[i][1])-yidx.begin()+1;
        plst[p2[i][1]].push_back(P(p2[i][0],2));
    }
    int ans=0;
    for(int y1=1 ; y1<=(int)yidx.size() ; y1++){
        SegTree T((int)xidx.size());
        for(int y2=y1 ; y2<=(int)yidx.size() ; y2++){
            for(int i=0 ; i<(int)plst[y2].size() ; i++){
                P val=plst[y2][i];
                int c=(val.second==1 ? c1 : -c2);
                T.update(val.first,c);
            }
            ans=max(ans,T.get_max());
        }
    }
    printf("%d",ans);
    return 0;
}
