//#define LOCAL
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast, no-stack-protector")
#pragma GCC target("avx")
#include<chrono>
#define FOR(i, a, b) for (int i = (a), _b=(b); i <= _b; i++)
#define FORD(i, a, b) for (int i  = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i <_a; ++i)
#define REPD(i, a) for (int i = (a) - 1; i >=0; --i)
#define PI (2 * acos((double)0))
#define fi first
#define se second
#define sec(x) 1.0 / cos((x))
#define asec(x) acos(1.0 / (x))
template<class T> int getbit(T s, int i) {return (s >> i ) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) {return __builtin_popcountll(s); }
template<class T> T gcd(T a, T b){ T r; while(b != 0){ r = a % b; a = b; b = r;} return a;}
template<class T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
#define sqr(x) ((x) * (x))
#define unify(x) x.erase(unique(x.begin(), x.end()), x.end())
#define __builtin_popcount __builtin_popcountll
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct RGB{
    int r, g, b;
};
double sq(double val){
return val * val;}
void getAvg(double & r, double &g, double &b, vector<RGB> &seq){
    r = g = b = 0.0;
    if(seq.empty()) return;
    int num = seq.size();
    for(int i = 0; i<seq.size(); ++i){
        r += seq[i].r;
        g += seq[i].g;
        b += seq[i].b;
    }
    r /= num;
    g /= num;
    b /= num;
}
double getD(double r, double g, double b, vector<RGB> &seq){
    double res = 0.0;
    for(int i = 0; i<seq.size(); ++i)
        res += sq(r - seq[i].r) + sq(b - seq[i].b) + sq(g - seq[i].g);
    return res;
}
double getDist(RGB p1, RGB p2){
    return sq(p1.r - p2.r) + sq(p1.g - p2.g) + sq(p1.b - p2.b);
}
int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    srand(time(0));
    int n, k; scanf("%d %d", &n, &k);
    vector<RGB> seq(n);
    for(int i = 0; i<n; ++i)
        scanf("%d %d %d", &seq[i].r, &seq[i].g, &seq[i].b);

    double r,g,b, ans = 1e10;
    if(k == 1){
        getAvg(r, g, b, seq);
        printf("%.9lf", getD(r, g, b, seq));
    }
    else{
        int p1 = rand()%seq.size();
        int p2 = rand()%seq.size();
        while(p1 == p2)
            p2 = rand()%seq.size();
        RGB c1 = seq[p1];
        RGB c2 = seq[p2];
        vector<RGB> s1, s2;
        for(int T = 0; T<80; ++T){
            for(int i = 0 ;i<seq.size(); ++i){
                if(getDist(c1, seq[i]) > getDist(c2, seq[i]))
                    s2.push_back(seq[i]);
                else
                    s1.push_back(seq[i]);
            }
            double sum = 0.0;
            getAvg(r, g, b, s1);
            sum += getD(r, g, b, s1);
            c1 = {r, g, b};
            getAvg(r, g, b, s2);
            sum += getD(r, g, b, s2);
            ans = min(ans, sum);
            s1.clear(); s2.clear();
            c2 = {r, g, b};
        }
        printf("%.9lf", ans);
    }
}

