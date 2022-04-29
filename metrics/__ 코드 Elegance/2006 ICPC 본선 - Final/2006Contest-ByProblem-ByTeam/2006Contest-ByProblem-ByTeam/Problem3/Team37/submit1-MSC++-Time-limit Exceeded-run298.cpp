#include <iostream>
#include <cstring>

using namespace std;

long long int w,h,n;
long long int data[1010][2];

long long int low_b[50010];
long long int high_b[50010];
long long int low[50010];
long long int high[50010];

void input()
{
	cin >> w >> h;
	cin >> n;
	long long int q;
	for(q=0;q<n;q++) {
		cin >> data[q][0] >> data[q][1];
	}
}

long long int correct()
{
	long long int min=h,max=0;
	long long int up_left,up_right;
	long long int down_left,down_right;
	long long int j;

	for(j=0;j<w;j++) {
		if(low[j]<min) {
			down_left=j;
			down_right=j;
			min=low[j];
		}
		else if(low[j]==min) {
			down_right=j;
		}

		if(max<high[j]) {
			up_left=j;
			up_right=j;
			max=high[j];
		}
		else if(max==high[j]) {
			up_right=j;
		}
	}

	long long int line=high[0];
	for(j=1;j<up_left;j++) {
		if(high[j]<line) high[j]=line;
		else if(line<high[j]) line=high[j];
	}
	for(j=up_left+1;j<up_right;j++) {
		high[j]=high[up_left];
	}
	line=high[w-1];
	for(j=w-1;j>up_right;j--) {
		if(high[j]<line) high[j]=line;
		else if(line<high[j]) line=high[j];
	}

	line=low[0];
	for(j=1;j<down_left;j++) {
		if(low[j]>line) low[j]=line;
		else if(line>low[j]) line=low[j];
	}
	for(j=down_left+1;j<down_right;j++) {
		low[j]=low[down_left];
	}
	line=low[w-1];
	for(j=w-1;j>down_right;j--) {
		if(low[j]>line) low[j]=line;
		else if(line>low[j]) line=low[j];
	}

	long long int sum=0;
	for(j=0;j<w;j++) {
		if(high[j]-low[j]<0) continue;
		sum+=high[j]-low[j];
	}

	return sum;
}

void process()
{
	long long int q,range1,range2,result=5000000000;
	long long int r1,r2;

	r1=w;
	r2=0;

	range1=h;
	range2=0;

	for(q=0;q<w;q++) {
		low_b[q]=h;
		high_b[q]=0;
	}
	for(q=0;q<n;q++) {
		if(low_b[ data[q][0]-1 ] > data[q][1]-1) low_b[ data[q][0]-1 ] = data[q][1]-1;
		if(low_b[ data[q][0] ] > data[q][1]-1) low_b[ data[q][0] ] = data[q][1]-1;
		if(data[q][1]-1 < range1) range1=data[q][1]-1;

		if(high_b[ data[q][0]-1 ] < data[q][1] + 1) high_b[ data[q][0]-1 ] = data[q][1] + 1;
		if(high_b[ data[q][0] ] < data[q][1] + 1) high_b[ data[q][0] ] = data[q][1] + 1;
		if(range2 < data[q][1]+1) range2=data[q][1]+1;

				
		if(data[q][0]-1 < r1 ) r1=data[q][0]-1;
		if(r2 < data[q][0]+1 ) r2=data[q][0]+1;

	}

	for(q=0;q<w;q++) {
		if(low_b[q]<0) low_b[q]=0;
		if(high_b[q]>h) high_b[q]=h;
	}
	if(range1<0) range1=0;
	if(range2>h) range2=h;
	if(r1<0) r1=0;
	if(r2>w) r2=w;


	long long int i,j;
	for(i=range1;i<range2;i++) {
		memcpy(low,low_b,sizeof(low));
		memcpy(high,high_b,sizeof(high));

		for(j=0;j<w;j++) {
			if(i<low[j]) low[j]=i;
			if(high[j] < i+1) high[j]=i+1;
		}

		long long int ret=correct();
		if(result>ret) result=ret;
	}

	for(i=r1;i<r2;i++) {
		memcpy(low,low_b,sizeof(low));
		memcpy(high,high_b,sizeof(high));

		low[i]=0;
		high[i]=h;

		long long int ret=correct();
		if(result>ret) result=ret;
	}


	cout << result << endl;
}

void output()
{
}

long long int main()
{
	long long int nn,q;
	cin >> nn;
	for(q=0;q<nn;q++) {
		input();
		process();
		output();
	}
	return 0;
}

/*
3
4 4
1
2 2

8 7
6
2 2
3 1
8 3
5 5
4 6
3 4

12 10
15
2 7
3 8
4 6
4 7
5 5
5 7
6 4
6 5
7 3
7 5
8 2
8 3
9 4
9 5
10 3


*/