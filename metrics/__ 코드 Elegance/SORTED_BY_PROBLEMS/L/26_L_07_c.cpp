#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int start;
    int endTime;
    int type;
}Mineral;

int n, m, table[105], dp[15005];
Mineral arr[10005];

bool comp(const Mineral &a, const Mineral &b)
{
    if(a.endTime == b.endTime) {
        return a.start < b.start;
    }

    return a.endTime < b.endTime;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(register int i = 1; i<= n; i++) scanf("%d", table+i);
    int s, e, t;
    for(register int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &t);
        arr[i] = {s,e,t};
    }

    sort(arr, arr+m, comp);
    int res = 0;
    for(register int i = 0 ; i < m; i++) {
        int start = arr[i].start;
        int maxVal = 0;
        for(register int j = start; j >=0; j--)
        {
            maxVal = max(maxVal, dp[j]);
        }

        dp[arr[i].endTime] = max(dp[arr[i].endTime], maxVal + (arr[i].endTime - arr[i].start) * table[arr[i].type]);
        res = max(res, dp[arr[i].endTime]);
    }

    printf("%d\n", res);
    return 0;
}
