#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point {
    int x, y, z;
};

struct avg{
    double a, b, c;
};
int square(int a) {
    return a * a;
}

int distance(Point a, Point b) {
    return square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z);
}

int main() {
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n , k, t1, t2, t3;
    vector<Point> rgb;
    vector<int> dist;
    vector<int> x, y, z;
    avg total = {};
    double ans = 0.0;

    cin >> n >> k;
    for(int i = 0; i< n; i++){
        cin >> t1 >> t2 >> t3;
        rgb.push_back({t1, t2, t3});
        dist.push_back(distance(rgb[i], {0,0,0}));
        total.a += t1;
        total.b += t2;
        total.c += t3;
        x.push_back(t1);
        y.push_back(t2);
        z.push_back(t3);
    }

    total.a /= n;
    total.b /= n;
    total.c /= n;

    for (int i = 0; i < n; i++){
        ans += pow((total.a - rgb[i].x), 2) + pow((total.b - rgb[i].y), 2) + pow((total.c - rgb[i].z), 2);
    }

    if( k == 1 || n == 1){
        cout << fixed;
        cout.precision(6);
        cout << ans;
        return 0;
    }
    else{
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    int standard = distance({x[i], y[j], z[k]}, {0,0,0});
                    vector<int> group1, group2;
                    avg av_group1 = {},  av_group2={};
                    for(int l = 0; l < n; l++){
                        if(dist[l] < standard){
                            group1.push_back(l);
                            av_group1.a += rgb[l].x;
                            av_group1.b += rgb[l].y;
                            av_group1.c += rgb[l].z;
                        }
                        else{
                            group2.push_back(l);
                            av_group2.a += rgb[l].x;
                            av_group2.b += rgb[l].y;
                            av_group2.c += rgb[l].z;
                        }
                    }
                    int k1 = group1.size(), k2 = group2.size();
                    if(k1 != 0){
                        av_group1.a /= k1;
                        av_group1.b /= k1;
                        av_group1.c /= k1;
                    }
                    if(k2 != 0) {
                        av_group2.a /= k2;
                        av_group2.b /= k2;
                        av_group2.c /= k2;
                    }

                    double t = 0.0;
                    for(int l = 0; l < k1; l++){
                        t += pow((av_group1.a - rgb[group1[l]].x), 2) + pow((av_group1.b - rgb[group1[l]].y), 2) + pow((av_group1.c - rgb[group1[l]].z), 2);
                    }
                    for(int l = 0; l < k2; l++){
                        t += pow((av_group2.a - rgb[group2[l]].x), 2) + pow((av_group2.b - rgb[group2[l]].y), 2) + pow((av_group2.c - rgb[group2[l]].z), 2);
                    }
                   ans = min(ans, t);
                }
            }
        }
        cout << fixed;
        cout.precision(6);
        cout << ans;
    }
    /*
    if(k==1) {

    }
    else if(k == 2) {
        int d = -1;
        int m_i1, m_i2;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int temp = distance(rgb[i], rgb[j]);
                if(d < temp){
                    d = temp;
                    m_i1 = i;
                    m_i2 = j;
                }
            }
        }
        cout << m_i1 << ' ' << m_i2 << endl;

        // Grouping
        vector<int> group1, group2;
        for(int i=0; i<n; i++) {
            if(distance(rgb[m_i1], rgb[i]) < distance(rgb[m_i2], rgb[i])) {
                group1.push_back(i);
            }else{
                group2.push_back(i);
            }
        }

        avg group1_avg, group2_avg;
        for(int i=0; i < group1.size(); i++){
            group1_avg.a += rgb[group1[i]].x;
            group1_avg.b += rgb[group1[i]].y;
            group1_avg.c += rgb[group1[i]].z;
        }
        for (int i = 0; i < group2.size(); i++){
            group2_avg.a += rgb[group2[i]].x;
            group2_avg.b += rgb[group2[i]].y;
            group2_avg.c += rgb[group2[i]].z;
        }

        group1_avg.a /= 3;
        group1_avg.b /= 3;
        group1_avg.c /= 3;
        group2_avg.a /= 3;
        group2_avg.b /= 3;
        group2_avg.c /= 3;


    }
    */
    return 0;
}