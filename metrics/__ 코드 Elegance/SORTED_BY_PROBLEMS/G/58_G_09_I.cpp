#include <bits/stdc++.h>
using namespace std;

struct data{
    int x, idx;
    bool operator<(const data &d1) const{
        return x < d1.x;
    }
};
int m, n, cnt, res;
deque <int> vt[100010], dq[100010];
data arr[100010];

int lowb(int a, int s){
    int l = 0, r = dq[a].size() - 1, mid, flag = dq[a].back();
    while(l <= r){
        mid = (l + r) / 2;
        if(dq[a][mid] < s) l = mid + 1;
        else flag = min(flag, dq[a][mid]), r = mid - 1;
    }
    return flag;
}
int main(){
    int i, j, k, a, b, now;
    scanf("%d %d", &m, &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i].x);
    for(i = 0; i < n; i++) scanf("%d", &arr[i].idx);
    sort(arr, arr + n);
    vt[cnt].push_back(arr[0].x);
    for(i = 1; i < n; i++){
        if(arr[i].idx != arr[i - 1].idx) cnt++;
        vt[cnt].push_back(arr[i].x);
    }
    for(i = 0; i < vt[0].size(); i++) dq[i].push_back(vt[0][i]); res = 1;
    for(i = 1; i <= cnt; i++){
        res++;
        a = 2 * vt[i - 1].back();
        b = 2 * vt[i].front();
        //printf("%d \n", dq[i - 1].size());
        for(j = 0; j < vt[i].size(); j++){
            now = lowb(i - 1, a - vt[i][j]);
            //printf("%d %d %d\n", i, j, now);
            if(now >= a - vt[i][j] && now <= b - vt[i][j]) dq[i].push_back(vt[i][j]);
        }
        if(dq[i].empty()){
            k = 0;
            while(k < vt[i - 1].size() && vt[i - 1][k] <= dq[i - 1][0]) k++;
            while(!dq[i - 1].empty()) dq[i - 1].pop_back();
            for(; k < vt[i - 1].size(); k++) dq[i - 1].push_back(vt[i - 1][k]);
            i--;
        }
    }
    printf("%d", res);
    return 0;
}

/*

2 6
0 3 4 7 8 11
1 1 1 2 2 1

2 6
0 3 4 7 8 11
1 2 1 2 2 1

2 6
5 6 7 8 10 12
1 2 2 2 2 1

2 9
1 4 5 7 8 10 12 13 14
1 1 2 2 2 2 1 1 1





*/
