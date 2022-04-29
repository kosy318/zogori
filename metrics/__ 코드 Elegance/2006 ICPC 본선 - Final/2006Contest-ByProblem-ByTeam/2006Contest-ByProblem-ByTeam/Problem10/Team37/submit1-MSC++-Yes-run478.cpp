#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,m;
int data[5010];

int cnt;

void input()
{
	scanf("%d %d",&n,&m);
	int q;
	for(q=0;q<n;q++) scanf("%d",&data[q]);
}

int compare(const void *a, const void *b)
{
	int *aa,*bb;
	aa=(int *)a;
	bb=(int *)b;
	if(*aa<*bb) return -1;
	if(*aa>*bb) return 1;
	return 0;
}


void process()
{
	qsort(data,n,sizeof(data[0]),compare);

	int q,last,i,result=0,from;
	for(q=0;q<n;q++) {
		from=q;
		cnt=1;
		last=data[q]+m;

		for(i=q+1;i<n;i++) {
			if(data[i]>last) break;


			if(data[i+1]<=last && i+1<n) {
				cnt++;
				from=i;
			}
			else {  // check
				cnt++;
				last=data[i]+m;

				if(i+1<n && data[i+1] > data[from]+m) {
					break;
				}
			}
		}

		if(result<cnt) result=cnt;
	}

	printf("%d\n",result);
}

int main()
{
	int nn,q;
	scanf("%d",&nn);
	for(q=0;q<nn;q++) {
		input();
		process();
	}
	return 0;
}

/*

4
8 5
-4 4 -5 1 7 -3 4 7 
4 5
-5 -4 -3 1
2 10
-1 5
2 3
-1 5

*/