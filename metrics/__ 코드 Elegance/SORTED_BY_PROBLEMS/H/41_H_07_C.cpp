#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n_1, n_2;
ll c_1, c_2;
ll X_1[1111];
ll Y_1[1111];
ll X_2[1111];
ll Y_2[1111];
vector<ll> X, Y;
vector< pair<ll, ll> > CC[2555];
ll ans;

struct node
{
	ll Lsum, Rsum;
	ll sum, val;
};

node tree[28888];

node creator(ll v)
{
	node ret;
	ret.Lsum=v; ret.Rsum=v;
	ret.sum=v; ret.val=v;
	return ret;
}
	
node merge(node A, node B)
{
	node ret;
	ret.Lsum=max(A.Lsum, A.sum+B.Lsum);
	ret.Rsum=max(B.Rsum, B.sum+A.Rsum);
	ret.sum=A.sum+B.sum;
	ret.val=max(A.val, B.val);
	ret.val=max(ret.val, A.Rsum+B.Lsum);
	return ret;
}

void tree_clear(int index, int s, int e)
{
	if(s==e)
	{
		tree[index]=creator(0);
		return;
	}
	tree[index]=creator(0);
	int m=(s+e)/2;
	tree_clear(index<<1, s, m);
	tree_clear(index<<1|1, m+1, e);
}

void update(int index, int s, int e, int loc, ll v)
{
	if(s>loc || loc>e) return;
	if(s==loc && e==loc)
	{
		tree[index].sum+=v;
		tree[index].Lsum+=v;
		tree[index].Rsum+=v;
		tree[index].val+=v;
		return;
	}
	int m=(s+e)/2;
	update(index<<1, s, m, loc, v);
	update(index<<1|1, m+1, e, loc, v);
	tree[index]=merge(tree[index<<1], tree[index<<1|1]);
}

int main(void)
{
	fio; ll i, j, k;
	cin>>n_1; ans=0;
	for(i=1 ; i<=n_1 ; i++) cin>>X_1[i]>>Y_1[i];
	cin>>n_2;
	for(i=1 ; i<=n_2 ; i++) cin>>X_2[i]>>Y_2[i];
	cin>>c_1>>c_2;
	for(i=1 ; i<=n_1 ; i++) X.push_back(X_1[i]), Y.push_back(Y_1[i]);
	for(i=1 ; i<=n_2 ; i++) X.push_back(X_2[i]), Y.push_back(Y_2[i]);
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	for(i=1 ; i<=n_1 ; i++) X_1[i]=lower_bound(X.begin(), X.end(), X_1[i])-X.begin()+1;
	for(i=1 ; i<=n_2 ; i++) X_2[i]=lower_bound(X.begin(), X.end(), X_2[i])-X.begin()+1;
	for(i=1 ; i<=n_1 ; i++) Y_1[i]=lower_bound(Y.begin(), Y.end(), Y_1[i])-Y.begin()+1;
	for(i=1 ; i<=n_2 ; i++) Y_2[i]=lower_bound(Y.begin(), Y.end(), Y_2[i])-Y.begin()+1;
	for(i=1 ; i<=n_1 ; i++) CC[Y_1[i]].push_back(make_pair(X_1[i], c_1));
	for(i=1 ; i<=n_2 ; i++) CC[Y_2[i]].push_back(make_pair(X_2[i], -c_2));
	for(i=1 ; i<=2010 ; i++)
	{
		tree_clear(1, 1, 2010);
		for(j=i ; j<=2010 ; j++)
		{
			for(k=0 ; k<CC[j].size() ; k++) update(1, 1, 2010, CC[j][k].first, CC[j][k].second);
			node VV = tree[1];
			ans=max(ans, VV.val);
		}
	}
	cout<<ans; return 0;
}
