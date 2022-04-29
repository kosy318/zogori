#include <stdio.h>
int main(void)
{
int n;
scanf("%d", &n);
n=n-2;
int q= n/2;

if(n>=2){
double re=n%2;
if(re>0) q++;
}


printf("%d\n", q);
return 0;
}
