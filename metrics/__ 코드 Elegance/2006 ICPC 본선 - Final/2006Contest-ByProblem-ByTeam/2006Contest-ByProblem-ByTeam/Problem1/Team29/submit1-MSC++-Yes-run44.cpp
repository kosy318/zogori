#include <iostream>
using namespace std;

struct clock {
	int h;
	int m;
	int s;
};

void inc(clock &t)
{
	if(t.s == 59) {
		t.s = 0;
		if(t.m == 59) {
			t.m = 0;
			if(t.h == 23) {
				t.h = 0;
			} else t.h++;
		} else t.m++;
	} else t.s++;
	return;
}

int ctoi(clock t)
{
	int temp;
	temp = t.h*10000;
	temp += t.m*100;
	temp += t.s;

	return temp;
}

int main()
{
	int n;
	scanf("%d",&n);

	clock f, t;
	int cnt;

	for(int i=0; i<n; i++) {
		scanf("%d:%d:%d %d:%d:%d",&f.h,&f.m,&f.s,&t.h,&t.m,&t.s);

		cnt = 0;

		while(ctoi(f)!= ctoi(t)) {
//			cout << f.h << " " << f.m << " " << f.s << endl;		
			if(ctoi(f)%3 == 0) cnt++;
			inc(f);
		}
		if(ctoi(f)%3 == 0) cnt++;
		
		printf("%d\n",cnt);

	}
	


	return 0;
}