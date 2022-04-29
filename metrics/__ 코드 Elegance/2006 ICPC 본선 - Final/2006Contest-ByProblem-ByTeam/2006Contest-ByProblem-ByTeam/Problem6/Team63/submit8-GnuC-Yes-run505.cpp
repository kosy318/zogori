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
#define FOR_EACH(I,C) for(I=(C).begin(); I!=(C).end(); ++I)

#define ASSERT(x) ((x)?0:*(int *)0=0)

int main()
{
  int T;
  cin >> T;
  REP (t, T)
  {
    int N;
    cin >> N;
    int a[N], b[N];
    REP (n, N)
    {
      cin >> a[n] >> b[n];
    }
    
    int M;
    cin >> M;
    
    long double prod = 1;
    REP (i, N)
    {
      prod *= a[i];
    }

    long double R = M*prod;
    REP (i, N)
    {
      R += (long double)b[i]/a[i]*prod;
    }
//       cout << R << " ";

    long double C = 0;
    REP (i, N)
    {
      C += (long double)prod/a[i];
    }
//       cout << C << " ";

    int G = (int)(R/C+0.5);

//     cout << G << " " ;

    int semi_M = 0;
    REP (i, N)
    {
      int x = (G-b[i])/a[i];
//       cout << x << " ";
      if ( x < 0 )
	goto FAIL;
      semi_M += (G-b[i])/a[i];
      if ( x*a[i]+b[i] != G )
	goto FAIL;
    }

    if ( semi_M != M )
      goto FAIL;

    cout << G << endl;
    continue;
  FAIL:
    cout << 0 << endl;
  }
  return 0;
}
