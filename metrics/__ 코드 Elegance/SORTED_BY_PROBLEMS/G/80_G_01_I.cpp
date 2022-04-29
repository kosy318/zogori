#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, c;
    int bfc = -1;
    int answer = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> c;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(bfc != c)
            answer++;
        bfc = c;
    }
    cout << answer;
    return 0;
}