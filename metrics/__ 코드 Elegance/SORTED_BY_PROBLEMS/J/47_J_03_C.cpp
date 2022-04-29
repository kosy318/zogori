#include <iostream>

using namespace std;

int d[1000001];


int go(int n) {
    if(n==3) return 0;
    if(d[n]>0) return d[n];
    if(n%2==1) {
        d[n]=2+go(n/2+1);
    } else {
        d[n] = 2+go(n/2);
    }
    return d[n];
}
int main()
{
    d[4]=1;
    d[5]=2;
    d[6]=2;
    int num;
    cin>>num;
    go(num);

    cout << go(num) << endl;
    return 0;
}
