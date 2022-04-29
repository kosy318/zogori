//Prob L

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

struct ore{
    int s;
    int e;
    long long price;
};
int price[110]={0,};
vector<ore> info;
long long dp[10001][2];

bool sort_ore(ore o1, ore o2){
    return (o1.s < o2.s);
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i=0;i<m;i++)
        scanf("%d", &price[i]);
    for(int i=0; i<n;i++){
        ore temp;
        scanf("%d %d %lld", &temp.s, &temp.e, &temp.price);
        temp.price = price[temp.price-1]*(temp.e-temp.s);
        info.push_back(temp);
    }
    sort(info.begin(), info.end(), sort_ore);
    dp[0][0] = info[0].price;
    dp[0][1] = 0;
    long long max_all = dp[0][0];
    for(int i=1;i<n;i++) {
        dp[i][0] = info[i].price;
        dp[i][1] = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (info[j].e > info[i].s) continue;
            if (dp[i][1] < dp[j][0]) dp[i][1] = dp[j][0];
            if (dp[i][0] < info[i].price + dp[j][0])
                dp[i][0] = info[i].price + dp[j][0];
            if (dp[i][0] < info[i].price + dp[j][1])
                dp[i][0] = info[i].price + dp[j][1];
        }
        if (max_all < dp[i][0]) max_all = dp[i][0];
        if (max_all < dp[i][1]) max_all = dp[i][1];
    }
    cout << max_all<< endl;
    return 0;
}