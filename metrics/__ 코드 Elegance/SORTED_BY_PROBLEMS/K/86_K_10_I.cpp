#include <bits/stdc++.h>

#ifdef LOCAL
    #define watch(x) cout<<(#x)<<" is "<<(x)<<'\n'
    #define dashline() cout<<"================\n"
#else
    #define watch(x)
    #define dashline()
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct dat
{int a,b,c;};

int n,k;
int cnt;
dat arr[111];
bool f[111];
double parr1[111];
double sum1=0,sum2=0,sum3=0;
double sum21=0,sum22=0,sum23=0;
double s1,s2,s3;
double s21,s22,s23;
double ans=2e9;
double v1,v2;

void f1()
{
    int i;
    v1=0; v2=0;
    for(i=1;i<=n;i++)
    {
        if (!f[i]) v1+=(parr1[i]=(arr[i].a-s1)*(arr[i].a-s1)+(arr[i].b-s2)*(arr[i].b-s2)+(arr[i].c-s3)*(arr[i].c-s3));
        else v2+=(arr[i].a-s21)*(arr[i].a-s21)+(arr[i].b-s22)*(arr[i].b-s22)+(arr[i].c-s23)*(arr[i].c-s23);
    }
    watch(v1);
    watch(v2);
    watch(v1+v2);
    dashline();
    ans=min(ans,v1+v2);
}

void mv()
{
    int i,id;
    double mx=-2e9;
    for(i=1;i<=n;i++)
    {
        if (!f[i] && mx<parr1[i])
        {
            mx=parr1[i];
            parr1[i]=0;
            id=i;
        }
    }
    f[id]=1;
    watch(id);
    cnt++;
}

void sum()
{
    int i;
    sum1=0; sum2=0; sum3=0;
    sum21=0; sum22=0; sum23=0;
    for(i=1;i<=n;i++)
    {
        if(!f[i])
        {
            sum1+=arr[i].a;
            sum2+=arr[i].b;
            sum3+=arr[i].c;
        }
        else
        {
            sum21+=arr[i].a;
            sum22+=arr[i].b;
            sum23+=arr[i].c;
        }
    }
    if (n-cnt)
    {
        s1=sum1/(n-cnt);
        s2=sum2/(n-cnt);
        s3=sum3/(n-cnt);
    }
    if (cnt)
    {
        s21=sum21/cnt;
        s22=sum22/cnt;
        s23=sum23/cnt;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    #ifdef LOCAL
    freopen("input3.txt","r",stdin);
    #endif // LOCAL

    cin>>n>>k;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    }

    if (k==1)
    {
        sum();
        f1();
        goto fail;

    }
    while(n-cnt)
    {
        sum();
        f1();
        mv();
    }

fail:
    cout.precision(6);
    cout<<fixed;
    cout<<ans;
    return 0;
}
