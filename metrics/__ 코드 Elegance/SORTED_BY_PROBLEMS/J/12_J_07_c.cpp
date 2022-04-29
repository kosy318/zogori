#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll arr[1000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int i;

    arr[2] = 4;
    arr[3] = 6;

    for(i=4;i<1000;i++)
    {
        arr[i] = 3 * arr[i-2] - 2 * arr[i-4];
        if(arr[i] < 0)
        break;
    }

    if(n == 3)
        cout << 0 << endl;
    else if(n == 4)
        cout << 1 << endl;
    else if(n == 5 || n == 6)
        cout << 2 << endl;
    else{
        for(int j=2;j<i;j++)
            if(n - 2 <= arr[j])
             {
               cout << j << endl;
               break;
             }

    }

    return 0;
}
