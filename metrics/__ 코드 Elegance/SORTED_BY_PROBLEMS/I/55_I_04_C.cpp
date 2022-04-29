#include <stdio.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

int n;
pair<int, int> thread[MAXN];

bool isPossible(long long T)
{
    int i;
    long long x=0;

    for(i=0; i<n; i++){
        if(x < thread[i].first)
            x = thread[i].first + T;
        else if(x > thread[i].first + thread[i].second)
            return false;
        else
            x += T;
    }

    return true;
}

int main()
{
    int i;
    long long l, r, m;

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &thread[i].first, &thread[i].second);
    sort(thread, thread+n);

    l = 0; r = thread[n-1].first+thread[n-1].second;
    while(l < r){
        m = (l+r+1)/2;

        if(isPossible((int)m)) l = m;
        else r = m-1;
    }

    printf("%lld", l);

    return 0;
}
