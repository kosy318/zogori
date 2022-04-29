#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

char str[51][1001];
char dna[30];
char dnastr[6]="ATGC";

void main(){

	int i,j,k,t,m,n,midx,out;


	cin>>t;
	while(t--){

		cin>>m>>n;
		for(i=0;i<m;i++){
			cin>>str[i];
		}

		memset(dna,0,sizeof(dna));
		out=0;
		for(i=0;i<n;i++){ //nth
			memset(dna,0,sizeof(dna));
			for(j=0;j<m;j++){ //str
				dna[str[j][i]-'A']++;
			}
			midx=29;
			for(k=0;k<4;k++){
				if(dna[midx]<dna[ dnastr[k]-'A']){
					midx= dnastr[k]-'A';
				}
			}
			out+=(m-dna[midx]);
			//cout<<out<<endl;
			cout<<(char)(midx+'A');
		}
		cout<<endl<<out<<endl;
	}

}