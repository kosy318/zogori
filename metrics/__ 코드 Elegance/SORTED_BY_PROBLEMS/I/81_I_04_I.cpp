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
    long long n, a, b, max_length = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        lines.push_back({a, b});
    }
    a = 0, b = n - 1;
    sort(lines.begin(), lines.end());

    for(int q = 0; q < n - 1; q++) {
        if(is_div(a, b, n - q)) {
            cout << (long long)((lines[b].first + lines[b].second) - lines[a].first) / (n - q - 1);
            return 0;
        }
        else {
            if(lines[a + 1].first - lines[a].first > (lines[b].first + lines[b].second) - (lines[b - 1].first + lines[b - 1].second))
                a++;
            else
                b--;
        }
    }

    return 0;
}