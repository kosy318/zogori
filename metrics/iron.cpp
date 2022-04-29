#include <iostream>
// #include <algorithm>

// #pragma warning(disable: 4996)

using namespace std;

/*
#include <iostream>
#include <algorithm>
using namespace std;

int cost[101], dp[10001][15001];
pair<int, int> se[10001];
int M, N, s, e, t, max_time, ms, me;

int Max(int x, int y){
    return x>y?x:y;
}

int main(){
    cin>>M>>N;
    for(int i=1; i<=M; i++){
        cin>>cost[i];
    }

    for(int i=1; i<=N; i++){
        cin>>se[i].second>>se[i].first>>t;
    }
    sort(se+1, se+1+N);

    for(int i=1; i<=N; i++){
        for(int j=1; j<se[i].first; j++){
            if(se[i].second>j) dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=dp[i-1][j];
                for(int k=1; k<i; k++){
                    if(se[k].first<=se[i].second){
                        dp[i][j]=Max(dp[i][j], dp[k][se[k].first - 1] + (j-se[i].second+1)*cost[t]);
                        if(se[i].second==7) cout<<dp[i][j]<<'\n';
                    }
                }
                dp[i][j]=Max(dp[i][j], (j-se[i].second+1)*cost[t]);
            }
            max_time=Max(max_time, dp[i][j]);
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<max_time<<'\n';

    return 0;
}*/

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
