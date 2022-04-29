#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int p[100001];
int q[100001];
int q_pos[100001];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> p[i];
    for(int i=0; i<n; i++)
    {
        cin >> q[i];
        q_pos[q[i]]=i;
    }
    int sl1,sr1,sl2,sr2;
    bool check=false;
    for(int i=0; i<n; i++)
    {
        int l1 = i-1;
        int r1 = i+1;
        if(l1==-1)
            l1=n-1;
        if(r1==n)
            r1=0;

        int l2 = q_pos[p[i]]-1;
        int r2 = q_pos[p[i]]+1;
        if(l2==-1)
            l2=n-1;
        if(r2==n)
            r2=0;
        //cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
        if(p[l1]==q[r2])
        {
            sl1=l1;
            sr1=i;
            sl2=q_pos[p[i]];
            sr2=r2;
            check=true;
            break;
        }else if(p[l1]==q[l2])
        {
            sl1=l1;
            sr1=i;
            sl2=l2;
            sr2=q_pos[p[i]];
            check=true;
            break;
        }else if(p[r1]==q[l2])
        {
            sl1=i;
            sr1=r1;
            sl2=l2;
            sr2=q_pos[p[i]];
            check=true;
            break;
        }else if(p[r1]==q[r2])
        {
            sl1=i;
            sr1=r1;
            sl2=l2;
            sr2=q_pos[p[i]];
            check=true;
            break;
        }
    }
    if(!check)
    {
        cout << -1 << '\n';
        return 0;
    }
    int total = 2;
    ans.push_back(p[sl1]);
    ans.push_back(p[sr1]);
    while(total<n)
    {
        int l1 = sl1-1;
        int r1 = sr1+1;
        int l2 = sl2-1;
        int r2 = sr2+1;
        if(l1==-1)
            l1=n-1;
        if(r1==n)
            r1=0;
        if(l2==-1)
            l2=n-1;
        if(r2==n)
            r2=0;
        //cout << "index : " << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
        //cout << p[l1] << " " << p[r1] << " " << q[l2] << " " << q[r2] << '\n';
        if(p[l1]==q[r2])
        {
            sl1--;
            sr2++;
            ans.push_back(p[l1]);
        }else if(p[l1]==q[l2])
        {
            sl1--;
            sl2--;
            ans.push_back(p[l1]);
        }else if(p[r1]==q[l2])
        {
            sr1++;
            sl2--;
            ans.push_back(p[r1]);
        }else if(p[r1]==q[r2])
        {
            sr1++;
            sr2++;
            ans.push_back(p[r1]);
        } else
            break;
        if(sl1==-1)
            sl1=n-1;
        if(sr1==n)
            sr1=0;
        if(sl2==-1)
            sl2=n-1;
        if(sr2==n)
            sr2=0;
        total++;
    }
    //cout << ans.size() << '\n';
    if(ans.size()==n)
    {
        for(int x : ans)
            cout << x << " ";
        cout << '\n';
    }else
        cout << -1 << '\n';
    return 0;
}