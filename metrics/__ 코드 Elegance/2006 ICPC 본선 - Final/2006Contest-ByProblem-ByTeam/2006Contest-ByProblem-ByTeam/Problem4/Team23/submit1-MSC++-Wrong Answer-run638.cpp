#include <queue>
#include <stdio.h>

using namespace std;

int p[1000][1001];
int c[1000];

queue<int> q;

int main ()
{
	int t;
	int n,m,f;
	int i,j,k;
	int s1,s2;
	int e1,e2;
	int s;

	scanf("%d", &t);
	while (t--)
	{
		int a,b;

		while(!q.empty())
			q.pop();

		scanf("%d %d", &n, &m);
	
		for (i=0; i<n; i++) {
			p[i][0] = 0;
			c[i] = 0;
		}

		for (i=0; i<m; i++) {
			scanf("%d %d", &a, &b);
			a = a - 1; b = b - 1;
			p[a][0]++;
			p[a][p[a][0]] = b;

			p[b][0]++;
			p[b][p[b][0]] = a;
		}

		scanf("%d %d", &s1, &s2);
		scanf("%d %d", &e1, &e2);

		s1--;
		s2--;
		e1--;
		e2--;

		scanf("%d", &f);

		for (i=0; i<f; i++){
			scanf("%d %d", &a, &b);
			a = a - 1; b = b - 1;

			for (j=1; j<=p[a][0];j++)
				if (p[a][j] == b) p[a][j] = -1;

			for (j=1; j<=p[b][0];j++)
				if (p[b][j] == a) p[b][j] = -1;
		}
	
		q.push(s1);
		c[s1] = 1;
		int sw;

		while (1)
		{
			sw = 0;
			s = q.front();
			q.pop();

			for (i=1; i<=p[s][0]; i++)
				if (p[s][i] != -1 && c[p[s][i]] == 0) {
					if (p[s][i] != e1 && p[s][i] != e2) q.push(i);
					
					c[p[s][i]] = 1;
					sw = 1;
				}

			if (q.empty()) break;
			if (c[e1] && c[e2]) break;
		}

		if (c[e1] && c[e2]) {
			for (k=0; k<n; k++){
				while(!q.empty()) q.pop();
		
				for (i=0; i<n; i++) {
					c[i] = 0;

				if (k == s1) {
					q.push(s2);
					c[s2] = 1;
				}else 
					q.push(s1);
					c[s1] = 1;
				}

				while (1)
				{
					sw = 0;
					s = q.front();
					q.pop();

					for (i=1; i<=p[s][0]; i++)
						if (p[s][i] != -1 && c[p[s][i]] == 0 && p[s][i] != k) {
					
						q.push(p[s][i]);
						c[p[s][i]] = 1;
						sw = 1;
					}

					if (q.empty()) break;
					if (c[e1] || c[e2]) break;
				}

				if (q.empty()) break;
			}

			if (q.empty()) printf("NO\n"); else printf("YES\n"); 
		}
		else printf("NO\n");
	}
	return 0;
}