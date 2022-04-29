#include<bits/stdc++.h>
using namespace std;
const int mxn=100010;
int m,n,x[mxn],c[mxn],lft[mxn],rht[mxn],dp[mxn];
int tree[mxn*4];
int query(int h,int l, int r,int gl,int gr){
    if(r<gl || gr<l) return 1e9;
    else if(gl<=l && r<=gr){
        return tree[h];
    }
    int mid = (l+r)/2;
    return min(query(h*2+1,l,mid,gl,gr),query(h*2+2,mid+1,r,gl,gr));
}
void update(int h,int l,int r,int g,int value){
    if(g<l || r<g) return;
    if(l==r){
        tree[h]=min(tree[h],value);
        return;
    }
    int mid=(l+r)/2;
    update(h*2+1,l,mid,g,value);
    update(h*2+2,mid+1,r,g,value);
    tree[h]=min(tree[h*2+1],tree[h*2+2]);
}
int main()
{
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1; i<=n; i++) scanf("%d",x+i);
    for(int i=1; i<=n; i++) scanf("%d",c+i);
    for(int i=1; i<=n; i++){
        if(c[i]==c[i-1]){
            lft[i]=lft[i-1];
            rht[i]=rht[i-1];
            continue;
        }
        lft[i]=rht[i]=i;
        for(int j=i+1; j<=n; j++){
            if(c[j]==c[i]){
                rht[i]=j;
            }
            else break;
        }
    }
    fill(tree, tree+mxn*4, 1e9);
    for(int i=lft[1]; i<=rht[1]; i++){
        dp[i]=1;
        update(0,1,n,i,1);
    }
    for(int i=rht[1]+1; i<=n; i++){
        dp[i]=1e9;
        int l,r;
        l=lft[i];
        r=i-1;
        if(l<=r) dp[i]=min(dp[i],query(0,1,n,l,r)+1);
        int pl=lft[lft[i]-1], pr=rht[lft[i]-1];
        l=lower_bound(x+pl,x+pr+1,2*x[pr]-x[i])-x;
        r=upper_bound(x+pl,x+pr+1,2*x[lft[i]]-x[i])-x-1;
        if(l<=r) dp[i]=min(dp[i],query(0,1,n,l,r)+1);
        update(0,1,n,i,dp[i]);
    }
    printf("%d",query(0,1,n,lft[n],rht[n]));
    return 0;
}
