#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;

int n;
int a[MAX+5];
int b[MAX+5];

int main(){
    a[4]=1;
    a[5]=1;
    cin>>n;
    for(int i=6; i<=n; ++i)
    {
        switch((i+1)%2)
        {
            case 0: a[i] = a[(i+1)/2] + 1;
                break;
            case 1: a[i] = a[(i+1)/2+1] + 1;
                break;
        }
    }
    if(n == 3)
        cout << 0;
    else if(n == 4)
        cout << 1;
    else if(n == 5)
        cout << 2;
    else
    {
        /*
       switch(n%3)
        {
            case 0:
                cout << a[(n+3)/3] * 2 + 2;
                break;
            case 1:

                cout << a[(n+3)/3] + a[(n+3)/3+1] + 2;
                break;
            case 2:
                cout << min(a[(n+3)/3+2] + a[(n+3)/3], a[(n+3)/3+1]*2) + 2;
                break;
        }
        */
        int minv = 1000;
        for(int i = 3; 3+n-i*2 >= 3; ++i)
        {
            int i2 = 3+n-i*2;
            if(i > i2)
                minv = min(minv, a[i]*2);
            else
                minv = min(minv, a[i]+a[i2]);
        }
        cout << minv + 2;
    }
    return 0;
}
