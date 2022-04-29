#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int,int>p;
p xy[100005];
int n, ans;

int chk(int mid){s
    int now = xy[0].first;
    for(int i = 1;i<n;i++){
        int nnow = now + mid;
        if(xy[i].second < nnow) return 0;
        else{
            if(nnow < xy[i].first) now = xy[i].first;
            else now = nnow;
        }
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i = 0,a,b;i<n;i++) scanf("%d %d",&a,&b), xy[i] = {a, a + b};
    sort(xy,xy+n);
    int s = 0, e = 1e9;
    while(s <= e){
        int mid = (s+e)/2;
        if(chk(mid)) ans = mid, s = mid+1;
        else e = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
