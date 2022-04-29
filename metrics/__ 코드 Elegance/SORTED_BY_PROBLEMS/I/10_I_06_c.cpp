#include<cstdio>
#include<algorithm>
using namespace std;
int n;
pair<int,int> a[100100];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
        a[i].second+=a[i].first;
    }
    sort(a,a+n);
    int left=0;
    int right=1234567890;
    int dap=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int ch=a[0].first;
        int update=0;
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
    printf("%d\n",dap);

}
