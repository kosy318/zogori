#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> vt[100050];
int check[100050]={0,};

struct abc
{
int a,level,sum;
};

struct abc2
{
int parent,level,sum;
};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        vt[x].push_back(make_pair(y,z));
        vt[y].push_back(make_pair(x,z));
    }

    queue<abc> q;
    vector<int> leaf;
    abc2 table[1000050];
    for(int i=1;i<=n;i++)
    {
        if(vt[i].size()!=1)
        {
            abc x;
            x.a=i;
            x.level=0;
            x.sum=0;
            q.push(x);
            break;
        }
    }
    while(!q.empty())
    {
        abc now=q.front();
        table[now.a].level=now.level;
        table[now.a].sum=now.sum;
        q.pop();
        check[now.a]=1;
        int flag=1;
        for(int i=0;i<vt[now.a].size();i++)
        {
            if(check[vt[now.a][i].first]==0)
            {

                table[vt[now.a][i].first].parent=now.a;
                flag=0;
                abc x;
                x.a=vt[now.a][i].first;
                x.level=now.level+1;
                x.sum=now.sum+vt[now.a][i].second;
                q.push(x);
            }
        }
        if(flag)
        {
            leaf.push_back(now.a);
        }
    }
    long long int answer=0;
    for(int i=0;i<leaf.size();i++)
    {
        for(int j=i+1;j<leaf.size();j++)
        {
            int x=leaf[i];
            int y=leaf[j];
            int il=table[leaf[i]].level;
            int jl=table[leaf[j]].level;
            int ssum=table[x].sum+table[y].sum;
            while(il>=0&&jl>=0)
            {
                if(il>jl)
                {
                    x=table[x].parent;
                    il--;
                }
                else if(il<jl)
                {
                    y=table[y].parent;
                    jl--;
                }
                else
                {
                    if(x==y)
                    {
                        ssum-=(table[x].sum*2);
                        break;
                    }
                    x=table[x].parent;
                    il--;
                }
            }
            answer+=ssum*ssum;
        }
    }
    printf("%lld",answer);
    return 0;
}
