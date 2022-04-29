#include <iostream>
#include <algorithm>

#define N 15000
#define M 100
using namespace std;

struct Mineral
{
    int s, e, type;

    bool operator< (Mineral& b)
    const {
        return e < b.e;
    }
};
typedef long long ll;

ll dp[N+5];
ll price[M+5];
Mineral mine[N+5];


int n, m;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, e, type;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> price[i];
    }

    for(int i=0;i<m;i++){
        cin >> s >> e >> type;
        mine[i] = {s, e, type};
    }

    sort(mine, mine+m);

    int j = 0;
    for(int i=0;i<N;i++){
        if(i != 0) dp[i] = dp[i-1];
        while(j < m && mine[j].e < i) j++;

        while(j < m && mine[j].e == i) {
            s = mine[j].s;
            e = mine[j].e;
            type = mine[j].type;

            dp[i] = max(dp[i], dp[s] + (e - s) * price[type]);
            j++;
        }
    }

    cout << dp[N-1];


    return 0;
}

