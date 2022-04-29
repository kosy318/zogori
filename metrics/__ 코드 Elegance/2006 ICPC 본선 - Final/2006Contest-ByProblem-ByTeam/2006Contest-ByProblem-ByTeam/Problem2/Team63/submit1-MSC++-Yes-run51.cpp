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

char str[60][1001];

int main()
{
	int T;
	cin >> T;
	while(T--) {
		int diff_num=0;
		int freq['Z'-'A'+1];
		int row, col;
		cin >> row >> col;;
		REP(i, row) {
			scanf("%s", str[i]);
		}
		REP(i, col) {
			memset(freq, 0, sizeof(freq));
			REP(j, row) {
				freq[str[j][i]-'A']++;
			}
			
			int max_cnt=0;
			int max_idx=0;
			
			FOR(j, 0, 'Z'-'A'+1){
				if(max_cnt < freq[j]) {
					max_cnt=freq[j];
					max_idx=j;
				}
			}
			printf("%c", max_idx+'A');
			diff_num+=row-max_cnt;
		}
		cout << endl;
		cout << diff_num << endl;
	}
  return 0;
}
