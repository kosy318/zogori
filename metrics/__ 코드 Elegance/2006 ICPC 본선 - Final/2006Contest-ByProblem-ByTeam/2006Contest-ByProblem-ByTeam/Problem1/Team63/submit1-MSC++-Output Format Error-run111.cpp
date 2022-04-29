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

short table[240001]={0,};

int calcu_to_end(int time);
int calcu_from_start(int time);


int main()
{
	int T;
	cin >> T;

	FOR(i, 0, 240000+1) {
		if(i%3==0)
			table[i]=1;
	}

	while(T--) {
		int start_num=0, end_num=0;
		char start_clk[15];
		char end_clk[15];

		scanf("%s %s", start_clk, end_clk);
        
		start_num+=(start_clk[0]-'0')*100000;
		start_num+=(start_clk[1]-'0')*10000;
		start_num+=(start_clk[3]-'0')*1000;
		start_num+=(start_clk[4]-'0')*100;
		start_num+=(start_clk[6]-'0')*10;
		start_num+=(start_clk[7]-'0')*1;

		end_num+=(end_clk[0]-'0')*100000;
		end_num+=(end_clk[1]-'0')*10000;
		end_num+=(end_clk[3]-'0')*1000;
		end_num+=(end_clk[4]-'0')*100;
		end_num+=(end_clk[6]-'0')*10;
		end_num+=(end_clk[7]-'0')*1;
		
		cout << start_num << " " << end_num << endl;

		int cnt=0;

		if(start_num < end_num) {
			FOR(i,start_num, end_num+1){
				if( (i/100)%100 >= 60)
					continue;
				if(i%100 >=60)
					continue;
				if(table[i]==1)
					cnt++;
			}
		}
		else if(start_num > end_num) {
			cnt+=calcu_to_end(start_num);
			cnt+=calcu_from_start(end_num);
		}
		cout << cnt << endl;
	}
  return 0;
}

int calcu_from_start(int time) {
	int cnt=0;
	FOR(i,0, time+1){
		if( (i/100)%100 >= 60)
			continue;
		if(i%100 >=60)
			continue;
		if(table[i]==1)
			cnt++;
	}
	return cnt;
}

int calcu_to_end(int time) {
	int cnt=0;
	FOR(i,time, 240000){
		if( (i/100)%100 >= 60)
			continue;
		if(i%100 >=60)
			continue;
		if(table[i]==1)
			cnt++;
	}
	return cnt;
}