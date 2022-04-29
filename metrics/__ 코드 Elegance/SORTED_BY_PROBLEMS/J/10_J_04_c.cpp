#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
   long long n; scanf("%lld",&n);

   long long tmp = 3;
   int ans = 0;

   while(tmp < n)
   {
       tmp *= 2;
       ans+=2;
   }

   if(tmp > n) tmp /= 2, ans-=2;
   if(n!=tmp)
   {
       if(n-tmp <= tmp/3) ans++;
       else ans+=2;
   }


   printf("%d",ans);
}
