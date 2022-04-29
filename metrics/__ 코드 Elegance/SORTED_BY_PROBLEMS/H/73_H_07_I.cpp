#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

class Data
{
public:
    long long x,y,t;
};
bool compare(Data &i, Data &j) {
    if(i.x==j.x)return i.y<j.y;
    return i.x<j.x;
}

bool compare2(Data &i, Data &j) {
    if(i.y==j.y)return i.x<j.x;
    return i.y<j.y;
}
Data input[2001];
Data input_x[2001];
Data input_y[2001];
deque<long long> num_y;
deque<long long> num_x;
int main(void)
{
    //freopen("input.txt","r",stdin);
    long long n1, n2;
    cin>>n1;
    for(int i=0; i<n1; i++)
    {
        cin>>input[i].x>>input[i].y;
        input[i].t = 1;
    }
    cin>>n2;
    for(int i=0; i<n2; i++) {
        cin >> input[i + n1].x >> input[i + n1].y;
        input[i + n1].t = 2;
    }
    long long c1,c2;
    cin>>c1>>c2;

    sort(input,input+n1+n2,compare);
    for(int i=0; i<n1+n2; i++)
        input_x[i] = input[i];
    sort(input,input+n1+n2,compare2);
    for(int i=0; i<n1+n2; i++)
        input_y[i]=input[i];

    long long num=0;
    for(int i=0; i<n1+n2; i++) {
        if (input_x[i].t == 2)++num;
        else {
            num_x.push_back(num);
            num = 0;
        }
    }
    num=0;
    for(int i=0; i<n1+n2; i++) {
        if (input_y[i].t == 2)++num;
        else {
            num_y.push_back(num);
            num = 0;
        }
    }

    long long ty=n1+n2-1;
    long long by=0;
    long long tx = n1+n2-1;
    long long bx =0;
    long long ans= c1*n1 - c2*n2;
    while(bx<=tx && by<=ty)
    {
        Data top_y = input_y[ty];
        Data bottom_y = input[by];
        Data top_x = input_x[tx];
        Data bottom_x = input_x[bx];
        if(top_x.t==1 && bottom_x.t==1 && top_y.t==1 && bottom_y.t==1)
        {
            long long num_ty = num_y.back();
            long long num_by = num_y[1];
            long long num_tx = num_x.back();
            long long num_bx = num_x[1];
            long long ma = -1;
            int check=0;
            if(ma<num_ty)
            {
                ma = num_ty;
                check=1;
            }
            if(ma<num_by)
            {
                ma = num_by;
                check=2;
            }
            if(ma<num_tx)
            {
                ma = num_tx;
                check=3;
            }
            if(ma<num_by)
            {
                ma = num_by;
                check=4;
            }
            if(check==1)
            {
                ty-=(num_ty+1) ;
                num_y.pop_back();
            }
            else if(check==2)
            {
                by+=(num_by+1);
                num_y.pop_front();
            }
            else if(check==3)
            {
                tx-=(num_tx+1);
                num_x.pop_back();
            }
            else if(check==4)
            {
                bx+=(num_bx+1);
                num_x.pop_front();
            }
            ans = max(ans, c1*(ty-by+1) - c2*(tx - bx + 1));
            continue;
        }
        if(top_y.t==2)
            ty-=1;
        else if(bottom_y.y==2)
            by+=1;
        else if(top_x.t==2)
            tx-=1;
        else if(bottom_x.t==2)
            bx+=1;
    }
    cout<<ans;
    return 0;
}