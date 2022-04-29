#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll a[2001];

int main()
{
    int N; scanf("%d", &N);
    a[0] = a[1] = 1;
    for(int i = 2; i <= N; i++){
        vector<ll> v;
        for(int k = 1; k <= i; k++){
            if(i - 2 * k >= 0 && 2 * a[i - k] - a[i - 2 * k] > 0)
                v.push_back(2 * a[i - k] - a[i - 2 * k]);
        }
        v.push_back(0);
        sort(v.begin(), v.end());

//        printf("%d\n", i);
//        for(int x : v)
//            printf("%d ", x);
//        printf("\n");
        for (int j = 1; j < (int) v.size(); j++) {
            if(v[j] == v[j - 1]) continue;
            if (v[j] != v[j - 1] + 1) {
                a[i] = v[j - 1] + 1;
                break;
            }
        }
        if (!a[i]) a[i] = v[v.size() - 1] + 1;
    }

//    for(int i = 0; i <= N; i++)
//        printf("%d ", a[i]);
//    printf("\n");
    printf("%lld\n", a[N]);

    return 0;
}