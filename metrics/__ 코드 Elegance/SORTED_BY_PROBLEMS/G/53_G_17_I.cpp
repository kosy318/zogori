#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int num[n];
    int col[n];

    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    for(int i=0; i<n; i++)
        scanf("%d", &col[i]);

    int count = 0;
    int pc = 0;
    int flag = 0;

    if(col[0] != col[1])
    {
        count++;
        flag = 1;
    }
    pc = col[0];

    for(int i=1; i<n-1; i++)
    {
        if(pc != col[i])
            if(flag == 0)
                count++;

        int t;
        if(num[i] - num[i-1] > num[i+1] - num[i])
            t = i+1;
        else
            t = i-1;

        if(col[t] != col[i])
        {
            count++;
            flag = 1;
        }
        else
            flag = 0;

        pc = col[i];
    }

    if(pc != col[n-1])
        if(flag == 0)
            count++;

    if(col[n-2] != col[n-1])
        count++;
    if(count == 0)
        count = 1;
    printf("%d", count);
}
