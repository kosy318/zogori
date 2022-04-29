#include <bits/stdc++.h>
using namespace std;

list< pair<int,int> > mine_info[15001];  //end time, price of this mineral
int mine_price[100] = {0,};
int max_price[15001] = {0,};

int dp(int start,int end_p){
    vector<int> ans;

    if(max_price[start] == -1){
        for(auto s:mine_info[start]){
            int gap = s.first - start;
            ans.push_back( s.second*gap + dp(s.first,end_p) );
        }
        if(start < end_p) ans.push_back( dp(start+1,end_p) );
        else{
            max_price[start] = 0;
            return 0;
        }

        sort(ans.begin(),ans.end());
        max_price[start] = ans.back();

        //cout << start << ' ' << max_price[start] << '\n';
    }

    return max_price[start];
}

int main()
{
    //freopen("input.txt","r",stdin);
    int m,n,end_p=0;
    cin >> m >> n;

    memset(mine_price, -1, sizeof(mine_price));
    memset(max_price, -1, sizeof(max_price));

    for(int i=0;i<m;i++){
        cin >> mine_price[i];
    }

    for(int i=0,b,e,k;i<n;i++){
        cin >> b >> e >> k;
        mine_info[b].push_back( make_pair(e,mine_price[k-1]) );

        if(end_p < e) end_p = e;
    }

    cout << dp(0,end_p);
    return 0;
}
