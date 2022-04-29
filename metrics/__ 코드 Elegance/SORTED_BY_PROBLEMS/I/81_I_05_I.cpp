#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> lines;

bool is_div(long long s_index, long long e_index, long long num) {
    long long jump = (long long)((lines[e_index].first + lines[e_index].second) - lines[s_index].first) / (num - 1);
    long long s = lines[s_index].first + jump;
    for(int i = s_index + 1; i <= e_index - 1; i++) {
        if(lines[i].first <= s && s <= lines[i].first + lines[i].second)
            s += jump;
        else
            return false;
    }
    return true;
}

int main ()
{
    long long n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        lines.push_back({a, b});
    }
    a = 0, b = n - 1;
    sort(lines.begin(), lines.end());
    long long re = 9999999999;
    for(int q = 0; q < n - 2; q++) {
        if(is_div(a, b, n - q)) {
            long long ans = (long long)((lines[b].first + lines[b].second) - lines[a].first) / (n - q - 1);
            if (ans > re)
                cout << re;
            else
                cout << ans;
            return 0;
        }
        else {
            if(lines[a + 1].first - lines[a].first > (lines[b].first + lines[b].second) - (lines[b - 1].first + lines[b - 1].second)) {
                re = lines[a + 1].first - lines[a].first;
                a++;
            }
            else {
                re = (lines[b].first + lines[b].second) - (lines[b - 1].first + lines[b - 1].second);
                b--;
            }
        }
    }
    long long ans = ((lines[b].first + lines[b].second) - lines[a].first);
    if (ans > re)
        cout << re;
    else
        cout << ans;
    return 0;
}