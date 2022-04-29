#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int start;
    int to;
}Line;

int n;
Line arr[100005];
int startDot[100005];
bool comp(const Line &a, const Line &b)
{
return a.start < b.start;
}
int main()
{
    scanf("%d", &n);
    for(register int i =0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].to);
    }
    sort(arr, arr+n, comp);
    int val = (arr[0].start + arr[n-1].start + arr[n-1].to) / (n-1);
    startDot[0] = arr[0].start;
    for(register int i = 0; i < n-1; i++) {
        if(arr[i+1].start - startDot[i] >= val) {
            startDot[i+1] = arr[i+1].start;
        }
        else if(startDot[i] + val <= arr[i+1].start + arr[i+1].to){
            startDot[i+1] = startDot[i] + val;
        }
        else {
            val = arr[i+1].start + arr[i+1].to - startDot[i];
            startDot[i+1] = arr[i+1].start + arr[i+1].to;
        }
    }
    printf("%d\n", val);
    return 0;
}
