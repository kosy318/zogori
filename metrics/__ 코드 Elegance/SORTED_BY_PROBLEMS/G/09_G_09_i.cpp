#include <iostream>
// #include <algorithm>

// #pragma warning(disable: 4996)

using namespace std;


int main()
{
    int m, n, i;
    int result = 0;
    int point[100000];
    int color[100000];
    int index[100000];

    cin >> m >> n;

    for(i=0;i<n;i++)
        cin >> point[i];
    for(i=0;i<n;i++)
        cin >> color[i];

    if(color[0] != color[1])
        result++;
    index[0] = 1;

    for(i=1;i<n-1;i++)
    {
        if((point[i] - point[i-1]) > (point[i+1] - point[i]))
        {
            index[i] = i+1;
            if (color[i] != color[i+1])
                result++;
        }
        else if((point[i]-point[i-1]) == (point[i+1] - point[i]))
        {
            int count = 0;
            if (color[i] != color[i-1])
            {
                result++;
                continue;
            }
            while(1)
            {
                if (color[i] != color[i-1])
                    break;
                if (point[i] - point[i-1] == point[i+1] - point[i])
                    count++;
                if(count%2==0)
                    result++;
                i++;
            }
        }
        else
        {
            index[i] = i-1;
            if (color[i] != color[i-1])
                result++;
            else if (index[i-1] == i)
                result++;
        }
    }
    if(color[n-2] != color[n-1])
        result++;
    cout << result << endl;
    return 0;
}
