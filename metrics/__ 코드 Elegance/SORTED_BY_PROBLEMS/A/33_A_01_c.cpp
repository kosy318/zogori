#include <stdio.h>

using namespace std;
int arr[1005]={1,1},n;

int main(){
	scanf("%d",&n);
	for(int i=2;i<n+1;i++){
		int lefts[1005]={};
		int rights[1005]={};
		for(int k=0;k<i/2;k++){
			lefts[k]=arr[i-2*(k+1)];
			rights[k]=arr[i-(k+1)];
		}
		for(int x=1;;x++){
			int did=1;
			for(int k=0;k<i/2;k++){
				if(x-rights[k]==rights[k]-lefts[k]){
					did=0;
					break;	
				}	
			}
			if(did){
				arr[i]=x; 
				break;
			}
		}
		
	}
	return !printf("%d\n",arr[n]);
	for(int i=0;i<n+1;i++)
		printf("%d\n",arr[i]);
}
