#include<cstdio>
#include<cstring>

void dfs();
int dif(int,int,int,int);

int chk[1001];
int ch[1001];
int n,k;
int sa,sb,da,db;
int dt[1001][1001];
int end;

int main()
{
	int t,i,j,m;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		memset(dt,0,sizeof(dt));
		for (i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			dt[a][b]=dt[b][a]=1;
		}
		scanf("%d%d%d%d",&sa,&sb,&da,&db);
		scanf("%d",&m);
		for (i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			dt[a][b]=dt[b][a]=0;
		}
		memset(ch,0,sizeof(ch));
		memset(chk,0,sizeof(chk));
		k=0;
		end=0;
		dfs();
		if (end)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int stk[1000005][2],sp;

void dfs()
{
	int i,j,ka;

	sp=0;
	stk[sp][0]=1;
	stk[sp++][1]=0;
	while (sp) {
		sp--;
		ka=stk[sp][0];
		i=stk[sp][1];
		if (!i) {
			if (chk[ka]==1 && ch[ka]==0 && k==2) {
				end=1;
				return;
			}
			chk[ka]=1;
			ch[ka]=k;
		}
		for (;i<=n;i++)
			if (dt[ka][i]==1) {
				if (dif(ka,i,sa,sb)==0 || dif(ka,i,da,db)==0) {
					k++;
				}
				dt[ka][i]=dt[i][ka]=0;
				stk[sp][0]=ka;
				stk[sp++][1]=i;
				stk[sp][0]=i;
				stk[sp++][1]=0;
				break;
			}
	}
}

int dif(int a,int b,int c,int d)
{
	int t;

	if (a==c && b==d)
		return 0;
	t=c,c=d,d=t;
	if (a==c && b==d)
		return 0;
	return 1;	
}

/*
3
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
3 5
2 4
1
6 5
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6 
5 6
2 3
3 5
1
4 2
5 4
1 2
2 3
3 4
4 5
1 2
4 5
2 
2 3
3 4

1
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6 
5 6
2 3
3 5
1
4 2

*/