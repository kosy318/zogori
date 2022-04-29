#include <cstdio>
#include <algorithm>

int iArr[1024];
int priceArr[101];
int timeArr[15001];

using namespace std;

typedef struct info{
    int s, e, price;
    int time, val;
}info;
info arr[10001];

bool cmp(info u, info v){
    if(u.val == v.val){
        return u.time < v.time;
    }
    return u.val > v.val;
}

int main(){

    int m, n;
    scanf("%d %d", &m, &n);

    for(int i=1; i<=m; i++){
        int v;
        scanf("%d", &v);
        priceArr[i] = v;
    }

    for(int i = 0; i < n; i++){
        int s, e, type;
        scanf("%d %d %d", &s, &e, &type);
        arr[i].s = s;
        arr[i].e = e;
        arr[i].price = priceArr[type];
        arr[i].time = e - s;
        arr[i].val = arr[i].time * arr[i].price;
    }
    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++){
        //printf("s:%d e:%d price:%d time:%d val:%d\n",arr[i].s, arr[i].e, arr[i].price, arr[i].time, arr[i].val);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool cando = true;
        for(int j = arr[i].s; j < arr[i].e; j++){
            if(timeArr[j] == 1){
                cando = false;
            }
        }
        if(cando){
            ans += arr[i].val;
            for(int j = arr[i].s; j < arr[i].e; j++){
                timeArr[j] = 1;
            }
        }
    }
    printf("%d\n", ans);
/*
    int n;
    bool bEnd = false;
    scanf("%d", &n);
    for(int i = 0; i < n+1; i++) iArr[i] = 2100000000;
    iArr[0] = 1;
    iArr[1] = 1;

    for(int i = 2; i < n+1; i++) {
    bEnd = false;
        for(int j = 1; !bEnd && j < 10; j++) {
            for(int k = 1; i-k >= 0 && i-2*k >= 0 && j-iArr[i-k] != iArr[i-k] - iArr[i-2*k] ; k++) {
                    //iArr[i] = min(iArr[i], j);
                    iArr[i] = j;

                    bEnd = true;
                    printf(" i :: %d k :: %d\n", i, k);
                    printf(" i-2k :: %d\n", i-2*k);
                    break;

            }
        }
    }
    for(int i = 0; i < n+1; i++) {
        printf(" %d :: %d\n", i, iArr[i]);
    }
    printf("%d\n", iArr[n]);


*/
/*
    int n;
    scanf("%d", &n);
    iArr[0] = 1;
    iArr[1] = 1;

    for(int i = 2; i <= n; i++) {
        bool cando = false;
        int k = 1;
        int j;
        int ans;
        while(i - 2 * k >= 0){
            ans = min(iArr[i - k], iArr[i - 2 * k]);
            printf("%d %d %d %d\n", iArr[i],iArr[i - k],iArr[i - k],iArr[i - 2 * k]);
            if(ans - iArr[i - k] != iArr[i - k] - iArr[i - 2 * k]){
                iArr[i] = ans;
                cando = true;
                break;
            }
            k++;
        }
        if(!cando) iArr[i] = ans+1;
    }
    printf("%d", iArr[n]);

*/
}
