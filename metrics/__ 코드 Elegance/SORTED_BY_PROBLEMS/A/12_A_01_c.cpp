#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int arr[1001];
int temp[1001];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    arr[0] = arr[1] = 1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<1001;j++)
        temp[j] = 0;
        for(int j=1;i-2*j>=0;j++)
            if(2 * arr[i-j] - arr[i - 2 * j] >= 0)
                temp[2 * arr[i-j] - arr[i - 2 * j]]=1;
        for(int j=1;j<1001;j++)
            if(temp[j] == 0)
            {
                arr[i] = j;
                break;
            }
    }

    cout << arr[n] << endl;

    return 0;
}
