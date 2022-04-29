#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

//#define CODING

#ifdef CODING
ifstream fin("input.txt");
#else
istream &fin = cin;
#endif

int N,M,F; // nb of node

vector<int> link[2002];
#define sink (N*2+1)
inline int in(int n)
{
	return n;
}

inline int out(int n)
{
	return N+n;
}


int queue[30000];
int front,rear;

void push(int v) { queue[rear++ % 30000 ] = v; }
int pop() { return queue[front++ % 30000 ]; }

map<pair<int,int>,int> capacity,flow;
set<pair<int,int> > toll;

bool findflow()
{
	int i;
	bool flag[2048];
	int parent[2048];
	front = rear = 0;	
	push(0); 

	fill(flag,flag+2*N+2,false);
	fill(parent,parent+2*N+2,-1);
	flag[0] = true;

	int p;
	while ( rear != front )
	{
		p = pop();// curr node nb
		if ( p == sink ) break;
		for ( int i=0;i<link[p].size();i++)
		{
			if ( !flag[ link[p][i] ] && capacity[ make_pair(p, link[p][i]) ] - flow[ make_pair(p, link[p][i]) ] > 0 )
			{ // flowable;
				push( link[p][i] );
				flag[link[p][i]] = true;
				parent[ link[p][i] ] = p;
			}
		}
	}
	if ( parent[ sink ] == -1 )  
	{ // fail		
		return false;
	}
	else
	{
		//int stack[3000];
		int cnt = 0;
		p = sink;
		while ( p != 0 )
		{
			flow[ make_pair(parent[p],p) ] = 1;
			flow[ make_pair(p,parent[p]) ] = -1;
			//stack[cnt++] = p;
			p = parent[p];
		}
		return true;
	}
}

void process()
{
	if ( findflow() && findflow() ) 
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

bool flag[1001];
bool graph[1001][1001];
int a,b,c;
bool dfs(int node)
{
	int i;
	if ( node == c ) 
		return true;
	flag[ node ] = true;
	for (i=1;i<=N;i++)
	{
		if ( !flag[i] && graph[node][i] ) 
		{
			if ( dfs(i) )
				return true;
		}
	}
	return false;
}
short edge[500000][2];
int main()
{
	int T;	
	
	fin >> T;
	for (int i=0;i<T;i++)
	{
		int j,k;
		capacity.clear();
		flow.clear();
		toll.clear();

		fin >> N >> M;
		for (j=1;j<=N;j++)
		{
			for (k=1;k<=N;k++)
				graph[j][k] = false;
		}
		for (j=0;j<=2*N+1;j++) 
		{
			link[j].clear();
		}
		for (j=1;j<=N;j++)
		{
			link[in(j)].push_back( out(j) );
			link[ out(j) ].push_back( in(j) );
			capacity[ make_pair(in(j),out(j)) ] = 1;
			flow[ make_pair(in(j),out(j)) ] = 0;
		}
		for (int j=0;j<M;j++)
		{
			int a,b;
			fin >> a >> b;
			edge[j][0] = a;
			edge[j][1] = b;
		}
		int a1,b1;
		int a2,b2;
		fin >> a1 >> b1; // to visit 1
		link[0].push_back( in(a1) );// S->a
		link[0].push_back( in(b1) );// S->b
		link[ in(a1) ].push_back( 0 ); // a-> S
		link[ in(b1) ].push_back( 0 ); // b-> S
		
		capacity[ make_pair(0,in(a1)) ] = 1;
		flow[ make_pair(0,in(a1)) ] = 0;
		capacity[ make_pair(0,in(b1)) ] = 1;
		flow[ make_pair(0,in(b1)) ] = 0;
		
		fin >> a2 >> b2; // to visit 2
		link[ out(a2) ].push_back( sink ); // a ->S
		link[ out(b2) ].push_back( sink ); // b ->S
		link[sink].push_back( out(a2) ); // S->a
		link[sink].push_back( out(b2) );
		fin >> F;
		for (int j=0;j<F;j++)
		{
			int a,b;
			fin >> a >> b;
			toll.insert( make_pair(a,b) );
			toll.insert( make_pair(b,a) );
		}
		for (int j=0;j<M;j++)
		{
			int a,b;
			a = edge[j][0];
			b = edge[j][1];
			if ( toll.find( make_pair(a,b) ) != toll.end() ) continue; // this is toll road
			link[out(a)].push_back( in(b) ); // a -> b
			link[in(b)].push_back( out(a) );
			capacity[ make_pair(out(a),in(b)) ] = 1;

			link[out(b)].push_back( in(a) );
			link[in(a)].push_back( out(b) );
			capacity[ make_pair(out(b),in(a)) ] = 1;

			graph[a][b] = true;
			graph[b][a] = true;
		}

		if ( a1 == a2 || a1 == b2 || b1 == a2 || b1 == b2 ) 
		{
			int k;

			for (j=1;j<=N;j++)
			{
				flag[j] = false;					
			}
			if ( a1 == a2 ) 
			{
				b = a1;
				a = b1;
				c = b2;
			}
			if ( a1 == b2 )
			{
				b = a1;
				a = a2;
				c = b1;
			}
			if ( b1 == a2 )
			{
				a = a1;
				b = b1;
				c = b2;
			}
			if ( b1 == b2 )
			{
				a = a1;
				b = b1;
				c = a2;
			}
			flag[b] = true;
			if ( dfs(a) )	cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}
		capacity[ make_pair(out(a2),sink) ] = 1;
		flow[ make_pair(out(a2),sink) ] = 0;
		capacity[ make_pair(out(b2),sink) ] = 1;
		flow[ make_pair(out(b2),sink) ] = 0;

		
		process();
	}
	return 0;
}