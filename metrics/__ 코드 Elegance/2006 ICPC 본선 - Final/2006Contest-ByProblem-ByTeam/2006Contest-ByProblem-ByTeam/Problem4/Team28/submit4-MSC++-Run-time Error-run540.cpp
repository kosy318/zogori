#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int cn[1001][1001];
int mix[1001][1001];
int ved[1001];
int n,m;
int start;
bool flag;
int cnt;

bool dfs(int v){
	int i,j,tmp,tmp2;
	bool find=false;

	if(start==v && flag && cnt==2) return true;
	if(!flag) flag=true;

	if(ved[v]) return false;

	ved[v]=true;
	//if(mix[v][0] || mix[v][1]){ 
	for(i=1;i<=n;i++){
		if(mix[v][i]){
			mix[v][i]=mix[i][v]=0;
			cn[v][i]=cn[i][v]=0;
			find=true;
			cnt++;
			if(dfs(i)) return true;
			cnt--;
			mix[v][i]=mix[i][v]=1;
			cn[v][i]=cn[i][v]=1;
		}
	}
	if(!find){
		for(i=1;i<=n;i++){
			if(cn[v][i]){
				if( dfs(i) ) return true;
			}
		}
	}
	ved[v]=false;
	return false;
}


void main(){

	int i,j,k,l,t,u,a,b;


	cin>>t;
	while(t--){
		memset(mix,0,sizeof(mix));
		memset(cn,0,sizeof(cn));
		memset(ved,0,sizeof(ved));

		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>j>>k;
			cn[j][k]=1;
			cn[k][j]=1;
		}
		cin>>i>>j>>k>>l;

		mix[i][j]=1;
		mix[j][i]=1;
		mix[k][l]=1;
		mix[l][k]=1;

		cin>>u;
		while(u--){
			cin>>a>>b;
			cn[a][b]=0;
			cn[b][a]=0;
		}
		flag=false;
		cnt=0;
		start=i;
		if(dfs(i)){
			cout<<"YES"<<endl;
			continue;
		}
		else
		{
			cout<<"NO"<<endl;
			continue;
		}
	}
}
/*
mix[i]=j;
			mix[j]=i;
			mix[k]=l;
			mix[l]=k;
			flag=false;
			cnt=0;
			start=j;
			memset(ved,0,sizeof(ved));
			if(dfs(j) && cnt==2){
				cout<<"YES"<<endl;
				continue;
			}
			else
			{
				mix[i]=j;
				mix[j]=i;
				mix[k]=l;
				mix[l]=k;
				flag=false;
				cnt=0;
				start=k;
				memset(ved,0,sizeof(ved));
				if(dfs(k) && cnt==2){
					cout<<"YES"<<endl;
					continue;
				}
				else
				{
					mix[i]=j;
					mix[j]=i;
					mix[k]=l;
					mix[l]=k;
					flag=false;
					cnt=0;
					start=l;
					memset(ved,0,sizeof(ved));
					if(dfs(l) && cnt==2){
						cout<<"YES"<<endl;
						continue;
					}
					else
					{
						cout<<"NO"<<endl;
					}
				}
			}


			*/

/*
		tmp=mix[v];
		tmp2=mix[tmp];
		mix[v]=0;
		if(mix[tmp]==v) mix[tmp]=0;
		
		cn[v][tmp]=0;
		cn[tmp][v]=0;
		cnt++;
		if(dfs(tmp))
			return true;
		else {
			cnt--;
			mix[v]=tmp;
			if(mix[tmp]==v) mix[tmp]=tmp2;
			cn[v][tmp]=1;
			cn[tmp][v]=1;
			ved[v]=false;
			return false;
			
		}
	}
	else{
		for(i=1;i<=n;i++){
			if(cn[v][i]){
				if( dfs(i) ) return true;
			}
		}
	}
	*/