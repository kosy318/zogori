/*#include <iostream>
#include <algorithm>

using namespace std;

class Data
{
public:
    int start, last, type;
    void setData(int start, int last, int type)
    {
        this->start = start;
        this->last = last;
        this->type = type;
    }
    bool operator<(const Data & cmp)
    {
        if (last == cmp.last && start == cmp.start) return type > cmp.type;
        if (last == cmp.last) return start < cmp.start;
        else last < cmp.last;
    }

    void showData()
    {
        cout << start << last << type << '\n';
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

    sort(mine, mine + n);

    for (int i=1; i<=n; i++) mine[i].showData();

    cout << result;

    return 0;
}
*/

#include <cstdio>

using namespace std;

int main(){
    int n;
    int tmp,ans;
    scanf("%d",&n);
    if(n==3)printf("0");
    else if(n==4)printf("1");
    else
        {
            if(n%2==0){
                tmp=n-2;
                ans=tmp-2;
            }
            else{
                tmp=n-2;
                ans=tmp-1;
            }
             printf("%d",ans);
        }
}
