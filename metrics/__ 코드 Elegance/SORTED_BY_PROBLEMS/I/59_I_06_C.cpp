#include <bits/stdc++.h>
#define ll long long

using namespace std;


struct th
{
    ll s, t;
    bool operator <(th right)
    {
        if(s == right.s)
            return t < right.t;
        return s < right.s;
    }
};

th t[100000];
int n;

bool check(ll v)
{
    ll curr = t[0].s;
    for(int i = 1; i < n; ++i)
    {
        if(curr + v <= t[i].s)
            curr = t[i].s;
        else if(curr + v <= t[i].s + t[i].t)
            curr = curr + v;
        else
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> t[i].s >> t[i].t;
    sort(t, t+n);
    ll s = 0, e = 2000000001;
    while(s <= e)
    {
        ll mid = (s+e)/2;
        if(check(mid))
            s = mid + 1;
        else
            e = mid - 1;
    }
    cout << s - 1;
    return 0;
}
