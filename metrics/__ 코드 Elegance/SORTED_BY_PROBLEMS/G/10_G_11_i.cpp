#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#define ll long long
using namespace std;

pair <int, int> ip[100001];
int m,n;
int cor[100001], color[100001];
vector<vector<int> > dot;

map<ll, ll> memo;

ll dp(int s, int last) {
  //  printf("%d %d\n",s,last);
    if (s >= dot.size()) return 0;
    ll hh = (ll) s * 1000000 + last;

    if (memo.count(hh)) return memo[hh];

    ll leftHole = dot[s - 1].back() - last;

    auto cit = lower_bound(dot[s].begin(), dot[s].end(), dot[s - 1].back() + leftHole);
    if (cit == dot[s].end()) return memo[hh] = 987654321;

    memo[hh] = 987654321;

    int rightHole = dot[s].front() - last;
    auto nit = upper_bound(dot[s].begin(), dot[s].end(), dot[s].front() + rightHole);

    for (auto it = cit; it < nit && it != dot[s].end(); it++)
    {
       // printf("s: %d, last : %d, *it : %d\n",s,last,*it);
        ll tmp = dp(s+1, *it) + 1;
        memo[hh] = min(memo[hh], tmp);
    }
    for (auto it = nit; it != dot[s].end(); it++)
    {
        ll tmp = dp(s+1,*it) + 2;
        memo[hh] = min(memo[hh], tmp);
    }

    return memo[hh];
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) scanf("%d", &ip[i].first);
    for(int i=0;i<n;i++) scanf("%d", &ip[i].second);

    sort(ip,ip+n);

    for(int i=0;i<n;i++) cor[i] = ip[i].first;

    int cc;
    vector <int> tmp;
    for(int i=0;i<n;i++)
    {
        color[i] = ip[i].second;
        if(i==0) cc = color[i];

        if(color[i] != cc)
        {
            dot.push_back(tmp);
            tmp.clear();
        }

        cc = color[i];
        tmp.push_back(cor[i]);
    }
    dot.push_back(tmp);

    ll ans = dot.size()*2;
    for(int it: dot[0])
    {
        ans = min(ans, dp(1, it));
    }

    printf("%lld", ans + 1);
}
