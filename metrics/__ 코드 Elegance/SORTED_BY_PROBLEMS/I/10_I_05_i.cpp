#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
pair<ll,ll> a[100100];
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i].first,&a[i].second);
        a[i].second+=a[i].first;
    }
    sort(a,a+n);
    ll left=0;
    ll right=2234567890;
    ll dap=0;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        ll ch=a[0].first;
        ll update=0;
        for(int i=1;i<n;i++){
            if(ch+mid>a[i].second) {
                update = 1;
            }
            ch=max(ch+mid,a[i].first);
        }
        if(update) {
            right = mid - 1;
        }
        else{
            left=mid+1;
            dap=max(dap,mid);
        }

    }
    printf("%lld\n",dap);

}
