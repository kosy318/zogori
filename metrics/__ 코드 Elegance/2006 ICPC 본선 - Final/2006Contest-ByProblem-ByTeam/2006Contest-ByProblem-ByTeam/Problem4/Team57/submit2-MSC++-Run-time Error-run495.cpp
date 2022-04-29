#include <stdio.h>

int t, n, m, f;
int aaa[10000][2], want[5], hate[10000][2], dap[10000],dosi[1002];

int solve()
{
	int i, j, count=0;
	
	for( i=1 ; i<=n  ; i++ ){
		if( dosi[i]%2 == 1 ) count++;
	}
	if( count > 2 ) return 0;
	else return 1;
}


void main()
{
	int i, j, k;
	scanf("%d",&t);
	for( i=0 ; i<t ; i++){
		scanf("%d%d",&n,&m);
		for( j=0 ; j<m ; j++ ){
			scanf("%d%d",&aaa[j][0],&aaa[j][1]);
			dosi[aaa[j][0]]++; dosi[aaa[j][1]]++;
		}
		scanf("%d%d%d%d",&want[0],&want[1],&want[2],&want[3]);
		for( j=0 ; j<4 ; j++ ){
			for( k=j+1 ; k<4 ; k++){
				if( want[j] == want[k] ) dosi[want[j]]--;
			}
		}
		scanf("%d",&f);
		for( j=0 ; j<f ; j++ ){
			scanf("%d%d",&hate[j][0],&hate[j][1]);
			dosi[hate[j][0]]--; dosi[hate[j][1]]--;
		}
		dap[i] = solve();
		for(j =0 ;j<1002 ; j++){
			dosi[j] = 0;
		}
		for( j=0 ; j<10000 ; j++ ){
			hate[j][0] = 0;
			hate[j][1] = 0;
		}

	}

	for( i=0 ; i<t ; i++ ){
		if(dap[i] == 1) printf("YES\n");
		else printf("NO\n");
	}
    
}