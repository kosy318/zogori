#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;
typedef pair<ll,p> llp;
priority_queue <llp, vector<llp>, greater<llp>> pq1, pq2;// pq1 -> first = s, pq2 ->first = e
llp sep;
ll m,n, price[105];
ll dp[16500];

int main(){
    scanf("%lld %lld",&m,&n);
    for(int i = 1;i<=m;i++) scanf("%lld",&price[i]);
    for(int i =1;i<=n;i++){
        ll s, e, t;
        scanf("%lld %lld %lld",&s,&e,&t);
        pq1.push({s, {e, (e - s) * price[t]}});
    }
    for(int sec = 1;sec <=16000;sec++){
        if(!pq2.empty()){
            while(!pq2.empty() && sec == pq2.top().first){
                ll sum = dp[pq2.top().second.first] + pq2.top().second.second;
                dp[sec] = max(max(sum, dp[sec-1]), dp[sec]);
                pq2.pop();
            }
        }
        if(!pq1.empty()){
            while(!pq1.empty() && sec == pq1.top().first){
                ll a = pq1.top().first, b= pq1.top().second.first, c= pq1.top().second.second;
                pq2.push({b, {a, c}});
                pq1.pop();
            }
        }
        dp[sec] = max(dp[sec], dp[sec-1]);
    }
    printf("%lld\n", dp[16000]);
    return 0;
}


/*#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<double ,double> p;
typedef pair<p,p> pp;
pp input[105];
int n,k;

void chk(int mid){
    for(int i = 0;i<mid;i++){

    }
    for(int i = mid;i<n;i++){

    }
}

int main(){
    scanf("%d %d",&n, &k);
    for(int i = 0;i<n;i++){
        double r, g, b;
        scanf("%lf %lf %lf",&r,&g,&b);
        input[i] = { {r + g + b, r}, {g, b} };
    }
    if(k == 1){
        double c = 0, mr = 0, mg = 0, mb = 0;
        for(int i = 0;i<n;i++){
            mr += input[i].first.second, mg += input[i].second.first, mb += input[i].second.second;
        }
        mr/=n, mg/=n, mb/=n;
        for(int i = 0;i<n;i++){
            c += (input[i].first.second - mr) * (input[i].first.second - mr) + (input[i].second.first - mg) * (input[i].second.first - mg) +
            (input[i].second.second - mb) * (input[i].second.second - mb);
        }
        printf("%lf",c);
    }
    if(k == 2){
        if(n <= 2) printf("0.00000\n");
        else {
            sort(input, input+ n);
            double c1 = 0, c2 = 0, mr1 = 0, mr2 = 0, mg1 = 0, mg2 = 0, mb1 = 0, mb2 = 0;
            mr1 = input[0].first.second, mg1 = input[0].second.first, mb1 = input[0].second.second;
            for(int i = 1;i<n;i++){
                mr2 += input[i].first.second, mg2 += input[i].second.first, mb2 += input[i].second.second;
            }
            for(int i = 1;i<n;i++){
                c2 += (input[i].first.second - mr2 / (n - 1)) * (input[i].first.second - mr2 / (n - 1)) + (input[i].second.first - mg2 / (n - 1)) * (input[i].second.first - mg2) +
                (input[i].second.second - mb2) * (input[i].second.second - mb2);
            }
        }
    }
    return 0;
}
*/
