//#define LOCAL_BOOKNU
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class key, class value, class cmp = less<key>>
using treemap = tree<key, value, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
//key, value, comp, implement
template <class key, class cmp = less<key>>
using treeset = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef LOCAL_BOOKNU
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define FOR(i,f,n) for(int (i) = (f); (i)<(int)(n); ++(i))
#define RFOR(i,f,n) for(int (i) = (f); (i)>=(int)(n); --(i))
#define pb push_back
#define emb emplace_back
#define fi first
#define se second
#define ENDL '\n'
#define sz(A) (int)(A).size()
#define ALL(A) A.begin(), A.end()
#define UNIQUE(c) (c).resize(UNIQUE(ALL(c))-c.begin(c))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long i64;
typedef unsigned long long ui64;
inline int getidx(const vi& ar, int x) {return lower_bound(ALL(ar), x)- ar.begin();}
inline i64 GCD(i64 a, i64 b) {i64 n; if(a<b) swap(a,b); while(b!=0){n= a%b; a=b; b= n;}
    return a;}
inline i64 LCM (i64 a, i64 b) {if(a==0 || b==0) return GCD(a,b);
    return a/GCD(a,b)*b;}
inline i64 CEIL(i64 n, i64 d) { return n/d+(i64)(n%d !=0);}
inline i64 ROUND(i64 n, i64 d) { return n/d+(i64)((n%d)*2>=d);}
inline i64 MOD = 1e9+7;
inline i64 POW(i64 a, i64 n){
    i64 ret;
    for(ret =1; n; a = a*a%MOD, n /=2){if(n%2) ret=ret*a%MOD;}
    return  ret;
}
template <class T> ostream& operator<<(ostream& os, vector<T> v){
    os<<"[";
    int cnt = 0;
    for(auto vv:v) {os << vv; if(++cnt<v.size()) os << ",";}
    return os<<"]";
}
template <class T> ostream& operator<<(ostream& os, set<T> v){
    os<<"[";
    int cnt = 0;
    for(auto vv:v) {os << vv; if(++cnt<v.size()) os << ",";}
    return os<<"]";
}
template <class L, class R> ostream& operator<<(ostream& os, pair<L,R> p){return os<<"("<<p.fi<<","<<p.se<<")";}
void debug_out(){cerr <<endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T){cerr << " " << H, debug_out(T...);}
//......................................MAIN.................................................

const int MAXN = 1e5+10;
int n;
ii ar[MAXN];
void input(){
    cin >> n;
    FOR(i, 0, n) cin >> ar[i].fi >> ar[i].se;
}

bool chk(int x) {
    int p = ar[0].fi;
    FOR(i, 1, n) {
        if(p + x > ar[i].fi + ar[i].se) return false;
        p = max(p + x, ar[i].fi);
    }
    return true;
}

int solve() {
    sort(ar, ar + n);
    debug(chk(25));
    i64 lo = 0, hi = 1e9+10;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(chk(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << ENDL;
}

void excute() {
    input(), solve();
}

int main() {
    // !! ERASE BEFORE SUBMIT !!
#ifdef LOCAL_BOOKNU
    freopen("/home/team062/CLionProjects/untitled/input.txt", "r", stdin);
    //freopen("_IO/out.txt", "w", stdout);
#endif
    cin.tie(0), ios_base::sync_with_stdio(false);
    excute();
    return  0;
}