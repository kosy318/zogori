#include <iostream>
#include <cstring>
using namespace std;
int m[1011][1011];
int des,des2;
int ss2;
int n ; 
int reach;
bool visited[1011];
int d1,d2,s1,s2,f;

void sgo2(int ii)
{
	if ( ii == d1 )
	{
		reach =1;
		return ;
	}
	if (reach) return ; 
	for ( int i = 0 ;  i < n; i++)
	{
				if ( ii == i ) continue;
		if (visited[i] == false && m[ii][i] )
		{
			visited[i]=true;
			sgo2(i);
			visited[i]=false;
		}
	}
}



void sgo(int ii)
{
	if (reach ) return;
	if ( ii == d2)
	{
		sgo2(s2);
		return ;
	}
	for ( int i = 0 ;  i < n; i++)
	{
				if ( ii == i ) continue;
		if (visited[i] == false && m[ii][i] )
		{
			visited[i]=true;
			sgo(i);
			visited[i]=false;
		}
	}
}


void go2(int ii)
{
	if ( ii == d2 )
	{
		reach =1;
		return ;
	}
	if (reach) return ; 
	for ( int i = 0 ;  i < n; i++)
	{
				if ( ii == i ) continue;
		if (visited[i] == false && m[ii][i] )
		{
			visited[i]=true;
			go2(i);
			visited[i]=false;
		}
	}
}
void gog(int ii , int dess) 
{
	if (reach ) return;
	if ( ii == dess)
	{
		reach = 1;
		return ;
	}
	for ( int i = 0 ;  i < n; i++)
	{
		if ( ii == i ) continue;
		if (visited[i] == false && m[ii][i] )
		{
			visited[i]=true;
			gog(i,dess);
			visited[i]=false;
		}
	}
}


void go(int ii) 
{
	if (reach ) return;
	if ( ii == d1)
	{
		go2(s2);
		return ;
	}
	for ( int i = 0 ;  i < n; i++)
	{
		if ( ii == i ) continue;
		if (visited[i] == false && m[ii][i] )
		{
			visited[i]=true;
			go(i);
			visited[i]=false;
		}
	}
}

int main()
{
	int mm,t ;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d %d",&n,&mm);
		memset(m,0,sizeof(m));
		while (mm--)
		{
			int fr,to;
			scanf("%d %d",&fr,&to);
			m[fr][to] =m[to][fr] = 1;
		}
		scanf("%d %d %d %d",&s1,&s2,&d1,&d2);
		scanf("%d",&f);
		while(f--)
		{
			int fr,to;
			scanf("%d %d",&fr,&to);
			m[fr][to]=m[to][fr] = 0;
		}
		reach = 0 ;
		memset(visited,false,sizeof(visited));
		if (s1==d1) 
		{
			visited[s1] = visited[s2] = visited[d1]  = 1;
			gog(s2,d2);
			if ( reach) goto yes;
			else goto no;
		}
		else if (s1 == d2)
		{
			visited[s1] = visited[s2] =  visited[d2] = 1;
			gog(s2,d1);
			if ( reach) goto yes;
			else goto no;
		}
		else if (s2 == d1)
		{
			visited[s1] = visited[s2] = visited[d2] = 1;
			gog(s1,d2);
			if ( reach) goto yes;
			else goto no;
		}
		else if (s2 == d2)
		{
			visited[s1] = visited[s2] = visited[d1]  = 1;
			gog(s1,d1);
			if ( reach) goto yes;
			else goto no;
		}
		 
		 

		des = d1; 
		des2 = d2;
		ss2 = s2;
		reach = 0 ; 
		memset(visited,false,sizeof(visited));
		visited[s1] = visited[s2] =1;
		 
		go(s1);
		
		if ( reach ) goto yes;
		cout << "2nd" << endl;
		ss2 = s1;
		memset(visited,false,sizeof(visited));
		visited[s1] = visited[s2] =1;
		reach = 0; 
		sgo(s2);
		if (reach) goto yes;
no:
		puts("NO");
		continue;
yes:
		puts("YES");


	}


	return 0 ;
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
*/