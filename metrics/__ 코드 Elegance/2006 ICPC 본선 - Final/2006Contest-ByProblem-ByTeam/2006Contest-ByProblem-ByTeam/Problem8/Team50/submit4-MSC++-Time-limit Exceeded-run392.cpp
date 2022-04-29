#include <stdio.h>
#include <string.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))


int lcs(char s1[], char s2[]) {
	int l1,l2,table[200][200];
	int i,j;
	l1=strlen(s1);
	l2=strlen(s2);
	
	for (i=0; i<=l1; i++) table[i][0]=i;
	for (i=0; i<=l2; i++) table[0][i]=i;
	for (i=1; i<=l1; i++) {
		for (j=1; j<=l2; j++) {
			table[i][j]=min(table[i-1][j],table[i][j-1])+1;
			table[i][j]=min(table[i][j],table[i-1][j-1]+1);
			if (s1[i-1]==s2[j-1]) table[i][j]=min(table[i][j],table[i-1][j-1]);
			
		}
	}
	return table[l1][l2];
}
void main() {
	int m,l1,l2,maxx,i,j,ll,cost;
	char s1[51],s2[5001];
	char temp[200];
	int table[5001];
	scanf("%d",&m);
	for (ll=1; ll<=m; ll++) {
		scanf("%s",s1);
		scanf("%s",s2);
		l1=strlen(s1);
		l2=strlen(s2);
		table[0]=2100000;
		for (i=1; i<=l2; i++) table[i]=2100000;
		for (i=1; i<=l1; i++) {
			if (i>l2) break;
			strncpy(temp,s2,i);
			temp[i]='\0';
			table[i]=lcs(temp,s1);
		}
		for (i=1; i<=l2; i++) {
			for (j=l1/2; j<=l1*2-1; j++) {
				if (i-j<0) continue;
				strncpy(temp,s2+(i-j),j);
				temp[j]='\0';
				cost=lcs(temp,s1);
				if (table[i]==2100000) {
					if (cost<table[i]) {
						table[i]=cost;
					}
				}
				else {
					maxx=max(cost,table[i-j]);
					if (maxx<table[i]) table[i]=maxx;
				}
			}
		}
		printf("%d\n",table[l2]);
	}
}
