#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100987654321
using namespace std;
typedef long long ll;
ll ans;
struct node{
    ll x,y,color;
    node(ll x, ll y,ll color){
        this->x = x;
        this->y = y;
        this->color = color;
    }

    bool operator<(node& n)
    {
        if(this->x == n.x){
            return this->y < n.y;
        }
        return this->x < n.x;
    }
};
// eval(R) = c1 * s - c2 * b;
ll coords[2001];
int n1,n2,c1,c2;
int s,b;
vector<node> info_x;


int main()
{
    cout << "hello_world";
}
