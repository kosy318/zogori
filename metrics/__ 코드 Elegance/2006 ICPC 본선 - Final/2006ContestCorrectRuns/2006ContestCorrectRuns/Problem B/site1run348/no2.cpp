#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a,b,c,d[4]={0,};
	int oo=0, pp=0;
	int i,j, cou=0, err = 0;
	int k, p, n,m;
	int bat, q=0,w=0,e=0,r=0;
	char sa[50][1000], op;
	char an[1000]={0,};
	char dna[] = "ACGT";
	
	scanf("%d",&bat);
	for(i = 0 ; i < bat ; i++) {
		scanf("%d %d",&a, &b);
		for(j = 0 ; j < a; j ++) {
			scanf("%s",sa[j]);
		}
		for( k = 0 ; k < b; k++) {
//			an[k] = sc[0][k];
			for( p = 0 ; p < a ; p++) {
				if( sa[p][k] == 'A')
					d[0]++;
				else if( sa[p][k] == 'C')
					d[1]++;
				else if( sa[p][k] == 'G')
					d[2]++;
				else
					d[3]++;
			}
//			printf("%d %d %d %d\n", d[0], d[1], d[2], d[3]);
			for( n = 0 ; n < 4 ; n++) {
				for( m = n ; m < 4 ; m++) {
					if( d[n] < d[m] ) {
						oo = d[m];
						d[m] = d[n];
						d[n] = oo;
						op = dna[m];
						dna[m] = dna[n];
						dna[n] = op;
					}
				}
			}
			an[cou] = dna[0];
			err += d[1]+d[2]+d[3];
			cou++;
//			printf("%s\n",dna);
			d[0] = 0;
			d[1] = 0;
			d[2] = 0;
			d[3] = 0;
			strcpy(dna,"ACGT");
		}
		cou = 0;
		for( n = 0 ; n < b ; n++) {
			printf("%c",an[n]);
		}
		printf("\n%d\n",err);
		err=0;
		
	}


}
		
			
