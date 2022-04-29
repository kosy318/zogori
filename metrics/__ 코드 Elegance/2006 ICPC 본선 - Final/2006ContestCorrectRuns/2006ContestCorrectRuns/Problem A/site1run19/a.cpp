#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

struct Time {
	int h,m,s;
	void scan() {
		scanf("%d:%d:%d",&h,&m,&s);
	}
	void inc() {
		s++;
		if(s>=60) s%=60, m++;
		if(m>=60) m%=60, h++;
		if(h>=24) h%=24;
	}
	bool operator==(const Time &t) const {
		return h==t.h && m==t.m && s==t.s;
	}
	int ok() {
		return (h*100*100+m*100+s)%3==0;
	}
};

int main() {
	int ca;
	Time s,t;
	for(scanf("%d",&ca);ca;ca--) {
		s.scan(), t.scan();
		int ans=0;
		while(1) {
			if(s.ok()) ans++;
			if(s==t) break;
			s.inc();
		}
		printf("%d\n",ans);
	}
}

