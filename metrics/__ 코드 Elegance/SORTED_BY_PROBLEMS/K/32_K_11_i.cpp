#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

typedef ll T;

struct p3{
    T x,y,z;
    p3 operator+(p3 p){ return {x+p.x,y+p.y,z+p.z};}
    p3 operator-(p3 p){ return {x-p.x,y-p.y,z-p.z};}
    p3 operator*(T d){ return {x*d,y*d,z*d};}
    p3 operator/(T d){ return {x/d, y/d, z/d};}
    bool operator==(p3 p){return tie(x,y,z)==tie(p.x,p.y,p.z);}
    bool operator!=(p3 p){return !operator==(p);}
};

p3 zero{0,0,0};
T operator|(p3 v, p3 w){return v.x*w.x+v.y*w.y+v.z*w.z;}
p3 operator*(p3 v, p3 w){
    return {v.y*w.z - v.z*w.y, v.z*w.x - v.x*w.z, v.x*w.y-v.y*w.x};
}
T sq(p3 v){return v|v;}
T abs(p3 v){return sqrt(sq(v));}
p3 unit(p3 v){return v/abs(v);}
T orient3d(p3 p, p3 q, p3 r, p3 s){return (q-p)*(r-p)|(s-p);}


int n, k;
p3 pt[105];

long double get(vector<bool>& state){
    T x1sum=0, y1sum=0, z1sum=0;
    T x1sqsum=0, y1sqsum=0, z1sqsum=0;
    T x2sum=0, y2sum=0, z2sum=0;
    T x2sqsum=0, y2sqsum=0, z2sqsum=0;
    int n1 = 0, n2 = 0;
    for(int i = 0 ; i < n ; i++){
        //cout << state[i] << ' ';
        if(state[i]){
            x1sum += pt[i].x;
            y1sum += pt[i].y;
            z1sum += pt[i].z;
            x1sqsum += pt[i].x * pt[i].x;
            y1sqsum += pt[i].y * pt[i].y;
            z1sqsum += pt[i].z * pt[i].z;
            n1++;
        }
        else{
            x2sum += pt[i].x;
            y2sum += pt[i].y;
            z2sum += pt[i].z;
            x2sqsum += pt[i].x * pt[i].x;
            y2sqsum += pt[i].y * pt[i].y;
            z2sqsum += pt[i].z * pt[i].z;
            n2++;
        }
    }
    //cout << '\n';
    if(n1 == 0 or n2 == 0) return -1.0;
    long double val = 0;
    ll tmp = -(x2sum*x2sum+y2sum*y2sum+z2sum*z2sum)*n1 -(x1sum*x1sum+y1sum*y1sum+z1sum*z1sum)*n2 + (x1sqsum+y1sqsum+z1sqsum+x2sqsum+y2sqsum+z2sqsum)*n1*n2;
    return 1.0l * tmp / n1 / n2;
}

int main(void){
    cout << fixed; cout.precision(6);
    //test();
    //return 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed; cout.precision(6);
    cin >> n >> k;
    //auto t = clock();
    T x[105], y[105], z[105];
    T xsum=0, ysum=0, zsum=0;
    T xsqsum=0, ysqsum=0, zsqsum=0;
    if(k==1){
        for(int i = 0; i < n; i++){
            cin >> x[i];
            xsum += x[i]; xsqsum += x[i]*x[i];
            cin >> y[i];
            ysum += y[i]; ysqsum += y[i]*y[i];
            cin >> z[i];
            zsum += z[i]; zsqsum += z[i]*z[i];
        }
        //cout << xsum << '\n';
        long double ans = -1.0l*(xsum*xsum+ysum*ysum+zsum*zsum)/n + xsqsum+ysqsum+zsqsum;
        cout << ans;
        return 0;
    }

    for(int i = 0; i < n; i++){
        cin >> pt[i].x >> pt[i].y >> pt[i].z;
        //pt[i] = {(T)rand()%1000,(T)rand()%1000,(T)rand()%1000};
    }
    if(n==1 or n == 2){
        cout << 0;
        return 0;
    }

    long double ans = 1e100;
    vector<bool> state(n);
    for(int i = 0; i < n; i++){
        //cout << i << '\n';
        for(int j = i+1;  j < n; j++){
            for(int k = j+1; k < n; k++){
                p3 crosspro = (pt[i]-pt[j])*(pt[k]-pt[j]);
                T fixed = crosspro|pt[j];
                for(int idx = 0; idx < n; idx++){
                    if(idx == i or idx == j or idx == k) continue;
                    state[idx] = (crosspro|pt[idx]) > fixed;
                }
                for(int mask = 0; mask < 8; mask++) {
                    state[i] = mask&(1);
                    state[j] = mask&(2);
                    state[k] = mask&(4);
                    long double val = get(state);
                    if(val == -1.0) continue;
                    ans = min(ans,val);
                }
            }
        }
    }
    cout << ans << '\n';
    //cout << clock()-t;
}

/*
 2 1
 36 16 85
 74 87 38

 4347.000000

 3 2
 93 50 26
 40 0 77
 99 10 29

 822.500000
 */