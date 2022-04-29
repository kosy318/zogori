#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct POINT{
    double x,y,z;
    POINT(){}
    POINT(double x, double y, double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    POINT operator*(int t){
        return POINT(this->x*t, this->y*t, this->z*t);
    }
    POINT operator/(int t){
        return POINT(this->x/t, this->y/t, this->z/t);
    }
    POINT operator+(POINT t){
        return POINT(this->x+t.x, this->y+t.y, this->z+t.z);
    }
};

double getd(POINT& p1, POINT& p2){
    return pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2);
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<POINT> v(n);
    double xm=0,ym=0,zm=0;
    for(int i=0; i<n; i++){
        cin>>v[i].x>>v[i].y>>v[i].z;
        xm+=v[i].x;
        ym+=v[i].y;
        zm+=v[i].z;
    }
    xm/=n;
    ym/=n;
    zm/=n;
    double answer=0;
    for(int i=0; i<n; i++){
        answer+=pow(v[i].x-xm,2)+pow(v[i].y-ym,2)+pow(v[i].z-zm,2);
    }

    if(k==2){
        vector<pair<int,int>> p;
        vector<int> group(n);
        double maxd=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                double d=getd(v[i],v[j]);
                if(maxd<d){
                    p.clear();
                    p.push_back({i,j});
                }
            }
        }
        POINT m1,m2;
        for(int i=0; i<p.size(); i++){
            m1=v[p[i].first];
            m2=v[p[i].second];
            group[p[i].first]=1;
            group[p[i].second]=2;
            for(int l=0; l<n; l++) {
                POINT nm1=POINT(0,0,0);
                POINT nm2=POINT(0,0,0);
                int cnt1=0,cnt2=0;
                for (int j = 0; j < n; j++) {
                    double d1 = getd(m1, v[j]);
                    double d2 = getd(m2, v[j]);
                    if (d1 < d2) {
                        group[j] = 1;
                        nm1=nm1+v[j];
//                        m1 = (m1 * cnt1 + v[j]) / (cnt1 + 1);
                        cnt1 += 1;
                    } else {
                        group[j] = 2;
                        nm2=nm2+v[j];
//                        m2 = (m2 * cnt2 + v[j]) / (cnt2 + 1);
                        cnt2 += 1;
                    }
                }
                m1=nm1/cnt1;
                m2=nm2/cnt2;
            }
        }

        double answer1=0,answer2=0;
        for(int i=0; i<n; i++){
            if(group[i]==1) answer1+=getd(v[i],m1);
            else answer2+=getd(v[i],m2);
        }
        answer=min(answer,answer1+answer2);
    }

    cout.precision(6);
    cout<<fixed;
    cout<<answer;

    return 0;
}