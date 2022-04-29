#include <fstream>
#include <cstring>

using namespace std;

int n, m;
char data[1010][1010];

int count[1010][4];

void input()
{
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++) {
		scanf("%s",data[i]);
	}
	memset(count,0,sizeof(count));
}

void process()
{
	int i,j,sum=0;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(data[i][j]=='A') count[j][0]++;
			else if(data[i][j]=='C') count[j][1]++;
			else if(data[i][j]=='G') count[j][2]++;
			else if(data[i][j]=='T') count[j][3]++;
		}
	}
	
	for(j=0;j<m;j++) {
		if(count[j][0] >= count[j][1] && count[j][0] >= count[j][2] && count[j][0] >= count[j][3]) {
			printf("%c",'A');
			sum+=count[j][1]+count[j][2]+count[j][3];
		}
		else if(count[j][1] >= count[j][2] && count[j][1] >= count[j][3]) {
			printf("%c",'C');
			sum+=count[j][0]+count[j][2]+count[j][3];
		}
		else if(count[j][2] >= count[j][3]) {
			printf("%c",'G');
			sum+=count[j][0]+count[j][1]+count[j][3];
		}
		else {
			printf("%c",'T');
			sum+=count[j][0]+count[j][1]+count[j][2];
		}
	}
	printf("\n%d\n",sum);
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

3
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT

4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA

6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA

*/