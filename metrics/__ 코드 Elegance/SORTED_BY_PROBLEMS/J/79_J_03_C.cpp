#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, a[1000001],x=3,odd=2,even=4,i,j;
    a[3]= 0, a[4]=1,a[5]=a[6]=2;
    for(i=7;i<=1000000;)
    {
        if(x%2)
        {
            for(j=0;j<odd;j++, i++)
            {
                if(i>1000000)
                    break;
                a[i]=x;
            }
            odd<<=1;
        } else{
            for(j=0;j<even;j++, i++)
            {
                if(i>1000000)
                    break;
                a[i]=x;
            }
            even<<=1;
        }
        x++;
    }

    cin>>n;
    cout<<a[n];

    return 0;
}