#include <fstream>

using namespace std;

int change(int a, int b, int c)
{
	int sum=0;
	sum+=a*10000;
	sum+=b*100;
	sum+=c;
	return sum;
}

void plus(int *a, int *b, int *c)
{
	(*c)++;
	if(*c==60) {*c=0;(*b)++;}
	if(*b==60) {*b=0;(*a)++;}
	if(*a==24) {*a=0; *b=0; *c=0;}
}


int main()
{
	int n,q,result;
	scanf("%d",&n);
	for(q=0;q<n;q++) {
		int a,b,c,d,e,f;
		result=0;
		scanf("%d:%d:%d %d:%d:%d",&a,&b,&c,&d,&e,&f);
		change(a,b,c);

		while(1) {
			int ret=change(a,b,c);
			if(ret%3==0) {
				result++;
//				printf("%d",ret);
			}
			plus(&a,&b,&c);
			if(a==d && b==e && c==f) break;
		}
		printf("%d\n",result);
	}
	return 0;
}

/*
3
00:59:58 01:01:24
22:47:03 01:03:24
00:00:09 00:03:37

*/