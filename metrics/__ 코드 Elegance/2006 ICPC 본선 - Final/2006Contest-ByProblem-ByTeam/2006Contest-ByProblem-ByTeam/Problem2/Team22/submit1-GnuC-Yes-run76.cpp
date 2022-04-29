#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char str[100][1001];
int main()
{
	int t;
	int m, n;
	int sum;
	int cnt[128];
	int i, j;
	char ch;
	int max1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		for (i = 0; i < m; i++) {
			scanf("%s", str[i]);
		}
		sum = 0;
		for (i = 0; i < n ;i++) {
			memset(cnt, 0, sizeof(cnt));
			max1 = -1;
			for (j = 0; j < m; j++) {
				cnt[str[j][i]]++;
				if (cnt[str[j][i]] > max1) {
					max1 = cnt[str[j][i]];
					ch = str[j][i]; 
				}
				else if (cnt[str[j][i]] == max1) {
					if (ch > str[j][i]) {
						ch = str[j][i];
					}
				}
			}
			printf("%c", ch);
			sum += m - max1;
		}
		printf("\n");
		printf("%d\n", sum);
	}
	return 0;
}
