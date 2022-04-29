// 2:12 PM

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
//vector<int> a;
int a[10000];
int n,K;
int cnt[10000];


bool possible(int p1, int p2)
{
	if(a[p2] <= a[p1]+K &&  a[p1] <= a[p2]+K)
		return true;
	return false;
}

int main(void)
{
	int ct, t, i;

	//freopen("j.in","r",stdin);

	scanf("%d",&t);
	for(ct=0; ct<t; ct++)
	{
		scanf("%d %d",&n,&K);
		for(i=0; i<n; i++)
		{
			int pi;
			scanf("%d",&pi);
			//a.push_back(pi);
			a[i] = pi;
		}
		sort(&a[0],&a[n]);//a.begin(), a.end());
		int p1, p2, k;
		int fail=0;
		int result = 0;
		cnt[0]=0;
		p1 = p2 = 0;
		k = 1;
		while(p1<n && p2<n && k <n)
		{
			if(p1 <= p2)
			{
				if(possible(p1,k))
				{
					cnt[k] = cnt[p1] +1;
					p1 = k++;
					fail=0;
				}
				else
				{
					p1 = p2;
					fail++;
					cnt[p1] = 0;
				}
			}
			else
			{
				if(possible(p2, k))
				{
					cnt[k] = cnt[p2] +1;
					p2 = k++;
					fail=0;
				}
				else
				{
					p2 = p1;
					fail++;
					cnt[p2] = 0;
				}
			}

			if(possible(p1, p2) && result < cnt[p1] + cnt[p2] + 1)
			{
				result = cnt[p1] + cnt[p2] + 1;
			}

			if(fail>=2)
			{
				fail=0;
				p1 = p2 =k;
				k++;
			}
		}

		printf("%d\n",result);
	}
	return 0;
}
