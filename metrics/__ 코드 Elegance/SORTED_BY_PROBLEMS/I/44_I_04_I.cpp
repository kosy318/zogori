#include<cstdio>
#include<algorithm>
using namespace std;
long long i,j,k,l,m,n,first,last,mid,now;
struct node{
    int x,y;
} a[300001];
bool booleen(node const&p,node const&q){
    return p.x<q.x;
}
int main(){
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].y+=a[i].x;
    }
    sort(a+1,a+n+1,booleen);
    first=1;last=1000000000;
    while(first<last){
        mid=(first+last)/2+1;
        bool b=0;
        now=a[1].x;
        for(i=2;i<=n;i++){
            if(now+mid<a[i].x) now=a[i].x;
            else if(now+mid>a[i].y) b=1;
            else now+=mid;
        }
        if(b==0) first=mid;
        else last=mid-1;
    }
    printf("%lld\n",first);
    return 0;
}
