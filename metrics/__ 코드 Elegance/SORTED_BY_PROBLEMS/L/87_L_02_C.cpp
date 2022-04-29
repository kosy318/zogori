#include <iostream>
#include <algorithm>
#include <vector>
using  namespace std;

class Appear{
public:
    int s, e, t, profit;

    Appear(int _s, int _e, int _t, int p){
        s=_s;
        e=_e;
        t=_t;
        profit = p;
    };
};

int price[105];
int dp[15005];
vector<Appear> appears;
int m, n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> price[i];
    }

    int max_e = -1;
    int e, s, t;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e >> t;
        appears.push_back(Appear(s, e, t-1, (e-s)*price[t-1]));
        if (e > max_e)
            max_e = e;
    }

    sort(appears.begin(), appears.end(), [](Appear& l, Appear& r){ return l.e < r.e;});

    for(auto& a : appears){
        if (dp[a.s] + a.profit > dp[a.e]){
            int new_profit = dp[a.s] + a.profit;
            for (int i = a.e; i <= max_e && new_profit > dp[i]; ++i) {
                dp[i] = new_profit;
            }
        }
    }

    cout << dp[max_e] << '\n';
    return 0;
}