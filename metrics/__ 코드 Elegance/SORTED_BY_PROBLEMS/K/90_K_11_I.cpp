#include<stdio.h>
#include<vector>
#include<algorithm>

struct color{
    double r,g,b;
    void scan() {
        scanf("%lf %lf %lf", &r, &g, &b);
    }
    void print(){printf("test : %f %f %f\n", r, g, b);}
    void operator +=(const color& x){
        r += x.r;
        g += x.g;
        b += x.b;
    }
    color operator -(const color& x){
        color temp;
        temp.r = r - x.r;
        temp.g = g - x.g;
        temp.b = b - x.b;
        return temp;
    }
    void operator -=(const color& x){
        r -= x.r;
        g -= x.g;
        b -= x.b;
    }
    void operator /=(double x) {
        r /= x;
        g /= x;
        b /= x;
    }
    color operator /(double x){
        color temp;
        temp.r = r/x;
        temp.g = g/x;
        temp.b = b/x;
        return temp;
    }
    double pow2(){
//        printf("%lf %lf %lf\n", r, g, b);
        return r*r + g*g + b*b;
    }
};

//double r[101], g[101], b[101];
color sum;
std::vector<color> v;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        color temp;
        temp.scan();
        sum += temp;
        v.push_back(temp);
    }
    double ans = 0;
    color sum_temp = sum/(double)N;
    for(int i=0; i<N; i++) {
        ans += (sum_temp-v[i]).pow2();
    }
    if(K==2){
        color temp, temp_sum;
        std::sort(v.begin(), v.end(), [](const color& x, const color& y){
            return x.r < y.r;
        });
        temp = {0,0,0};
        temp_sum = sum;
        for(int cut=0; cut<N; cut++){
            temp += v[cut];
            temp_sum -= v[cut];
            double temp_ans = 0;
            for(int i=0; i<=cut; i++){
                temp_ans += (temp/(double)(cut+1) - v[i]).pow2();
            }
            for(int i=cut+1; i<N; i++){
                temp_ans += (temp_sum/(double)(N-cut-1) - v[i]).pow2();
            }
            if(temp_ans < ans) ans = temp_ans;
        }
        std::sort(v.begin(), v.end(), [](const color& x, const color& y){
            return x.g < y.g;
        });
        temp = {0,0,0};
        temp_sum = sum;
        for(int cut=0; cut<N; cut++){
            temp += v[cut];
            temp_sum -= v[cut];
            double temp_ans = 0;
            for(int i=0; i<=cut; i++){
                temp_ans += (temp/(double)(cut+1) - v[i]).pow2();
            }
            for(int i=cut+1; i<N; i++){
                temp_ans += (temp_sum/(double)(N-cut-1) - v[i]).pow2();
            }
            if(temp_ans < ans) ans = temp_ans;
        }
        std::sort(v.begin(), v.end(), [](const color& x, const color& y){
            return x.b < y.b;
        });
        temp = {0,0,0};
        temp_sum = sum;
        for(int cut=0; cut<N; cut++){
            temp += v[cut];
            temp_sum -= v[cut];
            double temp_ans = 0;
            for(int i=0; i<=cut; i++){
                temp_ans += (temp/(double)(cut+1) - v[i]).pow2();
            }
            for(int i=cut+1; i<N; i++){
                temp_ans += (temp_sum/(double)(N-cut-1) - v[i]).pow2();
            }
            if(temp_ans < ans) ans = temp_ans;
        }
    }
    printf("%f",ans);
    return 0;
}