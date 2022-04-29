#include <iostream>
#include <algorithm>
#include <vector>
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
int n1,n2,c1,c2;
int s,b;
vector<node> info;
int main()
{
    ans = 0;
    cin >> n1;
    for(int i = 1; i <= n1; i++)
    {
        ll x,y;
        cin >> x >> y;
        info.push_back(node(x,y,1));
    }
    cin >> n2;
    for(int i = 1; i <= n2; i++)
    {
        ll x,y;
        cin >> x >> y;
        info.push_back(node(x,y,2));
    }
    cin >> c1 >> c2;
    sort(info.begin(),info.end());


    for(int i = 0; i < info.size(); i++)
    {
        s = 0;
        b = 0;
        for(int j = i; j < info.size(); j++)
        {
            if(info[j].color == 1) s++;
            else b++;
            ll eval = c1 * s - c2 * b;

            ans = max(ans, eval);
        }
    }

    cout  << ans;
    return 0;
}
