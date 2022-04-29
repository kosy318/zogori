#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 15000
using namespace std;

class cls{
public:
    int start, end, value;
};

bool operator < (cls a, cls b){
    return a.value < b.value ? false : true;
}
int m,n;
vector<cls> vec;
int arr[101] = {0};
int total[SIZE] = {0};
void input(){
    scanf("%d %d ", &m, &n);
    for(int i = 1; i<=m; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i<n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cls temp;
        temp.start = a;
        temp.end = b;
        temp.value = (b - a) * arr[c];
        vec.push_back(temp);
    }
}
bool check(cls temp){
    for(int i = temp.start; i<temp.end; i++){
        if(total[i])
            return false;
    }
    return true;
}

void fill(cls temp){
    for(int i = temp.start; i <=temp.end; i++)
        total[i] = 1;
}

void solve(){
    sort(vec.begin(), vec.end());
    int sum = 0;
    for(int i = 0; i<n; i++){
        cls temp = vec[i];
        if(!check(temp))
            continue;
        fill(temp);
        sum += temp.value;
        cout<<temp.start<<" "<<temp.end<<" "<<temp.value<<endl;
    }
    cout<<sum;
}

int main(void){
    input();
    solve();
}