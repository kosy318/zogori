/*#include <iostream>
#include <algorithm>

using namespace std;

class Data
{
public:
    int start, last, cost;
    void setData(int start, int last, int cost)
    {
        this->start = start;
        this->last = last;
        this->cost = cost;
    }
    bool operator<(const Data & cmp)
    {
        if (cost == cmp.cost) last < cmp.last;
        return cost > cmp.cost;
    }
    void showdata()
    {
        cout << start << last << cost << endl;
    }
};

int m, n;
int price[101];
Data mine[10001];
int actime[25];
int result, tmp;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> m >> n;

    for (int i=1; i<=m; i++) cin >> price[i];

    int start, last, type;
    for (int i=1; i<=n; i++)
    {
        cin >> start >> last >> type;
        int val = price[type] * (last - start);
        mine[i].setData(start, last, val);
    }


    sort(mine + 1, mine + n + 1);

    for (int i=1; i<=n; i++) mine[i].showdata();

    int cnt = 0;
    int stime = mine[1].start, etime = mine[1].last;

    for (int j=mine[1].start; j<=mine[1].last; j++) actime[j] = mine[1].cost;
    result = mine[1].cost;

    for (int i=2; i<=n; i++)
    {
        if (mine[i].last <= stime)
        {
            for (int j=mine[i].start; j<=mine[i].last; j++) actime[j] = mine[i].cost;
            result += mine[i].cost;
            stime = mine[i].start;
        }
        else if (mine[i].start >= etime)
        {
            for (int j=mine[i].start; j<=mine[i].last; j++) actime[j] = mine[i].cost;
            result += mine[i].cost;
            etime = mine[i].last;
        }
    }

    cout << result;

    return 0;
}

*/

#include <cstdio>

using namespace std;
int cnt[1000000];
int n;
int ans;
bool ope(int x,int y){
    return ans = x>y?
}
typedef struct sch{
    int x,y;
    int e;
}SCH;
SCH gene[1000000];
int main(){
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
        if()
    }
}
