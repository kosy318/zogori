#include<iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n;
int A[MAX][MAX];
int answer[MAX][MAX];
int dis[MAX][MAX];
queue<pair<int, int>> Q;

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a,b,l;
        cin >> a >> b >> l;
        A[a][b] = l;
    }

    for(int i = 1; i <= n; i++)
    {
        Q.push(make_pair(i,0));
        while (1)
        {
            if(Q.empty())break;

            int x = Q.front().first;
            int lenght = Q.front().second;

            for(int j = 1; j <= n; j++)
            {
                if(A[x][j] != 0 && dis[i][j] == 0)
                {
                    Q.push(make_pair(j,A[x][j]));
                    dis[i][j] = lenght + dis[i][j];
                }
            }
            Q.pop();
        }
    }
    int answer = 0;
    for(int i = 1 ;i <= n; i++)
    {
        for(int j = i+1; i <= n;j ++)
        {
            answer += dis[i][j]*dis[i][j];
        }
    }
    cout << answer << endl;
    return 0;
}
