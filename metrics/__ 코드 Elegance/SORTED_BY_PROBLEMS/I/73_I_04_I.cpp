#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<long long>> input;
bool compare(vector<long long> &i, vector<long long> &j)
{
    if(i[0]==j[0])return i[1]<j[1];
    return i[0]<j[0];
}
int main(void) {
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    input.resize(n,vector<long long>(2));
    for(int i=0; i<n; i++) {
        long long s,e;
        cin>>s>>e;
        input[i][0]=s;
        input[i][1]=s+e;
    }
    sort(input.begin(),input.end(),compare);
    if(n==2)
    {
        cout<<input[n-1][1] - input[0][0];
        return 0;
    }
    long long e =(input[n-1][1]-input[0][0])/(n-2);
    long long s=0;
    while(s<=e) {
        long long m = (s + e) / 2;
        long long p_x = input[0][0];
        bool check = 0;
        for (int i = 1; i < n; i++) {
            long long x = p_x + m;
            if (x > input[i][1]) {
                check = 1;
                break;
            }
            p_x = max(x, input[i][0]);
        }
        if (check)
            e = m - 1;
        else
            s = m + 1;
    }
    cout<<e;
    return 0;
}