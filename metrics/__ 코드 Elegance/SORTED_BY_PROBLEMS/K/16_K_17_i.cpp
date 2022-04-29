#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cfloat>
#include <climits>

struct info {
    long long r, g, b;
};

info input[110];
bool check[110];

long long getCost(std::vector<info>& v) {
    long long rhap = 0, ghap = 0, bhap = 0;
    for(int i = 0; i < v.size(); i++) {
        rhap += v[i].r;
        ghap += v[i].g;
        bhap += v[i].b;
    }
    long long result = 0;

    for(int i = 0; i < v.size(); i++) {
        result += (v[i].r * v.size() - rhap) * (v[i].r * v.size() - rhap) + (v[i].g * v.size() - ghap) * (v[i].g * v.size() - ghap) + (v[i].b * v.size() - bhap) * (v[i].b * v.size() - bhap);
    }
    return result;
}

int main(void) {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &input[i].r, &input[i].g, &input[i].b);
    }

    if(k == 1) {
        std::vector<info> v;
        for(int i = 1; i <= n; i++)
            v.push_back(input[i]);
        printf("%.6lf\n", (getCost(v) / (double)(n * n)));
    }
    else if(n == 1 || (k == 2 && n == 2)) {
        printf("0.000000\n");
    }
    else {
        std::vector<info> v;
        for(int i = 1; i <= n; i++)
            v.push_back(input[i]);
        double r = getCost(v)  / (double)(n * n);

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                long long rmid = (input[i].r + input[j].r), gmid = (input[i].g + input[j].g), bmid = (input[i].b + input[j].b);
                long long diff = (input[i].r - input[j].r) * (input[i].r - input[j].r) + (input[i].g - input[j].g) * (input[i].g - input[j].g) + (input[i].b - input[j].b) * (input[i].b - input[j].b);
                memset(check, false, sizeof(check));
                for(int k = 1; k <= n; k++) {
                    long long tmp = (input[k].r * 2 - rmid) * (input[k].r * 2 - rmid) + (input[k].g * 2- gmid) * (input[k].g * 2 - gmid) + (input[k].b * 2 - bmid) * (input[k].b * 2 - bmid);
                    if(tmp <= diff)
                        check[k] = true;
                }

                std::vector<info> v1, v2;
                for(int k = 1; k <= n; k++) {
                    if(check[k] == true)
                        v1.push_back(input[k]);
                    else
                        v2.push_back(input[k]);
                }
                if(v1.size() == 0) {
                    r = std::min(r, (long long)getCost(v2) / (double)(v2.size() * v2.size()));
                }
                else if(v2.size() == 0) {
                    r = std::min(r, (long long)getCost(v1) / (double)(v1.size() * v1.size()));
                }
                else
                    r = std::min(r, (long long)getCost(v1) / (double)(v1.size() * v1.size()) + (long long)getCost(v2) / (double)(v2.size() * v2.size()));
            }
        }
        printf("%.6lf\n", r);
    }

}