#include<iostream>
#include<cmath>
#include<memory.h>
#include<algorithm>
using namespace std;
int arr[1001];
int main()
{
    int n;
    cin >> n;
    arr[0]=arr[1]=1;
    for(int i=2; i<=n; i++)
    {
        int check[3001];
        memset(check,false,sizeof(check));
        for(int k=1; k<=500; k++)
        {
            if(i-2*k<0)
                break;
            int temp = arr[i-k] -arr[i-2*k];
            //cout << "!" << temp << '\n';
            if(arr[i-k]+temp>=1)
                check[arr[i-k]+temp]=true;
        }
        for(int k=1; k<=2001; k++)
            if(!check[k])
            {
                arr[i]=k;
                break;
            }
    }
    cout << arr[n] << '\n';
    return 0;
}