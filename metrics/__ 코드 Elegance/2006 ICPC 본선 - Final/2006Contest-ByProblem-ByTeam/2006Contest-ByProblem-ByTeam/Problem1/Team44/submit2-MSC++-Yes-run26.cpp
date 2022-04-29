#include<cstdio>

int ret(int,int,int);

int h,m,s;
int eh,em,es;

int main()
{
	int t;

	scanf("%d",&t);
	while (t--) {
		scanf("%d:%d:%d",&h,&m,&s);
		scanf("%d:%d:%d",&eh,&em,&es);
		int dp=0;
		do {
			int ka=ret(h,m,s);
			if (ka%3==0)
				dp++;
			s++;
			if (s==60) {
				s=0;
				m++;
			}
			if (m==60) {
				m=0;
				h++;
			}
			if (h==24) {
				h=0;
			}
		}while (h!=eh || m!=em || s!=es);
		int ka=ret(h,m,s);
		if (ka%3==0)
			dp++;
		printf("%d\n",dp);
	}
	return 0;
}

int ret(int h,int m,int s)
{
	return h*10000+m*100+s;
}

/*
10
00:59:58 01:01:24
22:47:03 01:03:24
00:00:09 00:03:37

*/