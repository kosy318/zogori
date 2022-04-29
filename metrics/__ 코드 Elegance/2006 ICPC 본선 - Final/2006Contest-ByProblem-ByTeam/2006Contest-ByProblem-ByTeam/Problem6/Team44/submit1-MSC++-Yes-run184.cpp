#include<cstdio>
#include<cstring>

int a[21],b[21];
int n,m;

int main()
{
	int t;
	int i,tt;

	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d%d",&a[i],&b[i]);
		scanf("%d",&m);
		int dp=-1;
		for (tt=1;tt<=101000;tt++) {
			int ch=0;
			for (i=0;i<n;i++)
				if (tt-b[i]<0 || (tt-b[i])%a[i]!=0) {
					ch=1;
					break;
				}
			if (!ch) {
				int sx=0;
				for (i=0;i<n;i++)
					sx+=(tt-b[i])/a[i];
				if (sx==m)
                    if (dp==-1 || tt<dp)
						dp=tt;
			}
		}
		if (dp==-1)
			dp=0;
		printf("%d\n",dp);
	}
	return 0;
}

/*
3
3
1 19 1 19 1 19
3
3
3 5 4 3 1 7
27
3
3 5 4 3 1 7
26
8
2 156 2 2 2 216 4 12 3 24 5 36 1 96 3 6
695

*/