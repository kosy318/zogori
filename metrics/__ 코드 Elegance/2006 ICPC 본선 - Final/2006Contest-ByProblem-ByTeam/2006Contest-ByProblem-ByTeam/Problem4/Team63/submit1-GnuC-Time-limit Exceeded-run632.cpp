#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstddef>

using namespace std;

#define FOR(V,I,L) for(int V=(I); V<(L); V++)
#define REP(V,L) FOR(V,0,L)
#define ITER(adt, type) adt<type>::iterator
#define FOR_EACH(I,C) for(__typeof((C).begin()) I=(C).begin(); I!=(C).end(); ++I)

#define ASSERT(x) ((x)?0:*(int *)0=0)

struct edge
{
  int u, v;
};

bool adj[1000][1000];

#define NMAX 2002
int N;
set<int> forward[NMAX];
set<int> backward[NMAX];
int cap[NMAX][NMAX];
int flow[NMAX][NMAX];
int cost[NMAX][NMAX];
int src;
int sink;
inline int IN(int v)
{
  return 2*v;
}

inline int OUT(int v)
{
  return 2*v+1;
}
inline void CONNECT(int u, int v)
{
  ASSERT( 0 <= u && u < N );
  ASSERT( 0 <= v && v < N );
  forward[u].insert(v);
  backward[v].insert(u);
}

inline void CONNECT(int u, int v, int c)
{
  CONNECT(u, v);
  cap[u][v] = c;
}

int augment()
{
  queue<int> q;
  int pre[N];
  bool visited[N];
  REP(i, N)
    visited[i] = false;
  visited[src] = true;
  q.push(src);
  ASSERT(pre[src]=-1);
  while ( !q.empty() )
  {
    int u = q.front();
    if ( u == sink )
      break;

    q.pop();
      
    FOR_EACH(v,forward[u])
      {
	if ( !visited[*v] && cap[u][*v] - flow[u][*v] > 0 )
	{
	  visited[*v] = true;
	  q.push(*v);
	  pre[*v] = u;
	}
      }
    FOR_EACH(w,backward[u])
      {
	if ( !visited[*w] && flow[*w][u] > 0 )
	{
	  visited[*w] = true;
	  q.push(*w);
	  pre[*w] = u;
	}
      }
  }

      
  if ( q.empty() )
    return 0;
      
  int aug = 1;
  int x = q.front();
  while ( x != src )
  {
    int u = pre[x];
    int a = aug;
    int b = cap[u][x] - flow[u][x];
    if ( b > 0 )
    {
      flow[u][x] += min(a,b);
      a -= b;
    }
    if ( a > 0 )
      flow[x][u] -= a;
    x = pre[x];
  }

  return aug;
}

int main()
{
  int T;
  cin >> T;
  REP (t, T)
    {
      int C, M;
      cin >> C; // city
      cin >> M; // road
      REP(i,C)
	REP(j,C)
	adj[i][j] = false;

      REP (i, M)
	{
	  int u, v;
	  cin >> u >> v;
	  u--;v--;
	  adj[u][v] = adj[v][u] = true;
	}
      
      int src1, src2, sink1, sink2;
      cin >> src1 >> src2 >> sink1 >> sink2;

      src1--;
      src2--;
      sink1--;
      sink2--;

      adj[src1][src2] = false;
      adj[src2][src1] = false;
      adj[sink1][sink2] = false;
      adj[sink2][sink1] = false;

      int F;
      cin >> F;
      REP (i,F)
	{
	  int u, v;
	  cin >> u >> v;
	  u--;v--;
	  adj[u][v] = adj[v][u] = false;
	}

      N = 2*C+2;

      REP(i,N)
	{
	  forward[i].clear();
	  backward[i].clear();
	}

      REP(i,N)
	REP(j,N)
	cap[i][j] = flow[i][j] = cost[i][j] = 0;

      src = N-2;
      sink = N-1;

      REP (i, (N-2)/2)
	CONNECT(IN(i),OUT(i),1);

      REP(i,C)
	REP(j,C)
	if ( adj[i][j] )
	  CONNECT(OUT(i),IN(j),1);
      
      CONNECT(src,IN(src1),1);
      CONNECT(src,IN(src2),1);
      CONNECT(OUT(sink1),sink,1);
      CONNECT(OUT(sink2),sink,1);

      if ( augment() == 1 && augment() == 1 )
	cout << "YES" << endl;
      else
	cout << "NO" << endl;

    }
  return 0;
}
