#include <bits/stdc++.h>

#ifdef LOCAL
    #define watch(x) cout<<(#x)<<" is "<<(x)<<'\n'
    #define dashline() cout<<"================\n"
#else
    #define watch(x)
    #define dashline()
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int sz=2048;
const int MAX=sz*2 + 12*2011;
const int MX=2e9;

bool comp(pii e1, pii e2)
{
    if(e1.second==e2.second) return e1.first<e2.first;
    return e1.second<e2.second;
}

struct Node
{
    int val;
    int l,r,id;
};

Node tr[sz*2+11], tr2[sz*2+11];
int tcnt,tcnt2;
int root[2011], root2[2011];
int K,K2;

void resetT()
{
    tcnt=1; tcnt2=1;
    root[K=0]=1; root2[K2=0]=1;
}

void update(int id)
{
    if(!id) return;
    int l=id*2, r=id*2+1;
    tr[id].l=l; tr[id].r=r;
    tr[id].val=tr[l].val+tr[r].val;
    update(id>>1);
}

void update2(int id)
{
    if(!id) return;
    int l=id*2, r=id*2+1;
    tr2[id].l=l; tr2[id].r=r;
    tr2[id].val=tr2[l].val+tr2[r].val;
    update2(id>>1);
}

int update(int val, int pos, int id, int nodeL, int nodeR)
{
    if (pos<nodeL || nodeR<pos) return id;
    Node  &ncur=tr[++tcnt];
    ncur.id= tcnt;
    ncur.val= tr[id].val;
    if (nodeL==nodeR)
    {
        ncur.val+=val;
        return ncur.id;
    }

    int mid=nodeL+nodeR>>1;
    ncur.l=update(val,pos,tr[id].l,nodeL,mid);
    ncur.r=update(val,pos,tr[id].r,mid+1,nodeR);
    ncur.val=tr[ncur.l].val + tr[ncur.r].val;
    return ncur.id;
}

int update2(int val, int pos, int id, int nodeL, int nodeR)
{
    if (pos<nodeL || nodeR<pos) return id;
    Node  &ncur=tr2[++tcnt2];
    ncur.id= tcnt2;
    ncur.val= tr2[id].val;
    if (nodeL==nodeR)
    {
        ncur.val+=val;
        return ncur.id;
    }

    int mid=nodeL+nodeR>>1;
    ncur.l=update2(val,pos,tr2[id].l,nodeL,mid);
    ncur.r=update2(val,pos,tr2[id].r,mid+1,nodeR);
    ncur.val=tr2[ncur.l].val + tr2[ncur.r].val;
    return ncur.id;
}

void update(int val, int pos)
{
    root[K+1]=update(val,pos,root[K],0,sz-1);
    K++;
}

void update2(int val, int pos)
{
    root2[K2+1]=update2(val,pos,root2[K2],0,sz-1);
    K2++;
}

int ask(int l, int r, int id, int nodeL, int nodeR)
{
    if (r<nodeL || nodeR<l) return 0;
    if (l<=nodeL && nodeR<=r) return tr[id].val;
    int mid = nodeL+nodeR>>1;
    return ask(l,r,tr[id].l,nodeL,mid) + ask(l,r,tr[id].r,mid+1,nodeR);
}

int ask2(int l, int r, int id, int nodeL, int nodeR)
{
    if (r<nodeL || nodeR<l) return 0;
    if (l<=nodeL && nodeR<=r) return tr2[id].val;
    int mid = nodeL+nodeR>>1;
    return ask2(l,r,tr2[id].l,nodeL,mid) + ask2(l,r,tr2[id].r,mid+1,nodeR);
}

int ask(int k, int l, int r)
{ return ask(l,r,root[k],0,sz-1);}

int ask2(int k, int l, int r)
{ return ask2(l,r,root2[k],0,sz-1);}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL

    int n1,n2,i,j; cin>>n1;
    int c1,c2;
    pii arr1[1011],arr2[1011];
    pii arr1px[1011],arr1py[1011];
    pii arr2px[1011],arr2py[1011];
    pii arr3p[2022];

    resetT();
    set<int> stx,sty;
    map<int,int> xtor,ytor;
    for(i=1;i<=n1;i++)
    {
        cin>>arr1[i].first>>arr1[i].second;
        stx.insert(arr1[i].first);
        sty.insert(arr1[i].second);
    }
    cin>>n2;
    for(i=1;i<=n2;i++)
    {
        cin>>arr2[i].first>>arr2[i].second;
        stx.insert(arr2[i].first);
        sty.insert(arr2[i].second);
    }
    cin>>c1>>c2;

    int sz=0;
    for(int x:stx)  xtor[x]=++sz;
    sz=0;
    for(int x:sty)  ytor[x]=++sz;

    for(i=1;i<=n1;i++)
    {
        arr1px[i].first=xtor[arr1[i].first]; arr1px[i].second=ytor[arr1[i].second];
        arr1py[i].first=xtor[arr1[i].first]; arr1py[i].second=ytor[arr1[i].second];
    }
    sort(arr1px+1,arr1px+n1+1);
    sort(arr1py+1,arr1py+n1+1,comp);

    for(i=1;i<=n2;i++)
    {
        arr2px[i].first=xtor[arr2[i].first]; arr2px[i].second=ytor[arr2[i].second];
        arr2py[i].first=xtor[arr2[i].first]; arr2py[i].second=ytor[arr2[i].second];
    }
    sort(arr2px+1,arr2px+n2+1);
    sort(arr2py+1,arr2py+n2+1,comp);

    for(i=1;i<=n1;i++)
    {
        arr3p[i] = arr1px[i];
    }
    int nid=1;
    for(i=n1+1;i<=n1+n2;i++)
    {
        arr3p[i] = arr2px[nid++];
    }

    int id=1;

    int val;
    for(i=1;i<=n1+n2;i++)
    {
        val=0;
        if (id<=n1 && arr1py[id].second==i)
        {
            val=1;
            id++;
        }

        update(val,arr1py[id-1].first);
    }

    id=1;
    for(i=1;i<=n1+n2;i++)
    {
        val=0;
        if (id<=n1 && arr2py[id].second==i)
        {
            val=1;
            id++;
        }
        update2(val,arr2py[id-1].first);
    }

    pii xb, yb;
    int ans=-1;
    int cnt1,cnt2;

    for(i=1;i<=n1+n2;i++)
    {
        for(j=i+1;j<=n1+n2;j++)
        {
            xb.first=min(arr3p[i].first,arr3p[j].first);
            xb.second=max(arr3p[i].first,arr3p[j].first);
            yb.first=min(arr3p[i].second,arr3p[j].second);
            yb.second=max(arr3p[i].second,arr3p[j].second);

            cnt1=ask(yb.second,xb.first,xb.second) - ask(yb.first-1,xb.first,xb.second);
            cnt2=ask2(yb.second,xb.first,xb.second) - ask2(yb.first-1,xb.first,xb.second);

            val=cnt1*c1 - cnt2*c2;
            ans=max(ans,val);
        }
    }

    cout<<ans;

    return 0;
}
