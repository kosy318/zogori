#define LOCAL
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast, no-stack-protector")
#pragma GCC target("avx")
#include<chrono>
#define FOR(i, a, b) for (int i = (a), _b=(b); i <= _b; i++)
#define FORD(i, a, b) for (int i  = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i <_a; ++i)
#define REPD(i, a) for (int i = (a) - 1; i >=0; --i)
#define PI (2 * acos((double)0))
#define sec(x) 1.0 / cos((x))
#define asec(x) acos(1.0 / (x))
template<class T> int getbit(T s, int i) {return (s >> i ) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) {return __builtin_popcountll(s); }
template<class T> T gcd(T a, T b){ T r; while(b != 0){ r = a % b; a = b; b = r;} return a;}
template<class T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
#define ARR(X, L, R) { cerr << #X << " = {";
#define sqr(x) ((x) * (x))
#define unify(x) x.erase(unique(x.begin(), x.end()), x.end())
#define __builtin_popcount __builtin_popcountll
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1100;
ll a[MAXN];
int main()
{
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    a[0] = 1, a[1] = 1;
    FOR(i, 2, n)
    {
        set<ll> good;
        FOR(k, 1, i / 2)
        {
            ll tmp = a[i - k] * 2 - a[i - 2 * k];
            if (tmp >= 0) good.insert(tmp);
        }

        if (*good.begin() > 1) a[i] = 1;
        else if (good.size() == 1) a[i] = *good.rbegin() + 1;
        else
        {
            a[i] = *good.rbegin() + 1;
            ll last = 0;
            for (auto x: good) if (x - last > 1)
            {
                a[i] = min(a[i], last + 1);
                break;
            }
            else last = x;
        }
    }
    cout << a[n] << endl;
    return 0;
}
