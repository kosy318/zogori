#include <iostream>
using namespace std;

int point[100000];
int color[100000];
int index[100000];


int main()
{
    int m, n, i;
    int result = 0;
    int count = 0;
    int c_count = 1;
    cin >> m >> n;


    for(i=0;i<n;i++)
        cin >> point[i];
    for(i=0;i<n;i++)
    {
        cin >> color[i];
        if (color[i] == color[i-1])
            c_count++;
    }

    if(n==1)
    {
        cout << 1 << endl;
        return 0;
    }


    if(c_count == n)
    {
        cout << c_count/2 << endl;
        return 0;
    }

    if(color[0] != color[1])
        result++;
    index[0] = 1;

    for(i=1;i<n;i++)
    {
        if((point[i] - point[i-1]) > (point[i+1] - point[i]))
        {
            index[i] = i+1;
            if (color[i] != color[i+1])
                result++;
        }
        else if((point[i]-point[i-1]) == (point[i+1] - point[i]))
        {
            count = 0;
            if (color[i] != color[i-1])
            {
                result++;
                continue;
            }
            while(1)
            {
                if (color[i] != color[i-1])
                    break;
                if(count%2==0)
                    result++;
                if (point[i] - point[i-1] == point[i+1] - point[i])
                    count++;
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
    cout << result << endl;
    return 0;
}
