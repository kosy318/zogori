#include<stdio.h>
#include<vector>
#include<algorithm>

int N;
std::vector<std::pair<int, int> > v;

bool go(int x){
    long long prev = -1e9;
    for(const auto &i : v){
        prev = std::max(prev+x, (long long)i.first);
        if(prev > i.first+i.second) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        v.push_back({x,y});
    }
    std::sort(v.begin(), v.end());
    int left=0, right=1e9;
    while(left < right){
//        printf("%d %d""\n", left, right);
        int mid = (left+right)/2;
        if(go(mid)) left = mid + 1;
        else right = mid - 1;
    }
    for(int mid = left-2; ; mid++){
//        printf("%d %d\n", mid, go(mid));
        if(!go(mid)) {printf("%d", mid-1); break;}
    }
    return 0;
}