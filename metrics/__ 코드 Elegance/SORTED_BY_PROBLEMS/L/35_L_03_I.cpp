#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int type[101];

int answer[15001];

struct abcd{
    int a;
    int b;
    int c;
    bool operator<(const abcd & t){
        if(a == t.a) return b < t.b;
        return a < t.a;
    }
};
abcd ary[10005];
int main(){
    int max = 0;
    int n, m;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m ;i++){
        scanf("%d", &type[i]);
    }
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &ary[i].a, &ary[i].b, &ary[i].c);
        ary[i].c = (ary[i].b - ary[i].a) * type[ary[i].c];
        if(max < b)
            max = b;
    }
    sort(ary, ary+n);
    int t = 0;
    for(int i = 0; i <= max; i++){
        if(i){
            if(answer[i] < answer[i - 1])
                answer[i] = answer[i - 1];
        }
        while(t < n && ary[t].a == i){
            if(answer[ary[t].b] < answer[i] + ary[t].c ){
                answer[ary[t].b] = answer[i] + ary[t].c;
            }
            t++;
        }
    }
    printf("%d", answer[max]);
}
