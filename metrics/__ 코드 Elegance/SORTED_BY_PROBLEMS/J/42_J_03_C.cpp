
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

ll calc(int n)
{
    if (n == 3) return 0;
    if (n == 4) return 1;
    int tmp = n / 2;
    if (n % 2) ++tmp;
    return calc(tmp) + 2;
}
int main()
{
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    cout << calc(n);
    return 0;
}
