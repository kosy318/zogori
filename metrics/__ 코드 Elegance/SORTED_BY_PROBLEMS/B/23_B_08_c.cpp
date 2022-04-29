#include<stdio.h>
#include<utility>
#include<algorithm>
#include<vector>
#define MaxN 100001

using namespace std;

bool visited[MaxN];
vector<pair<int,long long> > d[MaxN];
int deg[MaxN],n;
long long ans;

pair<long long,pair<long long,long long> > DFS(int here)
{
	int i,there;
	long long s=0,sq=0,childNum=0,A=0,B=0,C=0,D=0,E=0;
	pair<long long,pair<long long,long long> > getSums;

	visited[here] = 1;

	for(i=0; i<d[here].size(); i++){

		there = d[here][i].first;

		if(!visited[there]){
			getSums = DFS(there);

			childNum += getSums.first;
			s += ((getSums.second).first + getSums.first * d[here][i].second);

			A += ((getSums.second).first + getSums.first * d[here][i].second);
			B += ((getSums.second).first + getSums.first * d[here][i].second) * ((getSums.second).first + getSums.first * d[here][i].second);
			C += getSums.first;
			D += ((getSums.second).second + 2 * (getSums.second).first * d[here][i].second + getSums.first * d[here][i].second * d[here][i].second);
			E += getSums.first * (((getSums.second).second + 2 * (getSums.second).first * d[here][i].second + getSums.first * d[here][i].second * d[here][i].second));
			sq += ((getSums.second).second + 2 * (getSums.second).first * d[here][i].second + getSums.first * d[here][i].second * d[here][i].second);
		}
	}
//	printf("node %d : Childs(%d) Sum(%d), SqSum(%d), Score(%d)\n",here,childNum,s,sq,(A*A-B) + (C*D-E));
	
	if(childNum != 0) ans += ((A*A-B) + (C*D-E));
	return make_pair((childNum==0?1:childNum), make_pair(s,sq) );
}
		
int main()
{
	int i,a,b,c;

	scanf("%d",&n);

	for(i=1; i<n; i++){
		scanf("%d%d%lld",&a,&b,&c);
		deg[a]++; deg[b]++;
		d[a].push_back(make_pair(b,c));
		d[b].push_back(make_pair(a,c));
	}
	
	for(i=1; i<=n; i++) if(deg[i] != 1) {DFS(i); break;}

	printf("%lld\n",ans);
	return 0;
}
